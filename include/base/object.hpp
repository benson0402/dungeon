#pragma once

#include <string>

#include "base/element.hpp"

class Object {
public:
    Object();
    Object(std::string str);
    Object(std::string str, Element element);
    ~Object() = default;

    void SetName(std::string str);
    void SetElementType(Element a);
    std::string GetName() const;
    Element GetElementType() const;

private:
    std::string name;
    Element element_type;

};