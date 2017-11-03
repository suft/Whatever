#pragma once

#include "StateMachine.hpp"
#include "SplashState.hpp"

#define WIDTH 1920
#define HEIGHT 1080

class Application {
private:
    StateMachine machine;
    sf::RenderWindow window;
public:
    Application() = default;
    void run();
};