#include "Cart.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
 
// Konstruktor — alokuje dynamiczne tablice (RAII)
Cart::Cart(int capacity)
    : m_size(0), m_capacity(capacity)
{
    m_items   = new Product*[m_capacity];
    m_amounts = new double[m_capacity];
}
 
// Konstruktor kopiujący — głęboka kopia 
Cart::Cart(const Cart& other)
    : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_items   = new Product*[m_capacity];
    m_amounts = new double[m_capacity];
 
    for (int i = 0; i < m_size; i++) {
        m_items[i]   = other.m_items[i];
        m_amounts[i] = other.m_amounts[i];
    }
}
 
// Destruktor — zwalnia pamięć (RAII)
Cart::~Cart() {
    delete[] m_items;
    delete[] m_amounts;
}
 
// Dodanie produktu do koszyka
void Cart::addProduct(Product* product, double amount) {
    if (m_size >= m_capacity)
        throw std::runtime_error("Koszyk jest pelny!");
    if (amount <= 0)
        throw std::invalid_argument("Ilosc musi byc wieksza od zera.");
 
    m_items[m_size]   = product;
    m_amounts[m_size] = amount;
    m_size++;
}
 
// Suma do zapłaty
double Cart::getTotal() const {
    double total = 0.0;
    for (int i = 0; i < m_size; i++)
        total += m_items[i]->calculateFinalPrice(m_amounts[i]);
    return total;
}
 
// Wyczyszczenie koszyka
void Cart::clear() {
    m_size = 0;
}
 
// Wypisanie zawartości koszyka
void Cart::printContents() const {
    for (int i = 0; i < m_size; i++) {
        std::cout << "  ";
        m_items[i]->printLabel();
    }
}
 
// Przeciążenie operator<< 
std::ostream& operator<<(std::ostream& os, const Cart& cart) {
    os << "Koszyk (" << cart.m_size << " pozycji):\n";
    for (int i = 0; i < cart.m_size; i++) {
        os << "  " << cart.m_items[i]->getName()
           << " x" << cart.m_amounts[i]
           << "  ->  " << std::fixed << std::setprecision(2)
           << cart.m_items[i]->calculateFinalPrice(cart.m_amounts[i]) << " zl\n";
    }
    os << "  -------------------\n";
    os << "  SUMA: " << std::fixed << std::setprecision(2) << cart.getTotal() << " zl\n";
    return os;
}
