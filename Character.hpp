#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "src/graphics/Animation.hpp"
#include "src/penner/Tween.hpp"
#include "src/penner/Easing.hpp"

class Character {
private:
    enum class AnimationIndex {
        IdleUp, IdleDown, IdleLeft, IdleRight,
        WalkingUp, WalkingDown, WalkingLeft, WalkingRight,
        Count
    };

    sf::Vector2f pos;
    sf::Sprite sprite;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex currentAnimation = AnimationIndex::IdleRight;
    Tween forward;
    Tween backward;

public:
    Character(const std::string name, const sf::Vector2f& pos): pos(pos) {
        sprite.setTextureRect({0, 0, 64, 64});
        forward.setProperties(
            &this->pos.x,
            420,
            1416,
            easing(Function::Sine, Type::InOut),
            10.0f
        );
        backward.setProperties(
            &this->pos.x,
            1416,
            420,
            easing(Function::Sine, Type::InOut),
            10.0f
        );
        animations[int(AnimationIndex::IdleUp)] = Animation(name, 0, 0, 64, 64, 1, 10.1f);
        animations[int(AnimationIndex::IdleDown)] = Animation(name, 0, 128, 64, 64, 1, 10.1f);
        animations[int(AnimationIndex::IdleLeft)] = Animation(name, 0, 64, 64, 64, 1, 10.1f);
        animations[int(AnimationIndex::IdleRight)] = Animation(name, 0, 192, 64, 64, 1, 10.1f);
        animations[int(AnimationIndex::WalkingUp)] = Animation(name, 64, 0, 64, 64, 8, 0.1f);
        animations[int(AnimationIndex::WalkingDown)] = Animation(name, 64, 128, 64, 64, 8, 0.1f);
        animations[int(AnimationIndex::WalkingLeft)] = Animation(name, 64, 64, 64, 64, 8, 0.1f);
        animations[int(AnimationIndex::WalkingRight)] = Animation(name, 64, 192, 64, 64, 8, 0.1f);
    }

    void update(float dt) {
        if (forward.isComplete()) {
            backward.update(dt);
            currentAnimation = AnimationIndex::WalkingLeft;
            if (backward.isComplete()) {
                forward.reset();
                backward.reset();
            }
        } else {
            forward.update(dt);
            currentAnimation = AnimationIndex::WalkingRight;
        }
        animations[int(currentAnimation)].update(dt);
        animations[int(currentAnimation)].applyToSprite(sprite);
        sprite.setPosition(pos);
    }

    void render(sf::RenderTarget& rt) const {
        rt.draw(sprite);
    }
};