#pragma once

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "State.hpp"
#include "PlayState.hpp"
#include "../graphics/Codex.hpp"
#include "../Flags.hpp"


class SplashState: public State {
private:
    sf::Text text;
    sf::Color fill;
    sf::Color outline;
public:
    SplashState(StateMachine &machine, sf::RenderWindow &window, bool replace);

    void pause() override;
    void resume() override;

    void update(float dt) override;
    void render() override;
private:
    void handleEvents(const sf::Event& event);

    void renderText(sf::RenderTarget& rt);
    void renderTextBounds(sf::RenderTarget& rt);
};