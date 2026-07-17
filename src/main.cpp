#include <iostream>
#include <vector>

#include "DeliveryManager.h"
#include "Truck.h"
#include "OrderItem.h"
#include "OrderUtils.h"

using namespace std;

void printMenu()
{
    cout << "\n========== DELIVERY LOGISTICS ==========\n";
    cout << "1. Register Customer\n";
    cout << "2. Add Product & Stock\n";
    cout << "3. Place Order\n";
    cout << "4. Approve Order\n";
    cout << "5. Assign Orders To Truck\n";
    cout << "6. Complete Delivery\n";
    cout << "7. View Order\n";
    cout << "8. View Warehouse\n";
    cout << "0. Exit\n";
    cout << "Choice : ";
}

int main()
{
    DeliveryManager manager(1);
    Truck truck(1,10);

    manager.addTruck(&truck);

    int choice;

    while(true)
    {
        printMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
            {   
                int customerID;
                string name;
                string contact;
                string address;

                cout << "Customer ID : ";
                cin >> customerID;
                cin.ignore();

                cout << "Customer Name : ";
                getline(cin,name);

                cout << "Contact : ";
                getline(cin,contact);

                cout << "Address : ";
                getline(cin,address);

                manager.registerCustomer(customerID,name,contact,address);

                cout << "Customer Registered!\n";
                break;
            }

            case 2:
            {
                int id;
                string name;
                string brand;
                int quantity;

                cout << "Product ID : ";
                cin >> id;

                cin.ignore();

                cout << "Product Name : ";
                getline(cin,name);

                cout << "Brand : ";
                getline(cin,brand);

                cout << "Quantity : ";
                cin >> quantity;

                Product product(id,name,brand);

                manager.addStock(product,quantity);

                cout << "Stock Updated!\n";

                break;
            }

            case 3:
                {
                    int customerID;

                    cout << "Customer ID : ";
                    cin >> customerID;

                    Customer* customer = manager.getCustomer(customerID);

                    if(customer == nullptr)
                    {
                        cout << "Customer not found!\n";
                        break;
                    }

                    vector<OrderItem> items;

                    int n;
                    cout << "Number of different products : ";
                    cin >> n;

                    for(int i = 0; i < n; i++)
                    {
                        int productID;
                        int quantity;

                        cout << "\nProduct " << i + 1 << '\n';

                        cout << "Product ID : ";
                        cin >> productID;

                        Product* product = manager.getProduct(productID);

                        if(product == nullptr)
                        {
                            cout << "Invalid Product ID!\n";
                            i--;
                            continue;
                        }

                        cout << "Quantity : ";
                        cin >> quantity;

                        items.emplace_back(*product, quantity);
                    }

                    Order* order = manager.placeOrder(customer, items);

                    if(order == nullptr)
                    {
                        cout << "\nOrder could not be placed.\n";
                        cout << "Reason: One or more products are out of stock.\n";
                    }
                    else
                    {
                        cout << "\nOrder placed successfully!\n";
                        cout << "Order ID : " << order->getOrderID() << '\n';
                    }

                    break;
                }

            case 4:
            {
                int orderID;

                cout << "Order ID : ";
                cin >> orderID;

                Order* order = manager.getOrder(orderID);

                if(order == nullptr)
                {
                    cout << "Order not found!\n";
                    break;
                }

                manager.approveOrder(order);

                cout << "Order Approved!\n";

                break;
            }

            case 5:
            {
                manager.assignOrdersToTruck(&truck);

                cout << "Approved orders assigned to truck!\n";

                break;
            }

            case 6:
            {
                int orderID;

                cout << "Order ID : ";
                cin >> orderID;

                if(manager.completeDelivery(orderID))
                    cout << "Delivery Completed!\n";
                else
                    cout << "Order not found in truck!\n";

                break;
            }

            case 7:
            {
                int orderID;

                cout << "Order ID : ";
                cin >> orderID;

                Order* order = manager.getOrder(orderID);

                if(order == nullptr)
                {
                    cout << "Order not found!\n";
                    break;
                }

                cout << "\n========== ORDER DETAILS ==========\n";
                cout << "Order ID : " << order->getOrderID() << '\n';
                cout << "Customer : " << order->getCustomer()->getName() << '\n';
                cout << "Address : " << order->getDeliveryAddress() << '\n';
                cout << "Status : " << statusToString(order->getStatus()) << "\n\n";

                cout << "Items\n";

                for(const auto& item : order->getItems())
                {
                    cout << item.getProduct().getName()
                        << " x " << item.getQuantity() << '\n';
                }

                cout << "===================================\n";

                break;
            }

            case 8:
            {
                cout << "\n========== WAREHOUSE ==========\n";

                const auto& stock = manager.getWarehouse().getStockMap();

                if(stock.empty())
                {
                    cout << "Warehouse is empty.\n";
                    break;
                }

                for(const auto& entry : stock)
                {
                    Product* product = manager.getProduct(entry.first);

                    if(product)
                    {
                        cout << "ID : " << product->getProductID()
                            << " | "
                            << product->getName()
                            << " | "
                            << product->getBrand()
                            << " | Qty : "
                            << entry.second
                            << '\n';
                    }
                }

                cout << "===============================\n";

                break;
            }

            case 0:
            {
                cout << "Goodbye!\n";
                return 0;
            }

            default:
            {
                cout << "Invalid Choice!\n";
            }
        }
    }
}