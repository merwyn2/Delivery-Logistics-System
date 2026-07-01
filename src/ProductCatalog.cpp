#include "ProductCatalog.h"

#include <fstream>

ProductCatalog::ProductCatalog()
{
    loadProducts();
}

void ProductCatalog::addProduct(const Product& product)
{
    auto it = products.find(product.getProductID());

    if (it == products.end())
    {
        products.insert({product.getProductID(), product});
    }
    else
    {
        it->second = product;
    }

    saveProducts();
}

Product* ProductCatalog::getProduct(int productID)
{
    auto it = products.find(productID);

    if (it == products.end())
        return nullptr;

    return &(it->second);
}

void ProductCatalog::saveProducts() const
{
    std::ofstream out("data/products.txt");

    for (const auto& item : products)
    {
        const Product& product = item.second;

        out << product.getProductID() << ' '
            << product.getName() << ' '
            << product.getBrand() << '\n';
    }

    out.close();
}

void ProductCatalog::loadProducts()
{
    std::ifstream in("data/products.txt");

    if (!in)
        return;

    products.clear();

    int id;
    std::string name;
    std::string brand;

    while (in >> id >> name >> brand)
    {
        Product product(id, name, brand);

        products.insert({id,product});
    }

    in.close();
}