#include <iostream>
#include "game/Application.hpp"
#include "objects/property/PropertyManager.hpp"

int main() {
//    Application app;
//    app.run();

    PropertyManager properties;

    // Add a new sf::Clock property
    properties.add<sf::Clock>("AnimationClock", sf::Clock());

    // Add a new sf::Sprite property
    properties.add<sf::Sprite>("Sprite", sf::Sprite());

    // Add a boolean property
    properties.add<bool>("Visible", true);

    // Get the Visible property
    if(properties.get<bool>("Visible") == true)
    {
        // Draw our sprite
//        renderWindow.draw(properties.Get<sf::Sprite>("Sprite"));

        // First retrieve the sf::Clock property
        sf::Clock clock = properties.get<sf::Clock>("AnimationClock");

        // Next reset the Animation Clock
        clock.restart();

        // Then save the results back in the property
        properties.set<sf::Clock>("AnimationClock", clock);
    }

    // See if a property exists
    if(properties.has("NotExist"))
    {
        printf("It exists!\n");
    }
    else
    {
        printf("It doesn't exist\n");
    }

    return EXIT_SUCCESS;
}
