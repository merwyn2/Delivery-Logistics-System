#pragma once

#include <vector>

#include "Warehouse.h"
#include "Customer.h"
#include "Order.h"
#include "ProductCatalog.h"
#include "CustomerCatalog.h"
#include "OrderCatalog.h"

class Truck;

class DeliveryManager
{
private:
    Warehouse warehouse;
    std::vector<Order*> orders;
    std::vector<Truck*> trucks;

    ProductCatalog catalog;
    CustomerCatalog customerCatalog;
    OrderCatalog orderCatalog;

public:
    DeliveryManager(int warehouseID);
    Product* getProduct(int productID);
    void addStock(const Product& product, int quantity);
    void addCustomer(Customer* customer);
    void addTruck(Truck* truck);

    bool placeOrder(Customer* customer,
                    const std::vector<OrderItem>& items);

    void approveOrder(Order* order);

    Customer* getCustomer(int customerID);

    void assignOrdersToTruck(Truck* truck);

    void registerCustomer(int id,
                      const std::string& name,
                      const std::string& contact,
                      const std::string& address);
    
    Order* getOrder(int orderID);      
                
    bool completeDelivery(int orderID);
};