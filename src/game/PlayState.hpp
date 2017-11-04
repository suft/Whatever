#pragma once

#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "State.hpp"
#include "../window/Handler.hpp"
#include "../window/Camera.hpp"
#include "../graphics/Codex.hpp"

class PlayState: public State {
private:
    Handler handler;
    Camera camera;
public:
    PlayState(StateMachine &machine, sf::RenderWindow &window, bool replace);

    void pause() override;
    void resume() override;

    void update(float dt) override;
    void render() override;
private:
    void handleEvents(const sf::Event& event);
};