#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../GameObject.hpp"

class Block : public GameObject {
private:
    const float size = 32.0f;
public:
    Block() = default;
    Block(const sf::Vector2f& position);
    Block(float x, float y);

    sf::FloatRect getBounds() override;

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    virtual bool isCollidable() const = 0;
};