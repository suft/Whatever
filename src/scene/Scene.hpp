#pragma once

#include <memory>
#include <stack>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Fragment.hpp"

class Scene {
private:
    std::stack<std::unique_ptr<Fragment>> fragments;
public:
    Scene() = default;

    void update(float dt);
    void render(sf::RenderTarget& rt);

    void add(std::unique_ptr<Fragment> fragment);
};