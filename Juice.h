#pragma once
 
#include "Product.h"
 
/**
 * Klasa Juice
 * Reprezentuje sok wyciskany na miejscu.
 * Sprzedawany na sztuki (butelki), cena stała za butelkę.
 */
class Juice : public Product {
private:
    std::string m_ingredient; // z czego wyciśnięty, np. "pomarańcza"
    double      m_volume;     // pojemność butelki w litrach
 
public:
    Juice(const std::string& name, double price, int stock,
          const std::string& ingredient, double volume);
 
    double calculateFinalPrice(double amount) const override;
    void   printLabel() const override;
 
    std::string getCategory() const override;
 
    const std::string& getIngredient() const { return m_ingredient; }
    double             getVolume()     const { return m_volume; }
};
 
