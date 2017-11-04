#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

class StateMachine {
private:
    std::stack<std::unique_ptr<State>> states;
    bool resume;
    bool running;
public:
    StateMachine();

    bool isRunning();
    void quit();

    void run(std::unique_ptr<State> state);

    void update(float dt);
    void render();

    void next();
    void last();
};