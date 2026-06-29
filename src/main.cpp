#include <vector>

#include "Product.h"
#include "OrderItem.h"
#include "Customer.h"
#include "Order.h"
#include "Warehouse.h"

int main()
{
    // Create a product
    Product phone(1, "iPhone 16", "Apple");

    // Create an order item
    OrderItem item(phone, 2);

    // Create a customer
    Customer customer(
        1,
        "Jazz",
        "1234567890",
        "IIT Hyderabad"
    );

    // Create a list of order items
    std::vector<OrderItem> items;
    items.push_back(item);

    // Create an order
    Order order(
        1,
        &customer,
        items,
        customer.getAddress()
    );

    // Save order in customer's history
    customer.addOrder(&order);

    // Create warehouse
    Warehouse warehouse(1);

    // Add stock
    warehouse.addStock(phone, 20);

    // Check stock
    if (warehouse.hasStock(phone, 2))
    {
        warehouse.removeStock(phone, 2);
    }

    return 0;
}