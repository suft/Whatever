#pragma once

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <functional>

#include "Codex.hpp"

class Animation {
private:
    typedef std::function<void(void)> Callback;
    std::shared_ptr<sf::Texture> texture;
    std::vector<sf::IntRect> frames;


    bool loop;
    Callback callback;
    bool complete;
    bool backwards;
    int length;
    float hold;
    float time;
    int current;
public:
    Animation() = default;
    Animation(std::string name, int x, int y, int width, int height, int length, float hold, bool backwards, bool loop, Callback callback);

    void applyToSprite(sf::Sprite& s) const;
    void update(float dt);
    void reset();
private:
    void previous();
    void next();
};