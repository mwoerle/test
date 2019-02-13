//
// Created by Manuel Wörle on 18.01.2017.
//

#pragma once
#include <iostream>
#include <sstream>

std::string const SLASH("/");

int const STANDARDDENOM = 1;

/**
 * Klasse zur Bruchrechnung
 */
class Bruch {

public:

    /**
     * Default Konstruktor der einen Bruch "0/1" erzeugt
     */
    Bruch();

    /**
     * Konstruktor der einen Bruch "Zähler/1" erzeug
     * @param numerator Zähler
     */
    Bruch(long numerator);

    /**
    * Konstruktor der einen Bruch "Zähler/Nenner" erzeugt
    * @param numerator Zähler
    * @param denominator Nenner
    */
    Bruch(long numerator,  long denominator);

    /**
     * Bereitstellung des Zählers aus dem privat Bereich
     * @return Zähler
     */
    long getNumerator() const { return numerator; }

    /**
    * Bereitstellung des Nenners aus dem privat Bereich
    * @return Nenner
    */
     long getDenominator() const { return denominator; }

    /**
     * Kürzt einen Bruch soweit wie möglich
     * @return gekürzter Bruch
     */
    Bruch kuerzeBruch();

    /**
     * Destruktor der Bruchklasse
     */
    virtual ~ Bruch();

    /**
     * Ausgabe eines Bruchs in der Form Zähler/Nenner
     * @param os Referenz auf Ausgabestream
     * @param bruch Referenz auf auszugebenden Bruch
     * @return Bruch mit Bruchformatierung
     */
    friend std::ostream &operator<<(std::ostream &os, Bruch const &fraction);

    /**
     * Umwandlung von zwei eingegebenen int Zahlen in einen Bruch
     * @param inStream
     * @param bruch
     * @return
     */
    friend std::istream &operator>>(std::istream &inStream, Bruch &fraction);

private:

    //Deklaration von Zähler und Nenner
    long numerator;
    unsigned long denominator;

};

/**
 * Berechnung des größten gemeinsamen Teilers
 * greatest common devisor (gcd)
 * @param denomOne Nenner des ersten Bruchs
 * @param denomTwo Nenner des zweiten Bruchs
 * @return greatest common devisor
 */
long gcd(long denomOne,long denomTwo);

/**
 * Berechnung des kleinsten gemeinsamen Vielfachen
 * least common multiplyer(lcm)
 * @param denomOne Nenner des ersten Bruchs
 * @param denomTwo Nenner des zweiten Bruchs
 * @return least common multiplyer
 */
 long lcm( long denomOne,  long denomTwo);

/**
 * Überladung der Operatoren +,-,*,/ zur Berechnung von zwei Brüchen und Rückgabe des Ergebnises als Bruch
 * @param lhs linker Bruch
 * @param rhs rechter Bruch
 * @return Ergebnis der Operation
 */
Bruch operator+(Bruch const &lhs, Bruch const &rhs);

Bruch operator-(Bruch const &lhs, Bruch const &rhs);

Bruch operator*(Bruch const &lhs, Bruch const &rhs);

Bruch operator/(Bruch const &lhs, Bruch const &rhs);

/**
 * Überladung der Operatoren +,-,*,/ zur Berechnung eines Bruches und einer long int  und Rückgabe des Ergebnises als Bruch
 * @param lhs Bruch
 * @param rhs long int
 * @return Ergebnis der Operation
 */
Bruch operator+(Bruch const &lhs, long const &rhs);

Bruch operator-(Bruch const &lhs, long const &rhs);

Bruch operator*(Bruch const &lhs, long const &rhs);

Bruch operator/(Bruch const &lhs, long const &rhs);

/**
 * Überladung der Operatoren +,-,*,/ zur Berechnung von long int und eines Bruchs und Rückgabe des Ergebnises als Bruch
 * @param lhs long int
 * @param rhs Bruch
 * @return Ergebnis der Operation
 */
Bruch operator+(long const &lhs, Bruch const &rhs);

Bruch operator-(long const &lhs, Bruch const &rhs);

Bruch operator*(long const &lhs, Bruch const &rhs);

Bruch operator/(long const &lhs, Bruch const &rhs);
