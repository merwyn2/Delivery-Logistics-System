#include "Product.h"

Product::Product(int id, const std::string& name, const std::string& brand)
    : productID(id), name(name), brand(brand)
{
    // productID = id;
    // this->name = name;
    // this->brand = brand;
    
}

int Product::getProductID() const
{
    return productID;
}

std::string Product::getName() const
{
    return name;
}

std::string Product::getBrand() const
{
    return brand;
}