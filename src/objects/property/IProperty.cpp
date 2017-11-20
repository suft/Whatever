#include "IProperty.hpp"

IProperty::IProperty(std::string type, std::string id): type(type), id(id) {}

std::shared_ptr<IProperty::T> IProperty::getType() {
    return std::shared_ptr<IProperty::T>(&this->type);
}

const std::string IProperty::getID() const {
    return this->id;
}

void IProperty::setType(std::string type) {
    this->type = T(type);
}




