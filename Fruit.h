#pragma once
 
#include "Product.h"
 
/**
 * Klasa Fruit 
 * Reprezentuje owoc na straganie.
 * Owoce sezonowe są tańsze — rabat 10% przy m_seasonal = true.
 */
class Fruit : public Product {
private:
    bool m_seasonal; // czy owoc jest aktualnie sezonowy
 
public:
    Fruit(const std::string& name, double price, int stock, bool seasonal = false);
 
    double calculateFinalPrice(double amount) const override;
    void   printLabel() const override;
 
    std::string getCategory() const override;
 
    bool isSeasonal() const { return m_seasonal; }
};
 
