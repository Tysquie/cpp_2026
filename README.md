# 🥦 Warzywniak
 
Projekt zaliczeniowy na kurs **Programowanie w C++**. Konsolowa aplikacja symulująca działanie warzywniaka — od straganu z towarem, przez koszyk klienta, po kasę z paragonem.
 
---
 
## 📌 Opis
 
Program pozwala na:
- przeglądanie asortymentu (warzywa, owoce, soki)
- dodawanie produktów do koszyka
- obsługę kasy — wyliczenie sumy i wydruk paragonu
- sortowanie i wyszukiwanie produktów na straganie
---
 
## 🧬 Hierarchia klas
 
```
Product                  ← klasa abstrakcyjna
├── Vegetable            ← warzywa (cena za kg)
├── Fruit                ← owoce (cena za kg, sezonowość)
└── Juice                ← soki (wyciskane na miejscu, cena za butelkę)
```
 
---
 
## ✅ Zrealizowane wymagania kursu
 
| Wymaganie | Gdzie w projekcie |
|-----------|-------------------|
| Klasy i enkapsulacja | `Product`, `Vegetable`, `Fruit`, `Juice` |
| Konstruktory i destruktor (RAII) | `Cart` — zarządza dynamiczną pamięcią |
| Konstruktor kopiujący (głęboka kopia) | `Cart::Cart(const Cart&)` |
| Deklaracja `friend` | `operator<<` w `Product` |
| Dziedziczenie | `Vegetable`, `Fruit`, `Juice` → `Product` |
| Polimorfizm | `calculateFinalPrice()`, `printLabel()` przez `Product*` |
| Klasa abstrakcyjna | `Product` — metody czysto wirtualne (`= 0`) |
| STL — kontenery | `std::vector<Product*>` na straganie |
| STL — iteratory i algorytmy | `std::sort`, `std::find_if` |
| Zakresowa pętla `for` | iteracja po koszyku i straganie |
| Przeciążanie operatorów | `operator<<`, `operator<` |
| Obsługa wyjątków | `try-catch` przy błędnych danych i płatności |
| Szablon klasy *(opcjonalne)* | `Stand<T>` — generyczny stragan |
 
---
 
## 🏗️ Struktura projektu
 
```
├── Product.h / .cpp          ← klasa abstrakcyjna
├── Vegetable.h / .cpp        ← warzywa
├── Fruit.h / .cpp            ← owoce
├── Juice.h / .cpp            ← soki
├── Cart.h / .cpp             ← koszyk (Rule of Three)
├── Checkout.h / .cpp         ← kasa i paragon
├── Stand.h                   ← szablon straganu
├── main.cpp                  ← demonstracja działania
└── Makefile
```
 
---
 
## 🚀 Kompilacja i uruchomienie
 
```bash
make
./warzywniak
```
 
Wymagany kompilator z obsługą **C++17**.
 
---
 
## 📚 Kurs
 
Projekt realizowany w ramach kursu Programowanie w C++ 2026.
 
