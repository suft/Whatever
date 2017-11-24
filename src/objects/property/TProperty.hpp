#pragma once

#include "IProperty.hpp"

template<class TYPE = unsigned int>
class TProperty: public IProperty {
private:
    TYPE value;
public:
    TProperty(const std::string id): IProperty(typeid(TYPE).name(), id) {}

    TYPE& getValue() { return this->value; }

    void setValue(TYPE value) { this->value = value; }

    void update() {}

    IProperty* clone() {
        TProperty<TYPE>* property = new (std::nothrow) TProperty<TYPE>(getID());
        if (NULL != property) property->setValue(value);
        return property;
    }
};
