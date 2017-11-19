#pragma once

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "State.hpp"
#include "PlayState.hpp"
#include "../graphics/Codex.hpp"
#include "../Flags.hpp"
#include "../penner/Fader.hpp"


class SplashState: public State {
private:
    float duration;
    sf::Color background;
    sf::Sprite logo;
    Fader fader;
public:
    SplashState(StateMachine &machine, sf::RenderWindow &window, bool replace);

    void pause() override;
    void resume() override;

    void update(float dt) override;
    void render() override;
private:
    void handleEvents(const sf::Event& event);

    void swapFader();
    void renderLogo(sf::RenderTarget& rt);
};
