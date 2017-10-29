#pragma once

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Codex.hpp"

class Animation {
private:
    std::shared_ptr<sf::Texture> texture;
    std::vector<sf::IntRect> frames;

    bool backwards;
    int length;
    float hold;
    float time;
    int current;
public:
    Animation() = default;
    Animation(std::string name, int x, int y, int width, int height, int length, float hold, bool backwards);

    void applyToSprite(sf::Sprite& s) const;
    void update(float dt);
private:
    void previous();
    void next();
};