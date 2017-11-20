#pragma once

#include "IProperty.hpp"

template<class T = unsigned int>
class TProperty : public IProperty {
private:
    T value;
public:
    TProperty(const std::string &id) : IProperty(typeid(T).name(), id) {}

    T getValue() { return this->value; }
    void setValue(T value) { this->value = value; }

    void update() {}

    std::shared_ptr<IProperty> clone() {}
};
