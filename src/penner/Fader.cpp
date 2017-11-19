#include "Fader.hpp"
#include "../utils/Misc.hpp"
#include <iostream>

Fader::Fader(Direction direction, float duration, Fader::Update fadeUpdate, Fader::Render fadeRender, Fader::Callback fadeCallback) {
    this->duration = duration;
    this->current = 0.0f;
    this->fadeUpdate = fadeUpdate;
    this->fadeRender = fadeRender;
    this->fadeCallback = fadeCallback;
    this->overlay = sf::RectangleShape(DIMENSIONS);
    this->overlay.setPosition(ORIGIN);
    this->colour = sf::Color();
    this->alpha = 255.0f;
    this->direction = direction;
    this->complete = false;
}

void Fader::update(float dt) {
    if (this->current >= this->duration) {
        this->current = this->duration;
        this->complete = true;
        this->fadeCallback();
    } else {
        std::cout << "Current: " << this->current << std::endl;
        this->current += dt;
        auto percent = getPercentage();
        if (this->direction == Direction::In) this->alpha = clamp((1.0f - percent) * 255.0f, 0.0f, 255.0f);
        else if (this->direction == Direction::Out) this->alpha = clamp(percent * 255.0f, 0.0f, 255.0f);
        this->colour.a = this->alpha;
        this->overlay.setFillColor(this->colour);
        this->fadeUpdate(dt);
    }
}

void Fader::render(sf::RenderTarget &rt) {
    std::cout << "Alpha: " << this->alpha << std::endl;
    std::cout << "Overlay: " << (int) this->overlay.getFillColor().a << std::endl;
    this->fadeRender(rt);
    rt.draw(this->overlay);
}

Direction Fader::getDirection() {
    return this->direction;
}

void Fader::setDirection(Direction direction) {
    this->direction = direction;
}

void Fader::setComplete(bool complete) {
    this->current = 0.0f;
    this->complete = complete;
}

float Fader::getPercentage() {
    return this->current / this->duration;
}

bool Fader::isComplete() {
    return this->complete;
}
