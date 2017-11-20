#pragma once

#include <iostream>
#include <map>
#include <typeinfo>
#include "IProperty.hpp"
#include "TProperty.hpp"

class PropertyManager {
private:
    std::map<const std::string, IProperty*> properties;
public:
    PropertyManager() = default;
    virtual ~PropertyManager();

    bool has(const std::string id);

    template<class TYPE>
    TYPE get(const std::string id) {
        if (this->properties.find(id) != this->properties.end()) {
            if (this->properties.at(id)->getType()->getName() == typeid(TYPE).name()) {
                return static_cast<TProperty<TYPE> *>(this->properties[id])->GetValue();
            }
        }
        TYPE result = TYPE();
        return result;
    }

    template<class TYPE>
    void set(const std::string id, TYPE value) {
        if (this->properties.find(id) != this->properties.end()) {
            if (this->properties.at(id)->getType()->getName() == typeid(TYPE).name()) {
                static_cast<TProperty<TYPE>*>(this->properties[id])->SetValue(value);
            }
        }
    }

    template<class TYPE>
    void add(const std::string id, TYPE value) {
        if (this->properties.find(id) == this->properties.end()) {
            TProperty<TYPE>* property = new (std::nothrow) TProperty<TYPE>(id);
            property->SetValue(value);
            this->properties[property->getID()] = property;
        }
    }

    void add(IProperty *property);
    void clone(const PropertyManager &pm);
};
