#pragma once

#include <string>
#include <vector>

class Order;
class Customer{
    private:
        int customerID;
        std::string name;
        std::string contact;
        std::string address;
        std::vector<Order*> orders;
    public:
        Customer(int id, const std::string& name, const std::string& contact, const std::string& address);
    
        int getCustomerID() const;
        std::string getName() const;
        std::string getAddress() const;
        std::string getContact() const;
        void addOrder(Order* order);
        const std::vector<Order*>& getOrders() const;
};