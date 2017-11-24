#include "Player.hpp"

Player::Player(): GameObject() {
    this->pm.add<float>("Width", 48.0f);
    this->pm.add<float>("Height", 96.0f);
    this->pm.add<float>("Gravity", 0.5f);
    this->pm.add<float>("Terminal", 10.0f);
    this->pm.add<sf::Vector2f>("Position", sf::Vector2f());
    this->pm.add<sf::Vector2f>("Velocity", sf::Vector2f({0, 0}));
    this->pm.add<int>("Direction", 1);
    this->pm.add<sf::Sprite>("Sprite", sf::Sprite());
    this->pm.add<bool>("Falling", true);
    this->pm.add<bool>("Jumping", false);
    this->pm.add<bool>("Attacking", false);
    this->pm.add<AnimationType>("CurrentAnimation", AnimationType::IdleRight);
    this->pm.add<std::vector<Animation>>("Animations", std::vector<Animation>());
}

Player::Player(const sf::Vector2f& position, Handler* handler): GameObject(), handler(handler) {
    this->pm.add<float>("Width", 48.0f);
    this->pm.add<float>("Height", 96.0f);
    this->pm.add<float>("Gravity", 0.5f);
    this->pm.add<float>("Terminal", 10.0f);
    this->pm.add<sf::Vector2f>("Position", sf::Vector2f());
    this->pm.add<sf::Vector2f>("Velocity", sf::Vector2f({0, 0}));
    this->pm.add<int>("Direction", 1);
    this->pm.add<sf::Sprite>("Sprite", sf::Sprite());
    this->pm.add<bool>("Falling", true);
    this->pm.add<bool>("Jumping", false);
    this->pm.add<bool>("Attacking", false);
    this->loadAnimations();
}

void Player::loadAnimations() {
    sf::Sprite& sprite = this->pm.get<sf::Sprite>("Sprite");
    sprite.setTextureRect({0, 0, 32, 64});
    sprite.scale(2.0f, 3.0f);
    this->pm.add<AnimationType>("CurrentAnimation", AnimationType::IdleRight);
    this->pm.add<std::vector<Animation>>("Animations", {
        Animation("IdleRight.png", 0, 0, 24, 32, 11, 0.15f, false, true, [](){}),
        Animation("IdleLeft.png", 0, 0, 24, 32, 11, 0.15f, true, true, [](){}),
        Animation("WalkRight.png", 0, 0, 22, 33, 13, 0.05f, false, true, [](){}),
        Animation("WalkLeft.png", 0, 0, 22, 33, 13, 0.05f, true, true, [](){}),
        Animation("AttackRight.png", 0, 0, 43, 37, 18, 0.05f, false, false, std::bind(&Player::attackComplete, this)),
        Animation("AttackLeft.png", 0, 0, 43, 37, 18, 0.05f, true, false, std::bind(&Player::attackComplete, this)),
        Animation("HitRight.png", 0, 0, 30, 32, 8, 0.1f, false, true, [](){}),
        Animation("HitLeft.png", 0, 0, 30, 32, 8, 0.1f, true, true, [](){}),
        Animation("ReactRight.png", 0, 0, 22, 32, 4, 0.1f, false, true, [](){}),
        Animation("ReactLeft.png", 0, 0, 22, 32, 4, 0.1f, true, true, [](){}),
        Animation("DeadRight.png", 0, 0, 33, 32, 15, 0.1f, false, true, [](){}),
        Animation("DeadLeft.png", 0, 0, 33, 32, 15, 0.1f, true, true, [](){}),
    });
}

void Player::collision() {
    for (auto object : this->handler->objects) {
        auto block = std::dynamic_pointer_cast<Block>(object);
        if (block and block->isCollidable()) {

            float y = block->pm.get<sf::Vector2f>("Position").y;
            float x = block->pm.get<sf::Vector2f>("Position").x;
            float height = this->pm.get<float>("Height");
            float width = this->pm.get<float>("Width");
            sf::Vector2f &position = this->pm.get<sf::Vector2f>("Position");
            sf::Vector2f &velocity = this->pm.get<sf::Vector2f>("Velocity");

            if (this->getBoundsTop().intersects(block->getBounds())) {
                position.y = y + height/3;
                velocity.y = 0.0f;
            }

            if (this->getBoundsBottom().intersects(block->getBounds())) {
                position.y = y - height;
                velocity.y = 0.0f;
                this->pm.set<bool>("Falling", false);
                this->pm.set<bool>("Jumping", false);
            } else {
                this->pm.set<bool>("Falling", true);
            }

            if (this->getBoundsRight().intersects(block->getBounds())) {
                position.x = x - width - 2;
            }

            if (this->getBoundsLeft().intersects(block->getBounds())) {
                position.x = x + 36.0f;
            }
        }
    }
}

