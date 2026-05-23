#include "Fruit.h"
#include <iostream>
#include <iomanip>
 
// Konstruktor — przekazuje dane do konstruktora klasy bazowej
Fruit::Fruit(const std::string& name, double price, int stock, bool seasonal)
    : Product(name, price, stock), m_seasonal(seasonal)
{
}
 
// Oblicza finalną cenę — rabat 10% jeśli owoc jest sezonowy 
double Fruit::calculateFinalPrice(double amount) const {
    if (m_seasonal)
        return m_price * amount * 0.9;
    return m_price * amount;
}
 
// Wypisuje etykietę produktu 
void Fruit::printLabel() const {
    std::cout << std::left << std::setw(20) << m_name
              << std::right << std::setw(6) << std::fixed << std::setprecision(2)
              << m_price << " zl/kg";
    if (m_seasonal)
        std::cout << "  [SEZONOWY -10%]";
    std::cout << "\n";
}
 
// Nadpisanie getCategory 
std::string Fruit::getCategory() const {
    return "Owoc";
}
 
