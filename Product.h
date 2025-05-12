#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

// Represents a product in the e-commerce system
class Product {
public:
    int id;                 // Unique product ID
    std::string name;       // Product name
    double price;           // Product price
    int stock;              // Quantity available in stock

    // Constructor to initialize a product
    Product(int id, std::string name, double price, int stock);

    // Displays product details
    void display();
};

#endif // PRODUCT_H
