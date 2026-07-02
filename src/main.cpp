#include <iostream>
#include <vector>

#include "DeliveryManager.h"
#include "Truck.h"
#include "OrderItem.h"

int main()
{
    DeliveryManager manager(1);

    // Load customer from CustomerCatalog
    Customer* customer = manager.getCustomer(1);

    if (customer == nullptr)
    {
        std::cout << "Customer not found.\n";
        return 1;
    }

    // Load product from ProductCatalog
    Product* phone = manager.getProduct(1);

    if (phone == nullptr)
    {
        std::cout << "Product not found.\n";
        return 1;
    }

    // Create truck
    Truck truck(1, 5);

    manager.addTruck(&truck);

    // Create order
    std::vector<OrderItem> items;
    items.emplace_back(*phone, 2);

    if (!manager.placeOrder(customer, items))
    {
        std::cout << "Order placement failed.\n";
        return 1;
    }

    std::cout << "Order placed successfully!\n";

    Order* order = customer->getOrders()[0];

    manager.approveOrder(order);

    std::cout << "Order approved!\n";

    manager.assignOrdersToTruck(&truck);

    std::cout << "Truck now has "
              << truck.getOrders().size()
              << " order(s).\n";

    std::cout << "Final Order Status: ";

    switch (order->getStatus())
    {
        case Status::Pending:
            std::cout << "Pending";
            break;

        case Status::Approved:
            std::cout << "Approved";
            break;

        case Status::InTruck:
            std::cout << "InTruck";
            break;

        case Status::Delivered:
            std::cout << "Delivered";
            break;

        case Status::Cancelled:
            std::cout << "Cancelled";
            break;
    }

    std::cout << '\n';

    return 0;
}