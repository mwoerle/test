//
// Created by Manuel Wörle on 18.01.2017.
//
#include <cmath>
#include "Bruch.hpp"
#include <string>

Bruch::Bruch() : numerator(0), denominator(STANDARDDENOM) {}

Bruch::Bruch(long numerator,  long denominator) : numerator(numerator), denominator(denominator) {}

Bruch::Bruch(long numerator) : numerator(numerator), denominator(STANDARDDENOM) {}


Bruch::~Bruch() {}

Bruch Bruch::kuerzeBruch() {
    long tmp = gcd(numerator, denominator);
    numerator /= tmp;
    denominator /= tmp;
    return *this;
}

long gcd( long denomOne,  long denomTwo) {
    if (denomTwo == 0)
        return denomOne;

    else return gcd(denomTwo, denomOne % denomTwo);
}



long lcm( long denomOne,  long denomTwo) {
    return denomOne * denomTwo / gcd(denomOne, denomTwo);
}

/* Operatoren Bruch,Bruch */
Bruch operator+(Bruch const &lhs, Bruch const &rhs) {
    unsigned long lcmDenom = lcm(lhs.getDenominator(), rhs.getDenominator());
    return Bruch(lhs.getNumerator() * (lcmDenom / lhs.getDenominator()) +
                 rhs.getNumerator() * (lcmDenom / rhs.getDenominator()), lcmDenom);
}

Bruch operator-(Bruch const &lhs, Bruch const &rhs) {
    return (lhs + Bruch(-rhs.getNumerator(), rhs.getDenominator()));
}

Bruch operator*(Bruch const &lhs, Bruch const &rhs) {
    return Bruch(lhs.getNumerator() * rhs.getNumerator(), lhs.getDenominator() * rhs.getDenominator());
}

Bruch operator/(Bruch const &lhs, Bruch const &rhs) {
    return Bruch(lhs.getNumerator(), lhs.getDenominator()) * Bruch(rhs.getDenominator(), rhs.getNumerator());
}

/* Operatoren Bruch,long */ 
Bruch operator+(Bruch const &lhs, long const &rhs) {
    return (lhs + Bruch(rhs));
}

Bruch operator-(Bruch const &lhs, long const &rhs) {
    return (lhs - Bruch(rhs));
}

Bruch operator*(Bruch const &lhs, long const &rhs) {
    return (lhs * Bruch(rhs));
}

Bruch operator/(Bruch const &lhs, long const &rhs) {
    return (lhs / Bruch(rhs));
}

/* Operatoren long,Bruch */
Bruch operator+(long const &lhs, Bruch const &rhs) {
    return (Bruch(lhs) + rhs);
}

Bruch operator-(long const &lhs, Bruch const &rhs) {
    return (Bruch(lhs) - rhs);
}

Bruch operator*(long const &lhs, Bruch const &rhs) {
    return (Bruch(lhs) * rhs);
}

Bruch operator/(long const &lhs, Bruch const &rhs) {
    return (Bruch(lhs) / rhs);
}

std::ostream &operator<<(std::ostream &os, Bruch const &fraction) {
    os << fraction.getNumerator() << '/' << fraction.getDenominator();
    return os;
}

std::istream &operator>>(std::istream &inStream, Bruch &fraction) {
    std::string inputData;
    getline(inStream, inputData);
    size_t slashPos = inputData.find(SLASH);
    if (slashPos != std::string::npos) {
        fraction.numerator = std::stol(inputData.substr(0, slashPos));
        fraction.denominator = std::stol(inputData.substr(slashPos + STANDARDDENOM));
    } else {
        fraction.numerator = std::stol(inputData);
        fraction.denominator = STANDARDDENOM;
    }

    return inStream;
}