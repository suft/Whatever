#pragma once

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "State.hpp"
#include "../graphics/Codex.hpp"

#define WIDTH 1920
#define HEIGHT 1080

class SplashState: public State {
private:
    sf::Text text;
    sf::Color fill;
    sf::Color outline;
public:
    SplashState(StateMachine &machine, sf::RenderWindow &window, bool replace);

    void pause();
    void resume();

    void update();
    void render();
private:
    void handleEvents(const sf::Event& event);
};