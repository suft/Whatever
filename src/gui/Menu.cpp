#include "Menu.hpp"

void Menu::update(float dt) {}

void Menu::render(sf::RenderTarget &rt) {}

void Menu::add(std::unique_ptr<Item> item) {}

void Menu::finalize() {}

void Menu::handleEvents(const sf::Event &event) {
    switch (event.type) {
        default:
            break;
    }
}