#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

class Camera {
private:
    static constexpr float width = 1920;
    static constexpr float height = 1080;
    sf::Vector2f position;
    sf::View view;
public:
    Camera();

    void render(sf::RenderTarget& rt);
    void move(std::shared_ptr<GameObject> object);

    sf::Vector2f &getPosition();
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    float &getPositionX();
    void setPositionX(float x);

    float &getPositionY();
    void setPositionY(float y);
};