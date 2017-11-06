#pragma once

#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "State.hpp"

class MenuState : public State {
public:
    MenuState(StateMachine &machine, sf::RenderWindow &window, bool replace);

    void pause() override;
    void resume() override;

    void update(float dt) override;
    void render() override;
private:
    void handleEvents(const sf::Event& event);
};