#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
 
#include "Vegetable.h"
#include "Fruit.h"
#include "Juice.h"
#include "Cart.h"
#include "Checkout.h"
 
int main() {
 
    // -------------------------------------------------------------------------
    // 1. Stragan — tworzymy produkty (polimorfizm, dziedziczenie)
    // -------------------------------------------------------------------------
    std::cout << "=== WARZYWNIAK U STACHA ===\n\n";
 
    std::vector<Product*> stragan = {
        new Vegetable("Marchewka",      2.50, 100, "kg"),
        new Vegetable("Ziemniaki",      1.80, 200, "kg"),
        new Vegetable("Cebula",         3.00,  80, "kg"),
        new Fruit    ("Jablko",         4.00, 150, true),   // sezonowe -10%
        new Fruit    ("Banan",          5.50,  60, false),
        new Fruit    ("Truskawka",      8.00,  40, true),   // sezonowe -10%
        new Juice    ("Sok pomaranczowy", 7.00, 20, "pomarancza", 0.5),
        new Juice    ("Sok marchewkowy", 6.00, 15, "marchewka",  0.5),
    };
 
 
    // -------------------------------------------------------------------------
    // 2. Sortowanie po cenie — algorytm STL 
    // -------------------------------------------------------------------------
    std::cout << "\n--- Asortyment posortowany po cenie ---\n";
    std::sort(stragan.begin(), stragan.end(),
        [](Product* a, Product* b){ return *a < *b; });
 
    for (Product* p : stragan)
        p->printLabel();
 
    // -------------------------------------------------------------------------
    // 3. Wyszukiwanie produktu — algorytm STL 
    // -------------------------------------------------------------------------
    std::string szukana = "Truskawka";
    auto it = std::find_if(stragan.begin(), stragan.end(),
        [&](Product* p){ return p->getName() == szukana; });
 
    std::cout << "\n--- Wyszukiwanie: " << szukana << " ---\n";
    if (it != stragan.end())
        std::cout << "Znaleziono: " << **it << "\n";
    else
        std::cout << "Nie znaleziono produktu.\n";
 
    // -------------------------------------------------------------------------
    // 4. Koszyk — konstruktor kopiujący, wyjątki 
    // -------------------------------------------------------------------------
    std::cout << "\n--- Klient robi zakupy ---\n";
 
    Cart koszyk(10);
 
    try {
        koszyk.addProduct(stragan[0], 0.5);  // 0.5 kg marchewki
        koszyk.addProduct(stragan[3], 1.0);  // 1.0 kg jablek (sezonowe)
        koszyk.addProduct(stragan[6], 2.0);  // 2 soki pomaranczowe
        koszyk.addProduct(stragan[1], 2.0);  // 2.0 kg ziemniakow
    } catch (const std::invalid_argument& e) {
        std::cerr << "[BLAD]: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "[BLAD]: " << e.what() << "\n";
    }
 
    // Demonstracja konstruktora kopiującego
    Cart kopia(koszyk);
    std::cout << "Kopia koszyka utworzona poprawnie.\n";
 
    // -------------------------------------------------------------------------
    // 5. Kasa — płatność i paragon
    // -------------------------------------------------------------------------
    Checkout kasa("Warzywniak u Stacha");
 
    try {
        double reszta = kasa.processPayment(koszyk, 50.00);
        kasa.printReceipt(koszyk, 50.00);
        std::cout << "Reszta wyplacona: " << reszta << " zl\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "[BLAD KASY]: " << e.what() << "\n";
    }
 
    // Demonstracja wyjątku — za mało gotówki
    std::cout << "\n--- Proba zaplacenia za malo ---\n";
    try {
        kasa.processPayment(koszyk, 1.00);
    } catch (const std::runtime_error& e) {
        std::cerr << "[BLAD KASY]: " << e.what() << "\n";
    }
 
    // -------------------------------------------------------------------------
    // 6. Sprzątanie — zwalniamy pamięć
    // -------------------------------------------------------------------------
    for (Product* p : stragan)
        delete p;
 
    return 0;
}
