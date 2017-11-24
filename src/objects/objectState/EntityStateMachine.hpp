#pragma once
#include <stack>
#include "EntityState.hpp"
class EntityStateMachine {
private:
    std::stack<std::unique_ptr<EntityState>> entityStates;

public:
};