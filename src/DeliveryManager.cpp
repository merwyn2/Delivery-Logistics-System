#include "DeliveryManager.h"
#include "Truck.h"

DeliveryManager::DeliveryManager(int warehouseID)
    : warehouse(warehouseID),
      orderCatalog(&customerCatalog, &catalog)
{
}

void DeliveryManager::addStock(const Product& product, int quantity)
{
    warehouse.addStock(product, quantity);
}
void DeliveryManager::addCustomer(Customer* customer)
{
    customerCatalog.addCustomer(customer);
}

void DeliveryManager::registerCustomer(int id,
                                       const std::string& name,
                                       const std::string& contact,
                                       const std::string& address)
{
    Customer* customer =
        new Customer(id, name, contact, address);

    customerCatalog.addCustomer(customer);
}

void DeliveryManager::addTruck(Truck* truck)
{
    trucks.push_back(truck);
}

Customer* DeliveryManager::getCustomer(int customerID)
{
    return customerCatalog.getCustomer(customerID);
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

    orderCatalog.addOrder(order);

    return true;
}

Product* DeliveryManager::getProduct(int productID)
{
    return catalog.getProduct(productID);
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

Order* DeliveryManager::getOrder(int orderID)
{
    return orderCatalog.getOrder(orderID);
}