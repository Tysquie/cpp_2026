#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iomanip>
 
#include "Vegetable.h"
#include "Fruit.h"
#include "Juice.h"
#include "Cart.h"
#include "Checkout.h"
 
int main() {
 
    // -------------------------------------------------------------------------
    // 1. Stragan — tworzymy produkty (polimorfizm, dziedziczenie)
    // -------------------------------------------------------------------------
    std::vector<Product*> stragan = {
        new Vegetable("Marchewka",        2.50, 100, "kg"),
        new Vegetable("Ziemniaki",        1.80, 200, "kg"),
        new Vegetable("Cebula",           3.00,  80, "kg"),
        new Fruit    ("Jablko",           4.00, 150, true),
        new Fruit    ("Banan",            5.50,  60, false),
        new Fruit    ("Truskawka",        8.00,  40, true),
        new Juice    ("Sok pomaranczowy", 7.00,  20, "pomarancza", 0.5),
        new Juice    ("Sok marchewkowy",  6.00,  15, "marchewka",  0.5),
    };
 
    // -------------------------------------------------------------------------
    // 2. Sortowanie po cenie — algorytm STL 
    // -------------------------------------------------------------------------
    std::sort(stragan.begin(), stragan.end(),
        [](Product* a, Product* b){ return *a < *b; });
 
    // -------------------------------------------------------------------------
    // 3. Wyświetl asortyment z dostępną ilością
    // -------------------------------------------------------------------------
    std::cout << "=== WARZYWNIAK U STACHA ===\n\n";
    std::cout << "--- Asortyment ---\n";
    std::cout << std::left
              << std::setw(22) << "Nazwa"
              << std::setw(14) << "Cena"
              << std::setw(10) << "Dostepne"
              << "Kategoria\n";
    std::cout << std::string(55, '-') << "\n";
 
    for (Product* p : stragan)
        p->printLabel();
 
    // -------------------------------------------------------------------------
    // 4. Interaktywne zakupy
    // -------------------------------------------------------------------------
    Cart koszyk(20);
    std::string nazwa;
 
    std::cout << "\n--- Zakupy ---\n";
    std::cout << "Wpisz nazwe produktu lub 'koniec' aby zakonczyc.\n\n";
 
    while (true) {
        std::cout << "Produkt: ";
        std::getline(std::cin, nazwa);
 
        if (nazwa == "koniec")
            break;
 
        // Wyszukiwanie po nazwie 
        auto it = std::find_if(stragan.begin(), stragan.end(),
            [&](Product* p){ return p->getName() == nazwa; });
 
        if (it == stragan.end()) {
            std::cout << "Nie ma takiego produktu. Sprobuj ponownie.\n\n";
            continue;
        }
 
        Product* produkt = *it;
 
        std::cout << "Dostepne: " << produkt->getStock()
                  << "  |  Cena: " << produkt->getPrice() << " zl\n";
        std::cout << "Ilosc: ";
 
        double ilosc;
        std::cin >> ilosc;
        std::cin.ignore();
 
        // Sprawdzenie dostępności
        if (ilosc <= 0) {
            std::cout << "Ilosc musi byc wieksza od zera.\n\n";
            continue;
        }
        if (ilosc > produkt->getStock()) {
            std::cout << "Za duzo! Dostepne tylko: " << produkt->getStock() << "\n\n";
            continue;
        }
 
        // Dodanie do koszyka i aktualizacja stanu
        try {
            koszyk.addProduct(produkt, ilosc);
            produkt->setStock(produkt->getStock() - ilosc);
            std::cout << "Dodano do koszyka!\n\n";
        } catch (const std::exception& e) {
            std::cerr << "[BLAD]: " << e.what() << "\n\n";
        }
    }
 
    // -------------------------------------------------------------------------
    // 5. Paragon
    // -------------------------------------------------------------------------
    if (koszyk.getSize() == 0) {
        std::cout << "\nKoszyk jest pusty. Do zobaczenia!\n";
    } else {
        std::cout << "\nIle placisz? ";
        double gotowka;
        std::cin >> gotowka;
 
        Checkout kasa("Warzywniak u Stacha");
 
        try {
            kasa.processPayment(koszyk, gotowka);
            kasa.printReceipt(koszyk, gotowka);
        } catch (const std::runtime_error& e) {
            std::cerr << "[BLAD KASY]: " << e.what() << "\n";
        }
    }
 
    // -------------------------------------------------------------------------
    // 6. Sprzątanie pamięci
    // -------------------------------------------------------------------------
    for (Product* p : stragan)
        delete p;
 
    return 0;
}
 
