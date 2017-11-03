#include "State.hpp"


State::State(StateMachine& machine, sf::RenderWindow &window, bool replace): machine(machine), window(window), replace(replace) {}

bool State::isReplacing() {
    return this->replace;
}

std::unique_ptr<State> State::next() {
    return std::move(this->after);
}