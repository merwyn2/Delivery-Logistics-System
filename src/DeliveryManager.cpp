#include "DeliveryManager.h"
#include "Truck.h"

DeliveryManager::DeliveryManager(int warehouseID)
    : warehouse(warehouseID)
{
}
void DeliveryManager::addStock(const Product& product, int quantity)
{
    warehouse.addStock(product, quantity);
}
void DeliveryManager::addCustomer(Customer* customer)
{
    customers.push_back(customer);
}

void DeliveryManager::addTruck(Truck* truck)
{
    trucks.push_back(truck);
}

bool DeliveryManager::placeOrder(Customer* customer,
                                 const std::vector<OrderItem>& items)
{
    // Check stock
    for (const auto& item : items)
    {
        if (!warehouse.hasStock(item.getProduct(), item.getQuantity()))
            return false;
    }

    // Remove stock
    for (const auto& item : items)
    {
        warehouse.removeStock(item.getProduct(), item.getQuantity());
    }

    // Create order
    Order* order = new Order(
        orders.size() + 1,
        customer,
        items,
        customer->getAddress());

    orders.push_back(order);
    customer->addOrder(order);

    return true;
}

void DeliveryManager::approveOrder(Order* order)
{
    order->setStatus(Status::Approved);
}

void DeliveryManager::assignOrdersToTruck(Truck* truck)
{
    for (Order* order : orders)
    {
        if (order->getStatus() == Status::Approved)
        {
            if (!truck->addOrder(order))
                break;
        }
    }
}