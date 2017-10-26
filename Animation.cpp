#include "Animation.hpp"

Animation::Animation(std::string name, int x, int y, int width, int height, int length, float hold) {
    this->length = length;
    this->hold = hold;
    this->texture = Codex::AcquireTexture(name);
    for (int i = 0; i < this->length; ++i) {
        this->frames.push_back({x + i * width, y, width, height});
    }
}

void Animation::applyToSprite(sf::Sprite &s) const {
    s.setTexture(*texture);
    s.setTextureRect(this->frames[this->current]);
}

void Animation::update(float dt) {
    this->time += dt;
    while (this->time >= this->hold) {
        this->time -= this->hold;
        next();
    }
}

void Animation::next() {
    if (++this->current >= this->length) this->current = 0;
}