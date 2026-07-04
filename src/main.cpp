#include <iostream>
#include <vector>

#include "DeliveryManager.h"
#include "Truck.h"
#include "OrderItem.h"
#include "OrderUtils.h"

int main()
{
    DeliveryManager manager(1);

    Truck truck(1, 5);
    manager.addTruck(&truck);

    Customer* customer = manager.getCustomer(1);
    Product* product = manager.getProduct(1);

    if (!customer || !product)
    {
        std::cout << "Demo data missing.\n";
        return 1;
    }

    std::vector<OrderItem> items;
    items.emplace_back(*product, 1);

    if (!manager.placeOrder(customer, items))
    {
        std::cout << "Order placement failed.\n";
        return 1;
    }

    Order* order = customer->getOrders().back();

    manager.approveOrder(order);
    manager.assignOrdersToTruck(&truck);
    manager.completeDelivery(order->getOrderID());

    std::cout << "========== DEMO ==========\n";
    std::cout << "Customer : " << customer->getName() << '\n';
    std::cout << "Product  : " << product->getName() << '\n';
    std::cout << "Order ID : " << order->getOrderID() << '\n';
    std::cout << "Status   : "
              << statusToString(order->getStatus()) << '\n';
    std::cout << "==========================\n";

    return 0;
}