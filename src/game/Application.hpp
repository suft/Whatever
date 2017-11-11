#pragma once

#include "StateMachine.hpp"
#include "SplashState.hpp"
#include "../Flags.hpp"


class Application {
private:
    StateMachine machine;
    sf::RenderWindow window;
public:
    Application() = default;
    void run();
};