#ifndef ECOMMERCE_SYSTEM_H
#define ECOMMERCE_SYSTEM_H

#include <vector>
#include "Product.h"

// Represents the core system managing products in the e-commerce application
class ECommerceSystem {
private:
    std::vector<Product> products;  // List of available products

public:
    // Adds a new product to the system
    void addProduct(int id, std::string name, double price, int stock);

    // Displays all available products
    void displayProducts();

    // Retrieves a pointer to a product by ID (returns nullptr if not found)
    Product* getProduct(int id);
};

#endif // ECOMMERCE_SYSTEM_H
