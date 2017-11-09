#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

class Fragment {
private:
    float time;
    bool complete;
public:
    Fragment() = default;

    Fragment(const Fragment&) = delete;
    Fragment& operator=(const Fragment&) = delete;

    virtual void update(float dt);
    virtual void render(sf::RenderTarget& rt);

    bool isComplete();
};