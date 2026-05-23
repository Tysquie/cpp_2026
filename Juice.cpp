#include "Juice.h"
#include <iostream>
#include <iomanip>
 
// Konstruktor — przekazuje dane do konstruktora klasy bazowej
Juice::Juice(const std::string& name, double price, int stock,
             const std::string& ingredient, double volume)
    : Product(name, price, stock), m_ingredient(ingredient), m_volume(volume)
{
}
 
// Oblicza finalną cenę — cena stała za sztukę (butelkę), amount to liczba butelek 
double Juice::calculateFinalPrice(double amount) const {
    return m_price * amount;
}
 
// Wypisuje etykietę produktu 
void Juice::printLabel() const {
    std::cout << std::left << std::setw(20) << m_name
              << std::right << std::setw(6) << std::fixed << std::setprecision(2)
              << m_price << " zl/szt"
              << "  (" << m_ingredient << ", " << m_volume << "l)\n";
}
 
// Nadpisanie getCategory 
std::string Juice::getCategory() const {
    return "Sok";
}
