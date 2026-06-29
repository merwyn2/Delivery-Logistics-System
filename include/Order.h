#pragma once

#include <string>
#include <vector>

#include "OrderItem.h"

class Customer;

enum class Status
{
    Pending,
    Approved,
    InTruck,
    Delivered,
    Cancelled
};

class Order
{
private:
    int orderID;
    Customer* customer;
    std::vector<OrderItem> items;
    std::string deliveryAddress;
    Status status;

public:
    Order(int id,
          Customer* customer,
          const std::vector<OrderItem>& items,
          const std::string& deliveryAddress);

    int getOrderID() const;
    Customer* getCustomer() const;
    const std::vector<OrderItem>& getItems() const;
    std::string getDeliveryAddress() const;
    Status getStatus() const;

    void setStatus(Status status);
};