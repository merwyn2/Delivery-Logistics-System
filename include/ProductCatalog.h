#pragma once

#include <unordered_map>

#include "Product.h"

class ProductCatalog
{
private:
    std::unordered_map<int, Product> products;

    void saveProducts() const;
    void loadProducts();

public:
    ProductCatalog();

    void addProduct(const Product& product);

    Product* getProduct(int productID);
};