#include "User.h"
#include <iostream>

// Adds a product to the user's cart if it's in stock
void User::addToCart(int productId, int stock) {
    if (stock > 0) {
        cart[productId]++; // Increment quantity in cart
        std::cout << "Added to cart.\n";
    }
    else {
        std::cout << "Out of stock!\n";
    }
}

// Removes one quantity of a product from the user's cart
void User::removeFromCart(int productId) {
    if (cart.count(productId)) { // Check if product exists in cart
        cart[productId]--; // Decrease quantity
        if (cart[productId] == 0)
            cart.erase(productId); // Remove if quantity reaches zero
        std::cout << "Removed from cart.\n";
    }
    else {
        std::cout << "Not in cart.\n";
    }
}

// Adds a product to the user's wishlist
void User::addToWishlist(int productId) {
    wishlist[productId]++; // Increment quantity in wishlist
    std::cout << "Added to wishlist.\n";
}

// Removes a product entirely from the user's wishlist
void User::removeFromWishlist(int productId) {
    if (wishlist.count(productId)) {
        wishlist.erase(productId); // Remove product from wishlist
        std::cout << "Removed from wishlist.\n";
    }
    else {
        std::cout << "Not in wishlist.\n";
    }
}

// Moves a product from wishlist to cart if it exists in wishlist
void User::moveToCart(int productId, int stock) {
    if (wishlist.count(productId)) {
        addToCart(productId, stock); // Try adding to cart
        wishlist.erase(productId); // Remove from wishlist
        std::cout << "Moved to cart.\n";
    }
    else {
        std::cout << "Not in wishlist.\n";
    }
}

// Displays the current items in the user's cart
void User::viewCart(ECommerceSystem& system) {
    std::cout << "\n--- Your Cart ---\n";
    for (const auto& item : cart) {
        Product* product = system.getProduct(item.first); // Get product details
        if (product) {
            std::cout << product->name << " | $" << product->price
                << " | Qty: " << item.second << "\n";
        }
    }
}

// Displays the current items in the user's wishlist
void User::viewWishlist(ECommerceSystem& system) {
    std::cout << "\n--- Your Wishlist ---\n";
    for (const auto& item : wishlist) {
        Product* product = system.getProduct(item.first); // Get product details
        if (product) {
            std::cout << product->name << " | $" << product->price << "\n";
        }
    }
}

// Calculates the total value of items in the cart
double User::getTotalCartValue(ECommerceSystem& system) {
    double total = 0.0;
    for (const auto& item : cart) {
        Product* product = system.getProduct(item.first); // Get product
        if (product)
            total += product->price * item.second; // Add product total
    }
    return total;
}

// Purchases a product from the cart if enough stock is available
void User::purchaseProduct(int productId, ECommerceSystem& system) {
    if (cart.count(productId)) {
        Product* product = system.getProduct(productId); // Get product details
        if (product && product->stock >= cart[productId]) {
            product->stock -= cart[productId]; // Reduce stock
            purchaseStack.push(productId); // Track in stack (for undo perhaps)
            orderHistory.push(productId); // Add to order history
            cart.erase(productId); // Remove from cart after purchase
            std::cout << "Purchase successful for: " << product->name << "\n";
        }
        else {
            std::cout << "Not enough stock to complete the purchase.\n";
        }
    }
    else {
        std::cout << "Product not found in cart.\n";
    }
}

// Displays the order history (FIFO)
void User::viewOrderHistory() {
    std::cout << "\n--- Order History ---\n";
    std::queue<int> tempQueue = orderHistory; // Create a copy to preserve the original
    while (!tempQueue.empty()) {
        std::cout << "Product ID: " << tempQueue.front() << "\n";
        tempQueue.pop(); // Move to next
    }
}
