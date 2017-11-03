#include "Application.hpp"
#include <memory>

void Application::run() {
    this->window.create(sf::VideoMode(WIDTH, HEIGHT), "Whatever");
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);

    this->machine.run(std::unique_ptr<SplashState>(new SplashState(this->machine, this->window, true)));

    while (this->machine.isRunning()) {
        this->machine.next();
        this->machine.update();
        this->machine.render();
    }
}