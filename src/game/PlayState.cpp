#include "PlayState.hpp"

PlayState::PlayState(StateMachine &machine, sf::RenderWindow &window, bool replace) : State(machine, window, replace) {
    this->handler.loadLevel(*Codex::AcquireImage("Level.png"));
}

void PlayState::pause() {}

void PlayState::resume() {}

void PlayState::update(float dt) {
    sf::Event event;
    while (this->window.pollEvent(event)) handleEvents(event);
    handler.update(dt);
    for (auto o : handler.objects) {
        auto player = std::dynamic_pointer_cast<Player>(o);
        if (player) camera.move(player);
    }
}

void PlayState::render() {
    this->window.clear();
    this->camera.render(this->window);
    this->handler.render(this->window);
    this->window.display();
}

void PlayState::handleEvents(const sf::Event &event) {
    switch (event.type) {
        case sf::Event::Closed:
            this->machine.quit();
            break;
        default:
            break;
    }
}