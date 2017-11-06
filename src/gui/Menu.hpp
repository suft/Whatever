#pragma once

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "Item.hpp"

class Menu {
private:
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<Item>>::iterator iter;
public:
    Menu() = default;

    void update(float dt);
    void render(sf::RenderTarget& rt);

    void add(std::unique_ptr<Item> item);
    void finalize();
private:
    void handleEvents(const sf::Event& event);
};