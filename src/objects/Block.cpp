#include "Block.hpp"

Block::Block(): GameObject() {
    this->pm.add<sf::Vector2f>("Position", sf::Vector2f());
    this->pm.add<bool>("Collidable", false);
    this->pm.add<float>("Size", 32.0f);
}

Block::Block(const sf::Vector2f &position, bool collidable): GameObject() {
    this->pm.add<sf::Vector2f>("Position", position);
    this->pm.add<bool>("Collidable", collidable);
    this->pm.add<float>("Size", 32.0f);
}

sf::FloatRect Block::getBounds() {
    float size = this->pm.get<float>("Size");
    return {
        this->pm.get<sf::Vector2f>("Position"),
        {size, size}
    };
}

void Block::update(float dt) {}

void Block::render(sf::RenderTarget& rt) {
    sf::RectangleShape bounds;
    float size = this->pm.get<float>("Size");
    bounds.setSize({size, size});
    bounds.setOutlineThickness(1.0f);
    bounds.setOutlineColor(sf::Color::Cyan);
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setPosition(this->pm.get<sf::Vector2f>("Position"));
    rt.draw(bounds);
}

bool Block::isCollidable() {
    return this->pm.get<bool>("Collidable");
}

