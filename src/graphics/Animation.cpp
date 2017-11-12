#include "Animation.hpp"

Animation::Animation(std::string name, int x, int y, int width, int height, int length, float hold, bool backwards, bool loop, Callback callback) {
    this->loop = loop;
    this->complete = false;
    this->callback = callback;
    this->backwards = backwards;
    this->length = length;
    this->hold = hold;
    this->time = 0.0f;
    this->texture = Codex::AcquireTexture(name);
    this->current = (backwards) ? length - 1 : 0;
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
        if (this->backwards) this->previous();
        else this->next();
    }
}

void Animation::previous() {
    if (not this->complete) --this->current;
    if (this->current <= 0) {
        if (this->loop) this->current = this->length - 1;
        else {
            this->complete = true;
            this->callback();
        }
    }
}

void Animation::next() {
    if(not this->complete) ++this->current;
    if (this->current >= this->length) {
        if (this->loop) this->current = 0;
        else {
            this->complete = true;
            this->callback();
        }
    }
}

void Animation::reset() {
    if (this->backwards) this->current = this->length - 1;
    else this->current = 0;
    this->complete = false;
}
