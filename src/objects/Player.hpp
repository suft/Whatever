#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>

#include "GameObject.hpp"
#include "../window/Handler.hpp"
#include "../graphics/Animation.hpp"
#include "../Flags.hpp"

class Handler;

class Player : public GameObject {
private:
    enum class AnimationType {
        IdleRight, IdleLeft,
        WalkRight, WalkLeft,
        AttackRight, AttackLeft,
        HitRight, HitLeft,
        ReactRight, ReactLeft,
        DeadRight, DeadLeft

    };

    Handler* handler;
public:
    Player();
    Player(const sf::Vector2f& position, Handler* handler);

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    sf::FloatRect getBounds() override;
private:
    void loadAnimations();
    void attackComplete();
    void renderBody(sf::RenderTarget& rt);
    void renderTop(sf::RenderTarget& rt);
    void renderBottom(sf::RenderTarget& rt);
    void renderRight(sf::RenderTarget& rt);
    void renderLeft(sf::RenderTarget& rt);

    bool attack();
    bool up();
    bool right();
    bool left();
    void input();
    void collision();

    sf::FloatRect getBoundsTop();
    sf::FloatRect getBoundsBottom();
    sf::FloatRect getBoundsRight();
    sf::FloatRect getBoundsLeft();
};
