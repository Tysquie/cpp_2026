#pragma once
 
#include "Product.h"
 

 // Sprzedawane na kg lub na sztuki.
 
class Vegetable : public Product {
private:
    std::string m_unit; // "kg" lub "szt"
 
public:
    Vegetable(const std::string& name, double price, int stock, const std::string& unit = "kg");

    double calculateFinalPrice(double amount) const override;
    void   printLabel() const override;
 
    std::string getCategory() const override;
 
    const std::string& getUnit() const { return m_unit; }
};
 
