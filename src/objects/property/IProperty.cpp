#include "IProperty.hpp"

IProperty::IProperty(std::string type, const std::string id): type(type), id(id) {}

IProperty::~IProperty() {}

IProperty::T* IProperty::getType() { return &this->type; }

const std::string IProperty::getID() const { return this->id; }

void IProperty::setType(std::string type) { this->type = T(type); }

