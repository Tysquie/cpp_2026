#pragma once
 
#include <string>
#include <iostream>

class Product {
protected:
    std::string m_name;     // nazwa produktu
    double      m_price;    // cena bazowa (za kg lub za sztukę)
    int         m_stock;    // ilość dostępna na straganie
 
public:
    //Konstruktor
    Product(const std::string& name, double price, int stock);
 
    virtual ~Product() = default;
 
    const std::string& getName()  const { return m_name; }
    double             getPrice() const { return m_price; }
    int                getStock() const { return m_stock; }
 
    void setPrice(double price);
    void setStock(int stock);
 
    virtual double calculateFinalPrice(double amount) const = 0;
    virtual void   printLabel() const = 0;
 
    virtual std::string getCategory() const;
 
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
 
    bool operator<(const Product& other) const;
};
 
