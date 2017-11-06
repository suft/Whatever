#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

class Item {
private:
    bool selected;
public:
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget& rt) = 0;

    bool isSelected();
};