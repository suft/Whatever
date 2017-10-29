#pragma once

#include <iostream>
#include "Easing.hpp"

class Tween {
private:
    float* target;
    float from;
    float to;
    penner ease;
    float time;
    float duration;
    bool complete;
public:
    Tween() = default;
    inline Tween(float* target) {
        this->target = target;
    }

    inline Tween(float* target, penner ease) {
        this->target = target;
        this->ease = ease;
    }

    inline void setProperties(float from, float to, float duration) {
        this->from = from;
        this->to = to;
        this->time = 0;
        this->duration = duration;
        this->complete = false;
    }

    inline void setProperties(float from, float to, penner ease, float duration) {
        this->from = from;
        this->to = to;
        this->ease = ease;
        this->time = 0;
        this->duration = duration;
        this->complete = false;
    }

    inline void setProperties(float* target, float from, float to, penner ease, float duration) {
        this->target = target;
        this->from = from;
        this->to = to;
        this->ease = ease;
        this->time = 0;
        this->duration = duration;
        this->complete = false;
    }

    inline void reset() {
        this->time = 0;
        this->complete = false;
    }

    inline void update(float dt) {
        this->time += dt;
        if (this->time < this->duration) {
            *(this->target) = this->ease(this->time, this->from, this->to - this->from, this->duration);
        } else {
            this->time = this->duration;
            *(this->target) = this->ease(this->time, this->from, this->to - this->from, this->duration);
            this->complete = true;
        }
    }

    inline bool isComplete() const {
        return this->complete;
    }

};