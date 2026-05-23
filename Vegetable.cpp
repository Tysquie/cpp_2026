#include "Vegetable.h"
#include <iostream>
#include <iomanip>
 
// Konstruktor — przekazuje dane do konstruktora klasy bazowej
Vegetable::Vegetable(const std::string& name, double price, int stock, const std::string& unit)
    : Product(name, price, stock), m_unit(unit)
{
}
 
// Oblicza finalną cenę — cena * ilość 
double Vegetable::calculateFinalPrice(double amount) const {
    return m_price * amount;
}
 
// Wypisuje etykietę produktu 
void Vegetable::printLabel() const {
    std::cout << std::left << std::setw(20) << m_name
              << std::right << std::setw(6) << std::fixed << std::setprecision(2)
              << m_price << " zl/" << m_unit << "\n";
}
 
// Nadpisanie getCategory 
std::string Vegetable::getCategory() const {
    return "Warzywo";
}
 
