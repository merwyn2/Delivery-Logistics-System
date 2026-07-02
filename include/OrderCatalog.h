#pragma once

#include <unordered_map>

#include "Order.h"
#include "CustomerCatalog.h"
#include "ProductCatalog.h"

class OrderCatalog
{
private:
    std::unordered_map<int, Order*> orders;

    CustomerCatalog* customerCatalog;
    ProductCatalog* productCatalog;

    void saveOrders() const;
    void loadOrders();

public:
    OrderCatalog(CustomerCatalog* customers,
                 ProductCatalog* products);

    ~OrderCatalog();

    void addOrder(Order* order);

    Order* getOrder(int orderID);
};