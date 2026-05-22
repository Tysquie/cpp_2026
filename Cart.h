#pragma once
 
#include "Product.h"
#include <vector>
 
/**
 * Klasa Cart (koszyk zakupowy)
 * Przechowuje produkty dodane przez klienta.
 */
class Cart {
private:
    Product** m_items;   // dynamiczna tablica wskaźników na produkty
    int       m_size;    // aktualna liczba produktów w koszyku
    int       m_capacity; // pojemność tablicy
 
public:
    // Konstruktor
    Cart(int capacity = 10);
 
    // Konstruktor kopiujący — głęboka kopia
    Cart(const Cart& other);
 
    // Destruktor — zwalnia pamięć 
    ~Cart();
 
    // Dodanie produktu do koszyka (rzuca wyjątek jeśli brak miejsca)
    void addProduct(Product* product, double amount);
 
    // Suma do zapłaty
    double getTotal() const;
 
    // Liczba pozycji w koszyku
    int getSize() const { return m_size; }
 
    // Wyczyszczenie koszyka
    void clear();
 
    // Wypisanie zawartości koszyka
    void printContents() const;
 
    // Przeciążenie operator<< jako friend (cw4)
    friend std::ostream& operator<<(std::ostream& os, const Cart& cart);
 
private:
    double* m_amounts; // ilość każdego produktu (równoległa do m_items)
};
