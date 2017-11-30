#pragma once

#include <SFML/Window/Event.hpp>
#include "EntityState.hpp"

class NormalState: public EntityState {
private:

public:
    NormalState(GameObject& gameObject, bool replace);

    void update(float dt) override;
    void render() override;

private:
    void handleEvents(const sf::Event& event);
};