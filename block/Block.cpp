#include "Block.hpp"

Block::Block(float x, float y): GameObject(x, y) {}

Block::Block(const sf::Vector2f &position): GameObject(position) {}

sf::FloatRect Block::getBounds() {
    return {
        this->position,
        {this->size, this->size}
    };
}

void Block::update(float dt) {}

void Block::render(sf::RenderTarget& rt) {
    sf::RectangleShape bounds;
    bounds.setSize({this->size, this->size});
    bounds.setOutlineThickness(1.0f);
    bounds.setOutlineColor(sf::Color::Cyan);
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setPosition(this->position);
    rt.draw(bounds);
}

