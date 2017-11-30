#pragma once

#include <vector>
#include "../GameObject.hpp"
class EntityStateMachine;

class EntityState {
protected:
    std::vector<std::unique_ptr<EntityState>> nextStates;
    EntityStateMachine& entityMachine;
    GameObject& gameObject;
    std::unique_ptr<EntityState> after;
    bool afterFound;
    bool replace;
public:
    virtual std::unique_ptr<EntityState> next() = 0;

    virtual ~EntityState() = default;

    bool isReplacing();

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    std::unique_ptr<EntityState> next();

};