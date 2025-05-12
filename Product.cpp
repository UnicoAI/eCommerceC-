#include "Product.h"

// Constructor: Initializes a product with given ID, name, price, and stock
Product::Product(int id, std::string name, double price, int stock)
    : id(id), name(name), price(price), stock(stock) {}

// Displays the product's details to the console
void Product::display() {
    std::cout << "ID: " << id << " | " << name << " | $" << price
        << " | Stock: " << stock << std::endl;
}
