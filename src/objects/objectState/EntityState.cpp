#include "EntityState.hpp"


bool EntityState::isReplacing() {
    return this->replace;
}

std::unique_ptr<EntityState> EntityState::next() {
    return std::move(this->after);
}



