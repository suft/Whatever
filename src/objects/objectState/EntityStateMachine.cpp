#include "EntityStateMachine.hpp"

void EntityStateMachine::update(float dt) {
    this->entityStates.top()->update(dt);
}

void EntityStateMachine::render() {
    this->entityStates.top()->render();
}

void EntityStateMachine::next() {

}

bool EntityStateMachine::isRunning() const {
    return running;
}

void EntityStateMachine::run(std::unique_ptr<EntityState> entityState) {
    this->running = true;
    this->entityStates.push(std::move(entityState));
}
