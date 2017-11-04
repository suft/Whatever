#include "Application.hpp"
#include <iostream>

void Application::run() {
    this->window.create(sf::VideoMode(WIDTH, HEIGHT), "Whatever");
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);
    this->machine.run(std::unique_ptr<SplashState>(new SplashState(this->machine, this->window, true)));

    auto tp = std::chrono::steady_clock::now();
    while (this->machine.isRunning()) {
        const auto new_tp = std::chrono::steady_clock::now();
        float dt = std::chrono::duration<float>(new_tp - tp).count();
        tp = new_tp;
        this->machine.next();
        this->machine.update(dt);
        this->machine.render();
    }
}