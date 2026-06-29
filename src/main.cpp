// #include "Product.h"
// #include "OrderItem.h"

// int main(){
//     Product p(1, "iPhone 16", "Apple");
//     OrderItem item(p, 2);
    
//     return 0;
// }
#include "Product.h"
#include "OrderItem.h"
#include "Customer.h"
#include "Order.h"

int main()
{
    Product phone(1, "iPhone 16", "Apple");

    OrderItem item(phone, 2);

    Customer customer(
        1,
        "Jazz",
        "1234567890",
        "IIT Hyderabad"
    );

    std::vector<OrderItem> items;
    items.push_back(item);

    Order order(
        1,
        &customer,
        items,
        customer.getAddress()
    );

    return 0;
}