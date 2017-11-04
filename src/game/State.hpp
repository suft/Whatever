#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class StateMachine;

class State {
protected:
    std::unique_ptr<State> after;
    StateMachine& machine;
    sf::RenderWindow& window;
    bool replace;

public:
    State(StateMachine& machine, sf::RenderWindow& window, bool replace);
    virtual ~State() = default;

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    bool isReplacing();

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    std::unique_ptr<State> next();
};