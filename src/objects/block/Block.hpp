#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../GameObject.hpp"

class Block : public GameObject {
private:
    const float size = 32.0f;
    bool collidable;
public:
    Block() = default;
    Block(const sf::Vector2f& position, bool collidable);
    Block(float x, float y, bool collidable);

    sf::FloatRect getBounds() override;

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    bool isCollidable() const;
};