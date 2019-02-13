//
// Created by Manuel Wörle on 02.01.2017.
//

#pragma once
#include <vector>
#include <iostream>
#include "Bruch.hpp"

/**
 * Klasse zur Darstellung und Bearbeitung von Vektoren in 2D
 */
class Vektor {

public:

    /**
     * Konstruktor zur Erstellung von Vektoren in 2D
     * @param x erster Eintrag
     * @param y zweiter Eintrag
     */
    Vektor(Bruch x, Bruch y);

    /**
     * Destruktor für die Klasse Vektor
     */
    virtual ~Vektor();

    /**
     * Methode die den Wert des Vektors an einer bestimmten Stelle zurück gibt
     * @pre Vektor in 2D
     * @param index gewünschte Stelle im Vektor
     * @return Wert an entsprechendem index
     */
    Bruch at(size_t index) const;

    /**
     * Änderung des Wertes einer bestimmten Stelle im Vektor
     * @param index Stelle die geändert werden soll
     * @param value neuer Wert
     */
    void set(size_t index, Bruch value);

    /**
     * Rückgabe einer Referenz auf eine bestimmte Stelle im Vektor
     * @param index gewünschte Stelle
     * @return Wert an entsprechender Stelle
     */
    Bruch &at(size_t index);

    /**
     * Berechnung der euklidischen Norm eines Vektors
     * @return euklidische Norm eines Vektors
     */
    //double norm() const;

    /**
     * Formatierung und Ausgabe eines Vektors
     * @param out gewünschte Ausgabe
     */
    void print(std::ostream &out) const;

    /**
     * Bestimmung der Dimension eines Vektors
     * @return
     */
    size_t size() const;

    /**
     * Setzt jeden Wert eines Vektors auf Null
     */
    void setNull();

private:
    /**
     * Deklaration eines Vektors
     */
    std::vector<Bruch> vektor;
};

/**
 * Addition von zwei Vektoren
 * @param a Referenz auf Vektor a
 * @param b Referenz auf Vektor b
 * @return Ergebnis der Addition
 */
Vektor add(const Vektor &a, const Vektor &b);

/**
 * Skalarmultiplikation von zwei Vektoren
 * @param a Referenz auf Vektor a
 * @param b Referenz auf Vektor b
 * @return Skalarprodukt
 */
Bruch dot(const Vektor &a, const Vektor &b);
