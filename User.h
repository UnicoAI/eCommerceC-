#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <stack>
#include <queue>
#include "ECommerceSystem.h"

// Represents a user interacting with the e-commerce system
class User {
private:
    std::unordered_map<int, int> cart;         // Maps product ID to quantity in the cart
    std::unordered_map<int, int> wishlist;     // Maps product ID to quantity in the wishlist
    std::stack<int> purchaseStack;             // Stack to store most recent purchases
    std::queue<int> orderHistory;              // Queue to track purchase history

public:
    // Add a product to the cart
    void addToCart(int productId, int stock);

    // Remove a product from the cart
    void removeFromCart(int productId);

    // Add a product to the wishlist
    void addToWishlist(int productId);

    // Remove a product from the wishlist
    void removeFromWishlist(int productId);

    // Move a product from wishlist to cart
    void moveToCart(int productId, int stock);

    // View contents of the cart
    void viewCart(ECommerceSystem& system);

    // View contents of the wishlist
    void viewWishlist(ECommerceSystem& system);

    // Calculate the total value of items in the cart
    double getTotalCartValue(ECommerceSystem& system);

    // Purchase a product from the cart
    void purchaseProduct(int productId, ECommerceSystem& system);

    // Display the order history
    void viewOrderHistory();
};

#endif // USER_H
