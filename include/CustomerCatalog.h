#pragma once

#include <unordered_map>

#include "Customer.h"

class CustomerCatalog
{
private:
    std::unordered_map<int, Customer*> customers;

    void saveCustomers() const;
    void loadCustomers();

public:
    CustomerCatalog();
    ~CustomerCatalog();

    void addCustomer(Customer* customer);

    Customer* getCustomer(int customerID);
};