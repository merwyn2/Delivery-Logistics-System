#include "Warehouse.h"
#include <fstream>

Warehouse::Warehouse(int id)
    : warehouseID(id)
{
    loadStock();
}

void Warehouse::addStock(const Product& product, int quantity)
{
    stock[product.getProductID()] += quantity;
    saveStock();
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
    saveStock();
}

int Warehouse::getStock(const Product& product) const
{
    auto it = stock.find(product.getProductID());

    if (it == stock.end())
        return 0;

    return it->second;
}

void Warehouse::saveStock() const
{
    std::ofstream out("data/warehouse.txt");

    for (const auto& item : stock)
    {
        out << item.first << " "
            << item.second << '\n';
    }

    out.close();
}
void Warehouse::loadStock()
{
    std::ifstream in("data/warehouse.txt");

    if(!in)
    {
        return;
    }

    stock.clear();

    int productID;
    int quantity;

    while (in >> productID >> quantity)
    {
        stock[productID] = quantity;
    }

    in.close();
}

const std::unordered_map<int, int>& Warehouse::getStockMap() const
{
    return stock;
}