#pragma once

#include "Block.hpp"

class Inner : public Block {
private:
public:
    Inner() = default;
    Inner(float x, float y);
    Inner(const sf::Vector2f& position);

    bool isCollidable() const override;
};