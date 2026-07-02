#include <iostream>

#include "DeliveryManager.h"
#include "OrderItem.h"
#include "OrderUtils.h"

int main()
{
    DeliveryManager manager(1);

    Order* order = manager.getOrder(1);

    if (order == nullptr)
    {
        std::cout << "FAILED\n";
        return 0;
    }

    std::cout << "Order ID : "
              << order->getOrderID()
              << '\n';

    std::cout << "Customer : "
              << order->getCustomer()->getName()
              << '\n';

    std::cout << "Address : "
              << order->getDeliveryAddress()
              << '\n';

    std::cout << "Status : "
              << statusToString(order->getStatus())
              << '\n';

    std::cout << "\nItems\n";

    for (const OrderItem& item : order->getItems())
    {
        std::cout
            << item.getProduct().getName()
            << " x "
            << item.getQuantity()
            << '\n';
    }
}