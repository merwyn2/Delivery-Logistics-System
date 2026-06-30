# Delivery Logistics System

A console-based logistics management system built in **C++** to learn and apply Object-Oriented Programming (OOP) concepts. The project simulates the workflow of managing products, customers, warehouse inventory, orders, and delivery trucks.

## Features

* Product management
* Warehouse inventory management
* Customer registration
* Order creation
* Order approval
* Truck assignment
* Order status tracking

## Project Structure

```
DeliveryLogistics/
│
├── include/        # Header files
├── src/            # Source files
├── data/           # Reserved for future persistent storage
└── README.md
```

## Classes

| Class           | Responsibility                                                  |
| --------------- | --------------------------------------------------------------- |
| Product         | Stores product information                                      |
| OrderItem       | Represents a product and quantity inside an order               |
| Customer        | Stores customer details and order history                       |
| Order           | Represents a customer's order and its status                    |
| Warehouse       | Manages inventory and stock operations                          |
| Truck           | Stores approved orders assigned for delivery                    |
| DeliveryManager | Coordinates warehouse operations, orders, and truck assignments |

## Workflow

```
Create Product
        ↓
Add Stock
        ↓
Register Customer
        ↓
Place Order
        ↓
Approve Order
        ↓
Assign to Truck
        ↓
Update Order Status
```

## OOP Concepts Used

* Classes and Objects
* Encapsulation
* Composition
* Aggregation
* Constructors
* Initializer Lists
* Forward Declarations
* Const Correctness
* STL Containers (`std::vector`, `std::unordered_map`)
* Multi-file Project Structure

## Technologies

- C++17
- Standard Template Library (STL)
- GCC (g++)
- Git & GitHub
- Linux Mint
- Visual Studio Code

## Build

Compile using:

```bash
g++ -Iinclude \
src/main.cpp \
src/Product.cpp \
src/OrderItem.cpp \
src/Customer.cpp \
src/Order.cpp \
src/Warehouse.cpp \
src/Truck.cpp \
src/DeliveryManager.cpp \
-o logistics
```

Run:

```bash
./logistics
```

## Future Improvements

* Persistent storage using file handling
* Interactive command-line interface
* Multiple warehouses
* Delivery personnel management
* Product catalog
* Smart pointers (`std::unique_ptr`)
* File serialization
* CMake build support

## Author

**Merwyn Kumar Kollabathula**

---

This project was developed as a learning exercise to build a strong foundation in modern C++ and Object-Oriented Programming by designing and implementing a complete logistics management system from scratch.
