#include <iostream>
#include <chrono>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Handler.hpp"
#include "Camera.hpp"
#include "Codex.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "The Professor");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Handler handler;
    Camera camera;
    handler.loadLevel(*Codex::AcquireImage("Level.png"));


    auto tp = std::chrono::steady_clock::now();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { if (event.type == sf::Event::Closed) window.close(); }
        float dt;
        {
            const auto new_tp = std::chrono::steady_clock::now();
            dt = std::chrono::duration<float>(new_tp - tp).count();
            tp = new_tp;
        }

        handler.update(dt);
        {
            for (auto o : handler.objects) {
                auto player = std::dynamic_pointer_cast<Player>(o);
                if (player) camera.move(player);
            }
        }
        window.clear();
        camera.render(window);
        handler.render(window);
        window.display();
    }

    return EXIT_SUCCESS;
}