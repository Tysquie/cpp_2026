#pragma once
 
#include "Cart.h"
#include <string>
 
/**
 * Klasa Checkout (kasa)
 * Obsługuje płatność i drukuje paragon.
 */
class Checkout {
private:
    std::string m_storeName; // nazwa sklepu na paragonie
    int         m_receiptNo; // numer paragonu
 
public:
    Checkout(const std::string& storeName);
 
    // Przetwarza płatność — rzuca wyjątek jeśli za mało gotówki (cw6)
    double processPayment(const Cart& cart, double cash);
 
    // Drukuje paragon na ekran
    void printReceipt(const Cart& cart, double cash) const;
 
    int getReceiptNo() const { return m_receiptNo; }
};
