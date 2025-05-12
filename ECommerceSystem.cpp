#include "ECommerceSystem.h"

// Adds a product to the system
void ECommerceSystem::addProduct(int id, std::string name, double price, int stock) {
    products.emplace_back(id, name, price, stock);
}

// Displays all available products
void ECommerceSystem::displayProducts() {
    for (auto& product : products) {
        product.display();
    }
}

// Retrieves a pointer to a product by its ID
Product* ECommerceSystem::getProduct(int id) {
    for (auto& product : products) {
        if (product.id == id) {
            return &product;
        }
    }
    return nullptr; // Return null if product not found
}
