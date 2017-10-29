#include "Inner.hpp"

Inner::Inner(float x, float y): Block(x, y) {}
Inner::Inner(const sf::Vector2f& position): Block(position) {}

bool Inner::isCollidable() const {
    return false;
}