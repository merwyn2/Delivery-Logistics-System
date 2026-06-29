#include "Warehouse.h"

Warehouse::Warehouse(int id)
    : warehouseID(id)
{
}

void Warehouse::addStock(const Product& product, int quantity)
{
    stock[product.getProductID()] += quantity;
}

bool Warehouse::hasStock(const Product& product, int quantity) const
{
    auto it = stock.find(product.getProductID());

    if (it == stock.end())
        return false;

    return it->second >= quantity;
}

void Warehouse::removeStock(const Product& product, int quantity)
{
    if (hasStock(product, quantity))
    {
        stock[product.getProductID()] -= quantity;
    }
}

int Warehouse::getStock(const Product& product) const
{
    auto it = stock.find(product.getProductID());

    if (it == stock.end())
        return 0;

    return it->second;
}