#include "MenuState.hpp"

MenuState::MenuState(StateMachine &machine, sf::RenderWindow &window, bool replace) : State(machine, window, replace) {}

void MenuState::pause() {}

void MenuState::resume() {}

void MenuState::update(float dt) {
    sf::Event event;
    while (this->window.pollEvent(event)) handleEvents(event);
}

void MenuState::render() {
    this->window.clear();
    this->window.display();
}

void MenuState::handleEvents(const sf::Event &event) {
    switch (event.type) {
        case sf::Event::Closed:
            this->machine.quit();
            break;
        default:
            break;
    }
}