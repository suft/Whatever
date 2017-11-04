#include "StateMachine.hpp"

StateMachine::StateMachine(): resume(false), running(false) {}

void StateMachine::run(std::unique_ptr<State> state) {
    this->running = true;
    this->states.push(std::move(state));
}

bool StateMachine::isRunning() {
    return this->running;
}

void StateMachine::quit() {
    this->running = false;
}

void StateMachine::next() {
    if (this->resume) {
        if (!this->states.empty()) this->states.pop();
        if (!this->states.empty()) this->states.top()->resume();
        this->resume = false;
    }

    if (!this->states.empty()) {
        std::unique_ptr<State> state = this->states.top()->next();
        if (state) {
            if (state->isReplacing()) this->states.pop();
            else this->states.top()->pause();
            this->states.push(std::move(state));
        }
    }
}

void StateMachine::last() {
    this->resume = true;
}

void StateMachine::update(float dt) {
    this->states.top()->update(dt);
}

void StateMachine::render() {
    this->states.top()->render();
}