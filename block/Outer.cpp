#include "Outer.hpp"

Outer::Outer(float x, float y): Block(x, y) {}
Outer::Outer(const sf::Vector2f& position): Block(position) {}

bool Outer::isCollidable() const {
    return true;
}