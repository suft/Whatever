#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    sf::Vector2f velocity = {0.0f, 0.0f};
    int direction = 1;
    bool jumping = false;
    bool falling = true;
public:
    GameObject() = default;

    inline GameObject(float x, float y) {
        this->position = sf::Vector2f(x, y);
    }

    inline GameObject(const sf::Vector2f& position) {
        this->position = position;
    }

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget &rt) = 0;
    virtual sf::FloatRect getBounds() = 0;

    inline sf::Vector2f &getPosition() { return this->position; }
    inline void setPosition(const sf::Vector2f& position) { this->position = position; }
    inline void setPosition(float x, float y) { this->position = sf::Vector2f(x, y); }

    inline float &getPositionX() { return this->position.x; }
    inline void setPositionX(float x) { this->position.x = x; }

    inline float &getPositionY() { return this->position.y; }
    inline void setPositionY(float y) { this->position.y = y; }

    inline sf::Vector2f &getVelocity() { return this->velocity; }
    inline void setVelocity(const sf::Vector2f& velocity) { this->velocity = velocity; }
    inline void setVelocity(float x, float y) { this->velocity = sf::Vector2f(x, y); }

    inline float &getVelocityX() { return this->velocity.x; }
    inline void setVelocityX(float x) { this->velocity.x = x; }

    inline float &getVelocityY() { return this->velocity.y; }
    inline void setVelocityY(float y) { this->velocity.y = y; }
};