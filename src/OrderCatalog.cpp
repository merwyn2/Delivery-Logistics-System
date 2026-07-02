#include "OrderCatalog.h"

#include <fstream>

#include "OrderUtils.h"
#include "Customer.h"

OrderCatalog::OrderCatalog(CustomerCatalog* customers,
                           ProductCatalog* products)
    : customerCatalog(customers),
      productCatalog(products)
{
    loadOrders();
}

OrderCatalog::~OrderCatalog()
{
    for (auto& item : orders)
    {
        delete item.second;
    }
}

void OrderCatalog::addOrder(Order* order)
{
    auto it = orders.find(order->getOrderID());

    if (it == orders.end())
    {
        orders.insert({order->getOrderID(), order});
    }
    else
    {
        delete it->second;
        it->second = order;
    }

    saveOrders();
}

Order* OrderCatalog::getOrder(int orderID)
{
    auto it = orders.find(orderID);

    if (it == orders.end())
        return nullptr;

    return it->second;
}
void OrderCatalog::saveOrders() const
{
    std::ofstream ordersOut("data/orders.txt");
    std::ofstream itemsOut("data/orderItems.txt");

    for (const auto& pair : orders)
    {
        Order* order = pair.second;

        ordersOut
            << order->getOrderID() << ' '
            << order->getCustomer()->getCustomerID() << ' '
            << statusToString(order->getStatus()) << ' '
            << order->getDeliveryAddress()
            << '\n';

        for (const OrderItem& item : order->getItems())
        {
            itemsOut
                << order->getOrderID() << ' '
                << item.getProduct().getProductID() << ' '
                << item.getQuantity()
                << '\n';
        }
    }

    ordersOut.close();
    itemsOut.close();
}

void OrderCatalog::loadOrders()
{
    std::ifstream ordersIn("data/orders.txt");

    if (!ordersIn)
    {
        return;
    }

    for (auto& pair : orders)
    {
        delete pair.second;
    }

    orders.clear();

    int orderID;
    int customerID;
    std::string status;
    std::string address;

    while (ordersIn >> orderID
                    >> customerID
                    >> status
                    >> address)
    {
        Customer* customer = customerCatalog->getCustomer(customerID);

        if (customer == nullptr)
        {
            continue;
        }

        std::ifstream itemsIn("data/orderItems.txt");

        std::vector<OrderItem> items;

        int currentOrderID;
        int productID;
        int quantity;

        while (itemsIn >> currentOrderID
                       >> productID
                       >> quantity)
        {
            if (currentOrderID == orderID)
            {
                Product* product = productCatalog->getProduct(productID);

                if (product)
                {
                    items.emplace_back(*product, quantity);
                }
            }
        }

        Order* order = new Order(
            orderID,
            customer,
            items,
            address,
            stringToStatus(status));

        orders.insert({orderID, order});
    }
}