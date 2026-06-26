#pragma once

#include <string>

class Product
{
private:
    int productID;
    std::string name;
    std::string brand;

public:
    Product(int id, const std::string& name, const std::string& brand);

    int getProductID() const;
    std::string getName() const;
    std::string getBrand() const;
};