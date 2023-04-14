#pragma once

#include <iostream>

#include "base/utility.hpp"

enum class Element {
    NONE,
    FIRE,
    WATER,
    GRASS,
};

constexpr int kCounterAttack = 10;

inline std::ostream& operator<<(std::ostream &os, Element element) {
    if(element == Element::FIRE)
        os << "Fire";
    else if(element == Element::GRASS)
        os << "Grass";
    else if(element == Element::WATER)
        os << "WATER";
    else if(element == Element::NONE)
        os << "NONE";
    return os;
}
// Randomly Choose Element
inline Element RngElement() {
    int tmp = NumGen() % 3;
    if(tmp == 0)
        return Element::FIRE;
    else if(tmp == 1)
        return Element::WATER;
    else if(tmp == 2)
        return Element::GRASS;
    return Element::FIRE;
}

// 0 normal
// 1 bonus
// -1 minus
inline int CompareCounter(Element a, Element b) {
    if(a != Element::NONE && b == Element::NONE)
        return 1;
    if(a == Element::NONE && b != Element::NONE)
        return -1;
    if(a == Element::NONE && b == Element::NONE)
        return 0;

    if(a == Element::FIRE) {
        if(b == Element::FIRE)
            return 0;
        else if(b == Element::WATER)
            return -1;
        else if(b == Element::GRASS)
            return 1; 
    } 
    else if(a == Element::WATER) {
        if(b == Element::FIRE)
            return 1;
        else if(b == Element::WATER)
            return 0;
        else if(b == Element::GRASS)
            return -1; 
    }
    else if(a == Element::GRASS) {
        if(b == Element::FIRE)
            return -1;
        else if(b == Element::WATER)
            return 1;
        else if(b == Element::GRASS)
            return 0; 
    }
    return 0;
}
