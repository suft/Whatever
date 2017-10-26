#pragma once

#include <memory>
#include <SFMl/Graphics.hpp>

#include "GameObject.hpp"
#include "Handler.hpp"

class Handler;

class Player : public GameObject {
private:
    const float width = 48.0f;
    const float height = 96.0f;
    const float gravity = 0.5f;
    const float terminal = 10.0f;
    Handler* handler;
public:
    Player() = default;
    Player(float x, float y, Handler* handler);
    Player(const sf::Vector2f& position, Handler* handler);

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    sf::FloatRect getBounds() override;


private:
    bool up();
    bool right();
    bool left();
    void input();
    void collision();

    sf::FloatRect getBoundsTop();
    sf::FloatRect getBoundsRight();
    sf::FloatRect getBoundsLeft();
};