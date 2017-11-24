#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "GameObject.hpp"

class Block : public GameObject {
public:
    Block();
    Block(const sf::Vector2f& position, bool collidable);

    sf::FloatRect getBounds() override;

    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;

    bool isCollidable();
};
