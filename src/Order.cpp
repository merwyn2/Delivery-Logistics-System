#include "Order.h"
#include "Customer.h"

Order::Order(int id,
             Customer* customer,
             const std::vector<OrderItem>& items,
             const std::string& deliveryAddress)
    : orderID(id),
      customer(customer),
      items(items),
      deliveryAddress(deliveryAddress),
      status(Status::Pending)
{
}

int Order::getOrderID() const
{
    return orderID;
}

Customer* Order::getCustomer() const
{
    return customer;
}

const std::vector<OrderItem>& Order::getItems() const
{
    return items;
}

std::string Order::getDeliveryAddress() const
{
    return deliveryAddress;
}

Status Order::getStatus() const
{
    return status;
}

void Order::setStatus(Status status)
{
    this->status = status;
}