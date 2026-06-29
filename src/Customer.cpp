#include "Customer.h"

Customer::Customer(int id,
                   const std::string& name,
                   const std::string& contact,
                   const std::string& address)
    : customerID(id), name(name), contact(contact), address(address)
{
}

int Customer::getCustomerID() const
{
    return customerID;
}

std::string Customer::getName() const
{
    return name;
}

std::string Customer::getAddress() const
{
    return address;
}

std::string Customer::getContact() const
{
    return contact;
}

void Customer::addOrder(Order* order)
{
    orders.push_back(order);
}

const std::vector<Order*>& Customer::getOrders() const
{
    return orders;
}