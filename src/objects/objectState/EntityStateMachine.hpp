#pragma once
#include <stack>
#include "EntityState.hpp"
class EntityStateMachine {
private:
    std::stack<std::unique_ptr<EntityState>> entityStates;
    bool resume;
    bool running;
public:
    EntityStateMachine();

    bool isRunning() const;
    void run(std::unique_ptr<EntityState> entityState);
    void update(float dt);
    void render();
    void next();
};