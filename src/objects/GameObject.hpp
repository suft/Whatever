#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "property/PropertyManager.hpp"

class GameObject {
public:
    PropertyManager pm;
public:
    GameObject() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget &rt) = 0;
    virtual sf::FloatRect getBounds() = 0;
};
