#pragma once

#include <string>
#include <memory>
#include <map>
#include "IProperty.hpp"
#include "TProperty.hpp"

class PropertyManager {
private:
    std::map<const std::string, std::shared_ptr<IProperty>> properties;
public:
    PropertyManager() = default;

    bool has(const std::string id) const;

    template<class T>
    T& get(const std::string id);

    template<class T>
    void set(const std::string id, T value);

    template<class T>
    void add(const std::string id, T value);

    void add(std::shared_ptr<IProperty> property);
    void clone(const PropertyManager& pm);

};
