#include "CustomerCatalog.h"

#include <fstream>

CustomerCatalog::CustomerCatalog()
{
    loadCustomers();
}

CustomerCatalog::~CustomerCatalog()
{
    for (auto& item : customers)
    {
        delete item.second;
    }
}

void CustomerCatalog::addCustomer(Customer* customer)
{
    auto it = customers.find(customer->getCustomerID());

    if (it == customers.end())
    {
        customers.insert({customer->getCustomerID(), customer});
    }
    else
    {
        delete it->second;
        it->second = customer;
    }

    saveCustomers();
}

Customer* CustomerCatalog::getCustomer(int customerID)
{
    auto it = customers.find(customerID);

    if (it == customers.end())
        return nullptr;

    return it->second;
}

void CustomerCatalog::saveCustomers() const
{
    std::ofstream out("data/customers.txt");

    for (const auto& item : customers)
    {
        Customer* customer = item.second;

        out << customer->getCustomerID() << ' '
            << customer->getName() << ' '
            << customer->getContact() << ' '
            << customer->getAddress() << '\n';
    }

    out.close();
}

void CustomerCatalog::loadCustomers()
{
    std::ifstream in("data/customers.txt");

    if (!in)
        return;

    customers.clear();

    int id;
    std::string name;
    std::string contact;
    std::string address;

    while (in >> id >> name >> contact >> address)
    {
        Customer* customer =
            new Customer(id, name, contact, address);

        customers.insert({id, customer});
    }

    in.close();
}