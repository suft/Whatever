#pragma once

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../objects/GameObject.hpp"
#include "../objects/block/Outer.hpp"
#include "../objects/Player.hpp"

class Player;

class Handler {
public:
    std::list<std::shared_ptr<GameObject>> objects;
public:
    Handler() = default;

    void update(float dt);
    void render(sf::RenderTarget &rt);

    void loadLevel(const sf::Image& image);
    void addObject(std::shared_ptr<GameObject> object);
    void removeObject(std::shared_ptr<GameObject> object);
};