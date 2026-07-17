#pragma once

#include <unordered_map>
#include "Product.h"

class Warehouse
{
private:
    int warehouseID;
    std::unordered_map<int, int> stock;

public:
    Warehouse(int id);

    void addStock(const Product& product, int quantity);
    bool hasStock(const Product& product, int quantity) const;
    void removeStock(const Product& product, int quantity);
    int getStock(const Product& product) const;

    const std::unordered_map<int, int>& getStockMap() const;
    
private:
    void saveStock() const;
    void loadStock();
};