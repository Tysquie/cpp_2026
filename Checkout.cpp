#include "Checkout.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
 
// Konstruktor
Checkout::Checkout(const std::string& storeName)
    : m_storeName(storeName), m_receiptNo(1)
{
}
 
// Przetwarza płatność — rzuca wyjątek jeśli za mało gotówki 
double Checkout::processPayment(const Cart& cart, double cash) {
    double total = cart.getTotal();
    if (cash < total)
        throw std::runtime_error("Za mala kwota! Brakuje: " +
            std::to_string(total - cash) + " zl");
    m_receiptNo++;
    return cash - total; // reszta
}
 
// Drukuje paragon
void Checkout::printReceipt(const Cart& cart, double cash) const {
    double total   = cart.getTotal();
    double reszta  = cash - total;
 
    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "       " << m_storeName << "\n";
    std::cout << "==============================\n";
    std::cout << "Paragon nr: " << m_receiptNo << "\n";
    std::cout << "------------------------------\n";
    std::cout << cart;
    std::cout << "------------------------------\n";
    std::cout << "Zaplacono:  " << std::fixed << std::setprecision(2) << cash    << " zl\n";
    std::cout << "Reszta:     " << std::fixed << std::setprecision(2) << reszta  << " zl\n";
    std::cout << "==============================\n\n";
}
