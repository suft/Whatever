#pragma once

#include "Block.hpp"

class Outer: public Block {
private:
public:
    Outer() = default;
    Outer(float x, float y);
    Outer(const sf::Vector2f& position);

    bool isCollidable() const override;
};