#include <iostream>
#include"Bruch.hpp"
#include <fstream>
#include <vector>
#include "Vektor2.hpp"
#include <sstream>

int main() {
    std::cout << "-----Test der Klasse Bruch-----" << std::endl;
    std::cout << std::endl;
    Bruch fractionOne(1, 10);
    Bruch fractionTwo(23);
    Bruch result;
    Bruch testeKuerze(1024, 512);

    std::cout << "Konstruktoraufruf Bruch(1,10): " << fractionOne << std::endl;
    std::cout << "Konstruktoraufruf Bruch(23): " << fractionTwo << std::endl;

    // std::cout << "Der groesste gemeinsame Teiler von 10 und 1 ist " << gcd(5, 25) << std::endl;
    std::cout << "Das kleinste gemeinsame Vielfache von 10 und 1 ist " << lcm(5, 25) << std::endl;
    std::cout << std::endl;

    std::cout << "Test Bruch -Operator- Bruch" << std::endl;
    result = fractionOne + fractionTwo;
    std::cout << fractionOne << " + " << fractionTwo << " = " << result << std::endl;
    result = fractionOne - fractionTwo;
    std::cout << fractionOne << " - " << fractionTwo << " = " << result << std::endl;
    result = fractionOne * fractionTwo;
    std::cout << fractionOne << " * " << fractionTwo << " = " << result << std::endl;
    result = fractionOne / fractionTwo;
    std::cout << fractionOne << " / " << fractionTwo << " = " << result << std::endl;
    std::cout << std::endl;


    std::cout << "Test Bruch -Operator- long int" << std::endl;

    result = fractionOne + 5;
    std::cout << fractionOne << " + " << 5 << " = " << result << std::endl;
    result = fractionOne - 5;
    std::cout << fractionOne << " - " << 5 << " = " << result << std::endl;
    result = fractionOne * 5;
    std::cout << fractionOne << " * " << 5 << " = " << result << std::endl;
    result = fractionOne / 5;
    std::cout << fractionOne << " / " << 5 << " = " << result << std::endl;
    std::cout << std::endl;

    std::cout << "long int -Operator- Bruch" << std::endl;

    result = 5 + fractionOne;
    std::cout << 5 << " + " << fractionOne << " = " << result << std::endl;
    result = 5 - fractionOne;
    std::cout << 5 << " - " << fractionOne << " = " << result << std::endl;
    result = 5 * fractionOne;
    std::cout << 5 << " * " << fractionOne << " = " << result << std::endl;
    result = 5 / fractionOne;
    std::cout << 5 << " / " << fractionOne << " = " << result << std::endl;
    std::cout << std::endl;


    std::cout << testeKuerze;
    std::cout << " soweit wie moeglich gekuerzt ist " << testeKuerze.kuerzeBruch() << std::endl;
    std::cout << std::endl;

    std::cout << "-----Test der Vektorklasse-----" << std::endl;
    std::cout << std::endl;
    Bruch eins(5, 4);
    Bruch zwei(17, 4);
    Bruch drei(9, 16);
    Vektor ersterVektor(eins, zwei);

    std::cout << "Dies ist ein Vektor:" << std::endl;
    ersterVektor.print(std::cout);

    std::cout << "Dies ist die zweite Stelle des Vektors:" << std::endl;
    std::cout << ersterVektor.at(1) << std::endl;
    std::cout << "Dies ist der selbe Vektor mit geaenderter erster Stelle:" << std::endl;
    ersterVektor.at(0) = drei;
    ersterVektor.print(std::cout);
    std::cout << "Dies ist der selbe Vektor mit geaenderter zweiter Stelle:" << std::endl;
    ersterVektor.set(1, eins);
    ersterVektor.print(std::cout);

    Vektor zweiterVektor(drei, zwei);
    Vektor dritterVektor(zwei, eins);
    std::cout << "Dies dies sind zwei neue Vektoren:" << std::endl;
    zweiterVektor.print(std::cout);
    dritterVektor.print(std::cout);
    std::cout << "Dies ist ihre Summe:" << std::endl;
    add(zweiterVektor, dritterVektor).print(std::cout);
    std::cout << "Dies ist ihr Skalarprodukt:" << std::endl;
    std::cout << dot(zweiterVektor, dritterVektor) << std::endl;
    std::cout << std::endl;


// Einlesen und Kürzen der Datei
    std::cout << "-----Test Einlesen und Kuerzen-----" << std::endl;
    std::cout << std::endl;
    std::ifstream file("C:\\Users\\Manu\\Desktop\\test.txt");
    std::string inputdata, denominator, numerator;
    std::string const bruchstrich("/");
    int numerator_, denominator_;
    size_t pos;
    Bruch input;

    if (file >> inputdata)

        inputdata.find(bruchstrich);
    numerator = inputdata.substr(0, inputdata.find(bruchstrich));
    std::stringstream sstr(numerator);
    sstr >> numerator_;

    pos = inputdata.find(bruchstrich);
    denominator = inputdata.substr(pos + bruchstrich.length());
    std::stringstream sstr2(denominator);
    sstr2 >> denominator_;

    input = Bruch(numerator_, denominator_);
    std::cout << "Eingelesener Bruch: " << input << std::endl;
    std::cout << "Eingelesener Bruch gekuerzt: " << input.kuerzeBruch() << std::endl;
    return 0 ;
}
/*




// Test der Vektorklasse
    std::cout << "-----Test der Vektorklasse-----" << std::endl;
    std::cout << std::endl;
    Bruch eins(5, 4);
    Bruch zwei(17, 4);
    Bruch drei(9, 16);
    Vektor ersterVektor(eins, zwei);

    std::cout << "Dies ist ein Vektor:" << std::endl;
    ersterVektor.print(std::cout);

    std::cout << "Dies ist die euklidische Norm des Vektors:" << std::endl;
    std::cout << ersterVektor.norm() << std::endl;
    std::cout << "Dies ist die zweite Stelle des Vektors:" << std::endl;
    std::cout << ersterVektor.at(1) << std::endl;
    std::cout << "Dies ist der selbe Vektor mit geaenderter erster Stelle:" << std::endl;
    ersterVektor.at(0) = drei;
    ersterVektor.print(std::cout);
    std::cout << "Dies ist der selbe Vektor mit geaenderter zweiter Stelle:" << std::endl;
    ersterVektor.set(1, eins);
    ersterVektor.print(std::cout);

    Vektor zweiterVektor(drei, zwei);
    Vektor dritterVektor(zwei, eins);
    std::cout << "Dies dies sind zwei neue Vektoren:" << std::endl;
    zweiterVektor.print(std::cout);
    dritterVektor.print(std::cout);
    std::cout << "Dies ist ihre Summe:" << std::endl;
    add(zweiterVektor, dritterVektor).print(std::cout);
    std::cout << "Dies ist ihr Skalarprodukt:" << std::endl;
    std::cout << dot(zweiterVektor, dritterVektor) << std::endl;
    std::cout << std::endl;


// Einlesen und Kürzen der Datei
    std::cout << "-----Test Einlesen und Kuerzen-----" << std::endl;
    std::cout << std::endl;
    std::ifstream file("C:\\Users\\Manu\\Desktop\\test.txt");
    std::string inputdata, denominator, numerator;
    std::string const bruchstrich("/");
    int numerator_, denominator_;
    size_t pos;
    Bruch input;

    if (file >> inputdata)

        inputdata.find(bruchstrich);
    numerator = inputdata.substr(0, inputdata.find(bruchstrich));
    std::stringstream sstr(numerator);
    sstr >> numerator_;

    pos = inputdata.find(bruchstrich);
    denominator = inputdata.substr(pos + bruchstrich.length());
    std::stringstream sstr2(denominator);
    sstr2 >> denominator_;

    input = Bruch(numerator_, denominator_);
    std::cout << "Eingelesener Bruch: " << input << std::endl;
    std::cout << "Eingelesener Bruch gekuerzt: " << input.kuerzeBruch() << std::endl;


    return 0;
}

*/

