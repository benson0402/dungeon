#include "base/object.hpp"

#include <random>

Object::Object():
    name(""), element_type(Element::NONE) {}

Object::Object(std::string str):
    name(str), element_type(Element::NONE) {}

Object::Object(std::string str, Element element):
    name(str), element_type(element) {}

void Object::SetName(std::string str) {
    this->name = str;
}

void Object::SetElementType(Element a) {
    this->element_type = a;
}

std::string Object::GetName() const {
    return this->name;
}

Element Object::GetElementType() const {
    return this->element_type;
}

