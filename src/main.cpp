#include <iostream>
#include <vector>

#include "DeliveryManager.h"
#include "Truck.h"
#include "Customer.h"
#include "OrderItem.h"

int main()
{
    // Create manager
    DeliveryManager manager(1);

    // Load product from catalog
    Product* phone = manager.getProduct(1);

    if (phone == nullptr)
    {
        std::cout << "Product not found.\n";
        return 1;
    }

    // Create customer
    Customer customer(
        1,
        "Jazz",
        "1234567890",
        "IIT Hyderabad"
    );

    // Create truck
    Truck truck(1, 5);

    manager.addCustomer(&customer);
    manager.addTruck(&truck);

    // Create order items
    std::vector<OrderItem> items;
    items.emplace_back(*phone, 2);

    // Place order
    if (!manager.placeOrder(&customer, items))
    {
        std::cout << "Order placement failed.\n";
        return 0;
    }

    std::cout << "Order placed successfully!\n";

    // Get created order
    Order* order = customer.getOrders()[0];

    // Approve order
    manager.approveOrder(order);

    std::cout << "Order approved!\n";

    // Assign to truck
    manager.assignOrdersToTruck(&truck);

    std::cout << "Truck now has "
              << truck.getOrders().size()
              << " order(s).\n";

    // Print final status
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