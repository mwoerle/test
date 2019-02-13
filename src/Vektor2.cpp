//
// Created by Manu on 21.01.2017.
//

#include <cmath>
#include "Vektor2.hpp"

Vektor::Vektor(Bruch x, Bruch y) {

    vektor.resize(2);
    set(0, x);
    set(1, y);
}
Vektor::~Vektor() {}

Bruch Vektor::at(size_t index) const {
    return vektor.at(index);
}

void Vektor::set(size_t index, Bruch value) {

    vektor.at(index) = value;
}

Bruch &Vektor::at(size_t index) {

    return vektor.at(index);
}


size_t Vektor::size() const {
    return vektor.size();
}

void Vektor::setNull() {

    for (size_t i = 0; i < size(); ++i) {
        set(i, 0);

    }
}

void Vektor::print(std::ostream &out) const {

    out << "( ";
    for (size_t i = 0; i < size(); ++i) {
        out << at(i) << " ";
    }
    out << ")" << std::endl;
}


Vektor add(const Vektor &a, const Vektor &b) {

    Vektor result = a;

    for (size_t i = 0; i < 2; i++) {

        result.set(i, a.at(i) + b.at(i));
    }
    return result;
}

Bruch dot(const Vektor &a, const Vektor &b) {

    Bruch result;

    for (size_t i = 0; i < 2; i++) {
        result = result + (a.at(i) * b.at(i));
    }
    return result;
}
