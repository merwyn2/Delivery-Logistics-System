#pragma once

#include <vector>

#include "Order.h"

class Truck
{
private:
    int truckID;
    int capacity;
    std::vector<Order*> orders;

public:
    Truck(int id, int capacity);

    int getTruckID() const;
    int getCapacity() const;

    bool addOrder(Order* order);

    const std::vector<Order*>& getOrders() const;
};