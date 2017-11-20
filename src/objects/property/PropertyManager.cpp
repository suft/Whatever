#include "PropertyManager.hpp"

PropertyManager::~PropertyManager() {
    std::map<const std::string, IProperty*>::iterator pit;
    for (pit = this->properties.begin(); pit != this->properties.end(); ++pit) {
        IProperty* property = (pit->second);
        delete property;
        property = NULL;
    }
}

bool PropertyManager::has(const std::string id) {
    return (this->properties.find(id) != this->properties.end());
}


void PropertyManager::add(IProperty *property) {
    if (this->properties.find(property->getID()) == this->properties.end()) {
        this->properties[property->getID()] = property;
    }
}

void PropertyManager::clone(const PropertyManager &pm) {
    std::map<const std::string, IProperty*>::const_iterator pit;
    for (pit = pm.properties.begin(); pit != pm.properties.end(); ++pit) {
        IProperty* property = (pit->second);
        add(property->clone());
    }
}
