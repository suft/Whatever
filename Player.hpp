#pragma once

#include <memory>
#include <vector>
#include <SFMl/Graphics.hpp>

#include "GameObject.hpp"
#include "Handler.hpp"
#include "Animation.hpp"

class Handler;

class Player : public GameObject {
private:
    enum class AnimationType {
        IdleRight, IdleLeft,
        WalkRight, WalkLeft,
        RunRight, RunLeft,
        JumpRight, JumpLeft,
        FallRight, FallLeft
    };
    const float width = 48.0f;
    const float height = 96.0f;
    const float gravity = 0.5f;
    const float terminal = 10.0f;
    Handler* handler;

    sf::Sprite sprite;
    std::vector<Animation> animations;
    AnimationType currentAnimation;
public:
    Player() = default;
    Player(float x, float y, Handler* handler);
    Player(const sf::Vector2f& position, Handler* handler);

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    sf::FloatRect getBounds() override;
private:
    void loadAnimations();

    void renderBody(sf::RenderTarget& rt);
    void renderTop(sf::RenderTarget& rt);
    void renderBottom(sf::RenderTarget& rt);
    void renderRight(sf::RenderTarget& rt);
    void renderLeft(sf::RenderTarget& rt);

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