void Player::update(float dt) {
    this->input();
    sf::Vector2f &position = this->pm.get<sf::Vector2f>("Position");
    sf::Vector2f &velocity = this->pm.get<sf::Vector2f>("Velocity");
    int &direction = this->pm.get<int>("Direction");

    position += velocity;

    if (velocity.x == 0.0f) {
        if (direction < 0) this->pm.set<AnimationType>("CurrentAnimation", AnimationType::IdleLeft);
        else if (direction > 0) this->pm.set<AnimationType>("CurrentAnimation", AnimationType::IdleRight);
    } else if (velocity.x < 0.0f) {
        direction = -1;
        this->pm.set<AnimationType>("CurrentAnimation", AnimationType::WalkLeft);
    } else if (velocity.x > 0.0f) {
        direction = 1;
        this->pm.set<AnimationType>("CurrentAnimation", AnimationType::WalkRight);
    }

    if (this->pm.get<bool>("Attacking")) {
        if (direction < 0) this->pm.set<AnimationType>("CurrentAnimation", AnimationType::AttackLeft);
        else if (direction > 0) this->pm.set<AnimationType>("CurrentAnimation", AnimationType::AttackRight);
    }

    if (this->pm.get<bool>("Falling") || this->pm.get<bool>("Jumping")) {
        velocity.y += this->pm.get<float>("Gravity");
        float terminal = this->pm.get<float>("Terminal");
        if (velocity.y > terminal) velocity.y = terminal;
    }

    this->collision();
    AnimationType currentAnimation = this->pm.get<AnimationType>("CurrentAnimation");
    sf::Sprite& sprite = this->pm.get<sf::Sprite>("Sprite");
    this->pm.get<std::vector<Animation>>("Animations")[static_cast<int>(currentAnimation)].update(dt);
    this->pm.get<std::vector<Animation>>("Animations")[static_cast<int>(currentAnimation)].applyToSprite(sprite);
    if (currentAnimation == AnimationType::AttackRight) {
        sprite.setPosition(position.x, position.y - 20);
    } else if (currentAnimation == AnimationType::AttackLeft) {
        sprite.setPosition(position.x - 30, position.y - 20);
    } else {
        sprite.setPosition(position);
    }
}

void Player::render(sf::RenderTarget& rt) {
    rt.draw(this->pm.get<sf::Sprite>("Sprite"));

    if (DEBUGGING) {
        this->renderBody(rt);
        this->renderTop(rt);
        this->renderBottom(rt);
        this->renderRight(rt);
        this->renderLeft(rt);
    }
}

void Player::renderBody(sf::RenderTarget &rt) {
    sf::RectangleShape body;
    sf::FloatRect bounds = this->getBounds();
    body.setSize({bounds.width, bounds.height});
    body.setOutlineThickness(1.0f);
    body.setOutlineColor(sf::Color::Blue);
    body.setFillColor(sf::Color::Transparent);
    body.setPosition(bounds.left, bounds.top);
    rt.draw(body);
}

void Player::renderTop(sf::RenderTarget &rt) {
    sf::RectangleShape above;
    sf::FloatRect top = this->getBoundsTop();
    above.setSize({top.width, top.height});
    above.setOutlineThickness(1.0f);
    above.setOutlineColor(sf::Color::Red);
    above.setFillColor(sf::Color::Transparent);
    above.setPosition(top.left, top.top);
    rt.draw(above);
}

void Player::renderBottom(sf::RenderTarget &rt) {
    sf::RectangleShape below;
    sf::FloatRect bottom = this->getBoundsBottom();
    below.setSize({bottom.width, bottom.height});
    below.setOutlineThickness(1.0f);
    below.setOutlineColor(sf::Color::Red);
    below.setFillColor(sf::Color::Transparent);
    below.setPosition(bottom.left, bottom.top);
    rt.draw(below);
}

