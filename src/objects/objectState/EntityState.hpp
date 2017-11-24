#pragma once

#include <vector>

class EntityStateMachine;

class EntityState {
protected:
    std::vector<EntityState> nextStates;
    EntityStateMachine &entityMachine;
public:
    std::unique_ptr<EntityState> next();
};