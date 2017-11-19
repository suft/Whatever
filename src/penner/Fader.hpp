#pragma once

#include <functional>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Flags.hpp"

enum class Direction {In, Out};

class Fader {
private:
    typedef std::function<void(float)> Update;
    typedef std::function<void(sf::RenderTarget&)> Render;
    typedef std::function<void()> Callback;

    float duration;
    float current;
    float alpha;
    sf::RectangleShape overlay;
    sf::Color colour;
    Direction direction;
    Update fadeUpdate;
    Render fadeRender;
    Callback fadeCallback;

    bool complete;
public:
    Fader() = default;
    Fader(Direction direction, float duration, Update fadeUpdate, Render fadeRender, Callback fadeCallback);

    void update(float dt);
    void render(sf::RenderTarget& rt);

    Direction getDirection();

    void setDirection(Direction direction);
    void setComplete(bool complete);

    bool isComplete();
private:
    float getPercentage();
};