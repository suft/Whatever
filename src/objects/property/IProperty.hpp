#pragma once

#include <string>
#include <memory>

class IProperty {
public:
    class T {
    private:
        std::string name;
    public:
        explicit T(std::string name): name(name) {}
        std::string getName() { return this->name; }
    };
private:
    T type;
    const std::string id;
public:
    IProperty(std::string type, std::string id);

    std::shared_ptr<T> getType();
    const std::string getID() const;

    virtual void update() = 0;
    virtual std::shared_ptr<IProperty> clone() = 0;
protected:
    void setType(std::string type);
};
