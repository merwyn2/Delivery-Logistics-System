#include <iostream>
#include <vector>

#include "Product.h"
#include "OrderItem.h"
#include "Customer.h"
#include "Order.h"
#include "Warehouse.h"
#include "Truck.h"
#include "DeliveryManager.h"

int main()
{
    // Create product
    Product phone(1, "iPhone 16", "Apple");

    // Create customer
    Customer customer(
        1,
        "Jazz",
        "1234567890",
        "IIT Hyderabad"
    );

    // Create manager and truck
    DeliveryManager manager(1);
    Truck truck(1, 5);

    manager.addCustomer(&customer);
    manager.addTruck(&truck);

    // Add stock to warehouse through manager
    // manager.addStock(phone, 20);*********S

    // Create order items
    std::vector<OrderItem> items;
    items.emplace_back(phone, 2);

    // Place order
    if (!manager.placeOrder(&customer, items))
    {
        std::cout << "Order placement failed.\n";
        return 0;
    }

    std::cout << "Order placed successfully!\n";

    // Get the created order
    Order* order = customer.getOrders()[0];

    // Approve it
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

    // return 0;
}
// #include <iostream>

// #include "Warehouse.h"
// #include "Product.h"

// int main()
// {
//     Product phone(1, "iPhone 16", "Apple");

//     Warehouse warehouse(1);

//     warehouse.addStock(phone, 20);

//     warehouse.saveStock();

//     Warehouse warehouse2(2);

//     warehouse2.loadStock();

//     std::cout << warehouse2.getStock(phone) << '\n';

//     return 0;
// }