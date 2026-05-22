#include "Product.h"
#include <stdexcept>
#include <iomanip>
 
// Konstruktor
Product::Product(const std::string& name, double price, int stock)
    : m_name(name), m_price(price), m_stock(stock)
{
    if (price < 0)
        throw std::invalid_argument("Cena nie moze byc ujemna: " + name);
    if (stock < 0)
        throw std::invalid_argument("Stan magazynowy nie moze byc ujemny: " + name);
}
 
// Setter ceny — rzuca wyjątek przy błędnej wartości 
void Product::setPrice(double price) {
    if (price < 0)
        throw std::invalid_argument("Cena nie moze byc ujemna.");
    m_price = price;
}
 
// Setter stanu magazynowego
void Product::setStock(int stock) {
    if (stock < 0)
        throw std::invalid_argument("Stan magazynowy nie moze byc ujemny.");
    m_stock = stock;
}
  
std::string Product::getCategory() const {
    return "Produkt";
}
 
// Przeciążenie operator< — sortowanie po cenie 
bool Product::operator<(const Product& other) const {
    return m_price < other.m_price;
}
 
// Przeciążenie operator<< jako friend 
std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << std::left << std::setw(20) << p.m_name
       << std::right << std::setw(8) << std::fixed << std::setprecision(2)
       << p.m_price << " zl"
       << "  (stan: " << p.m_stock << ")";
    return os;
}
 
