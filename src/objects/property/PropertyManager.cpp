#include "PropertyManager.hpp"

bool PropertyManager::has(const std::string id) const {
    return this->properties.find(id) != this->properties.end();
}

template<class T>
T &PropertyManager::get(const std::string id) {
    if (this->properties.find(id) != this->properties.end()) {
        if (this->properties.at(id)->getType()->getName() == typeid(T).name()) {
            return std::static_pointer_cast<TProperty <T>>(this->properties[id])->getValue();
        }
    }
    T result = T();
    return result;
}

template<class T>
void PropertyManager::set(const std::string id, T value) {
    if (this->properties.find(id) != this->properties.end()) {
        if (this->properties.at(id)->getType()->getName() == typeid(T).name()) {
            std::static_pointer_cast<TProperty <T>>(this->properties[id])->setValue(value);
        }
    }
}

template<class T>
void PropertyManager::add(const std::string id, T value) {
    if (this->properties.find(id) == this->properties.end()) {
        std::shared_ptr<TProperty<T>> property = new(std::nothrow) TProperty<T> (id);
        property->setValue(value);
        this->properties[property->getID()] = property;
    }
}

void PropertyManager::add(std::shared_ptr<IProperty> property) {
    if (this->properties.find(property->getID()) == this->properties.end()) {
        this->properties[property->getID()] = property;
    }
}

void PropertyManager::clone(const PropertyManager &pm) {
    std::map<const std::string, std::shared_ptr<IProperty>>::const_iterator pit;
    for(pit = pm.properties.begin(); pit != pm.properties.end(); ++pit) {
        std::shared_ptr<IProperty> property = (pit->second);
        add(property->clone());
    }
}
