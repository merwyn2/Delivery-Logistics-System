#include "Truck.h"

Truck::Truck(int id, int capacity)
    : truckID(id), capacity(capacity)
{
}

int Truck::getTruckID() const
{
    return truckID;
}

int Truck::getCapacity() const
{
    return capacity;
}

bool Truck::addOrder(Order* order)
{
    if (orders.size() >= capacity)
    {
        return false;
    }

    orders.push_back(order);
    order->setStatus(Status::InTruck);

    return true;
}

const std::vector<Order*>& Truck::getOrders() const
{
    return orders;
}