void Player::renderRight(sf::RenderTarget &rt) {
    sf::RectangleShape rightwards;
    sf::FloatRect right = this->getBoundsRight();
    rightwards.setSize({right.width, right.height});
    rightwards.setOutlineThickness(1.0f);
    rightwards.setOutlineColor(sf::Color::Green);
    rightwards.setFillColor(sf::Color::Transparent);
    rightwards.setPosition(right.left, right.top);
    rt.draw(rightwards);
}

void Player::renderLeft(sf::RenderTarget &rt) {
    sf::RectangleShape leftwards;
    sf::FloatRect left = this->getBoundsLeft();
    leftwards.setSize({left.width, left.height});
    leftwards.setOutlineThickness(1.0f);
    leftwards.setOutlineColor(sf::Color::Green);
    leftwards.setFillColor(sf::Color::Transparent);
    leftwards.setPosition(left.left, left.top);
    rt.draw(leftwards);
}

bool Player::attack() {
    return (
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or
        (sf::Joystick::isConnected(0) and sf::Joystick::isButtonPressed(0, sf::Joystick::Y))
    );
}

bool Player::up() {
    return (
        sf::Keyboard::isKeyPressed(sf::Keyboard::W) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or
        (sf::Joystick::isConnected(0) and sf::Joystick::isButtonPressed(0, sf::Joystick::X))
    );
}

bool Player::right() {
    return (
        sf::Keyboard::isKeyPressed(sf::Keyboard::D) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or
        (sf::Joystick::isConnected(0) and sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > 50)
    );
}

bool Player::left() {
    return (
        sf::Keyboard::isKeyPressed(sf::Keyboard::A) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left) or
        (sf::Joystick::isConnected(0) and sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < -50)
    );
}

void Player::input() {
    sf::Vector2f& velocity = this->pm.get<sf::Vector2f>("Velocity");
    if (this->right()) velocity.x = 5.0f;
    else if (this->left()) velocity.x = -5.0f;
    else velocity.x = 0.0f;

    bool& jumping = this->pm.get<bool>("Jumping");
    if (this->up() and not jumping) {
        jumping = true;
        velocity.y = -10.0f;
    }

    if (this->attack()) this->pm.set<bool>("Attacking", true);
}

sf::FloatRect Player::getBounds() {
    sf::Vector2f position = this->pm.get<sf::Vector2f>("Position");
    return {
        position.x,
        position.y,
        this->pm.get<float>("Width"),
        this->pm.get<float>("Height")
    };
}

sf::FloatRect Player::getBoundsTop() {
    sf::Vector2f position = this->pm.get<sf::Vector2f>("Position");
    float width = this->pm.get<float>("Width");
    float height = this->pm.get<float>("Height");
    return {
        position.x + (width/2.0f) - ((width/2.0f)/2.0f),
        position.y,
        width/2.0f,
        height/2.0f
    };
}

sf::FloatRect Player::getBoundsBottom() {
    sf::Vector2f position = this->pm.get<sf::Vector2f>("Position");
    float width = this->pm.get<float>("Width");
    float height = this->pm.get<float>("Height");
    return {
        position.x + (width/2.0f) - ((width/2.0f)/2.0f),
        position.y + (height/2.0f),
        width/2.0f,
        height/2.0f
    };
}

sf::FloatRect Player::getBoundsRight() {
    sf::Vector2f position = this->pm.get<sf::Vector2f>("Position");
    float width = this->pm.get<float>("Width");
    float height = this->pm.get<float>("Height");
    return {
        position.x + width - 5.0f,
        position.y + 5.0f,
        5.0f,
        height -10.0f
    };
}

sf::FloatRect Player::getBoundsLeft() {
    sf::Vector2f position = this->pm.get<sf::Vector2f>("Position");
    float height = this->pm.get<float>("Height");
    return {
        position.x,
        position.y + 5.0f,
        5.0f,
        height - 10.0f
    };
}

void Player::attackComplete() {
    AnimationType currentAnimation = this->pm.get<AnimationType>("CurrentAnimation");
    this->pm.set<bool>("Attacking", false);
    this->pm.get<std::vector<Animation>>("Animations")[static_cast<int>(currentAnimation)].reset();
}
