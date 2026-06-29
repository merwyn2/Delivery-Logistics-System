#pragma once

#include <vector>

#include "Warehouse.h"
#include "Customer.h"
#include "Order.h"

class Truck;

class DeliveryManager
{
private:
    Warehouse warehouse;
    std::vector<Customer*> customers;
    std::vector<Order*> orders;
    std::vector<Truck*> trucks;

public:
    DeliveryManager(int warehouseID);
    void addStock(const Product& product, int quantity);
    void addCustomer(Customer* customer);
    void addTruck(Truck* truck);

    bool placeOrder(Customer* customer,
                    const std::vector<OrderItem>& items);

    void approveOrder(Order* order);

    void assignOrdersToTruck(Truck* truck);
};