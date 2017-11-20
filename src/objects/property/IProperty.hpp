#pragma once

#include <string>
#include <memory>

class IProperty {
public:
    class T {
    private:
        std::string name;
    public:
        explicit T(std::string name) : name(name) {}
        std::string getName() const { return name; };
    };
private:
    T type;
    const std::string id;
public:
    IProperty(std::string type, const std::string id);
    virtual ~IProperty();

    T* getType();
    const std::string getID() const;

    virtual void update() = 0;
    virtual IProperty* clone() = 0;
protected:
    void setType(std::string type);
};
