#include "ECommerceSystem.h"
#include "User.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>  // Windows-specific color handling
#else
#include <unistd.h>   // For Unix-based systems
#endif

// Function to set console text color based on platform
void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  // Windows API call
#else
    std::string colorCode = "\033[0m";
    if (color == 12) colorCode = "\033[31m"; // Red
    else if (color == 10) colorCode = "\033[32m"; // Green
    else if (color == 14) colorCode = "\033[33m"; // Yellow
    std::cout << colorCode;  // ANSI escape code for Unix
#endif
}

// Function to display the main menu with ASCII art and color formatting
void showMenu() {
    setColor(14);
    std::cout << "\n======================[ WELCOME TO MARIUS E-SHOP ]=====================\n";
    setColor(7);
    std::cout << "                        _________________________  \n";
    std::cout << "                       |                         | \n";
    std::cout << "                       |   E - C O M M E R C E   | \n";
    std::cout << "                       |_________________________| \n";
    setColor(14);
    std::cout << "-----------------------------------------------------------------------\n";
    setColor(7);
    std::cout << " 1.  [VIEW]      View Products\n";
    setColor(10);
    std::cout << " 2.  [+]         Add to Cart\n";
    setColor(12);
    std::cout << " 3.  [-]         Remove from Cart\n";
    setColor(14);
    std::cout << " 4.  [WISH]      Add to Wishlist\n";
    setColor(12);
    std::cout << " 5.  [X]         Remove from Wishlist\n";
    setColor(10);
    std::cout << " 6.  [MOVE->]    Move Wishlist to Cart\n";
    setColor(10);
    std::cout << " 7.  [CART]      View Cart\n";
    setColor(12);
    std::cout << " 8.  [LIST]      View Wishlist\n";
    setColor(14);
    std::cout << " 9.  [$]         Total Cart Value\n";
    setColor(10);
    std::cout << "10.  [BUY]       Purchase Products\n";
    setColor(14);
    std::cout << "11.  [HISTORY]   View Order History\n";
    setColor(4);
    std::cout << "12.  [EXIT]      Exit\n";
    setColor(14);
    std::cout << "------------------------------------------------------------------------\n";
    setColor(7);
    std::cout << ">>>>>>>>>>>>  [Terminal Command]  >>>>>>>>>>>>  Choose an option: ";
}

int main() {
    ECommerceSystem system; // Create an instance of the e-commerce system
    User user;              // Create a user

    // Add predefined products to the system's product catalog
    system.addProduct(1, "Laptop", 1200.50, 10);
    system.addProduct(2, "Phone", 799.99, 5);
    system.addProduct(3, "Headphones", 199.99, 15);

    int choice, productId;

    // Infinite loop for the main menu
    while (true) {
        showMenu();  // Display menu
        std::cin >> choice;  // Take user input

        switch (choice) {
        case 1:
            system.displayProducts();  // Show all products
            break;
        case 2:
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            user.addToCart(productId, system.getProduct(productId)->stock); // Add item to cart if stock available
            break;
        case 3:
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            user.removeFromCart(productId); // Remove item from cart
            break;
        case 4:
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            user.addToWishlist(productId); // Add item to wishlist
            break;
        case 5:
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            user.removeFromWishlist(productId); // Remove item from wishlist
            break;
        case 6:
            std::cout << "Enter product ID: ";
            std::cin >> productId;
            user.moveToCart(productId, system.getProduct(productId)->stock); // Move item from wishlist to cart
            break;
        case 7:
            user.viewCart(system); // Display cart contents
            break;
        case 8:
            user.viewWishlist(system); // Display wishlist contents
            break;
        case 9:
            std::cout << "[TOTAL] Cart Value: $" << user.getTotalCartValue(system) << "\n"; // Show total value of items in cart
            break;
        case 10:
            std::cout << "Enter product ID to purchase: ";
            std::cin >> productId;
            user.purchaseProduct(productId, system); // Purchase product if in cart and stock is sufficient
            break;
        case 11:
            user.viewOrderHistory(); // Display purchase history
            break;
        case 12:
            setColor(4);
            std::cout << "[EXIT] Thank you for shopping with us!\n"; // Exit message
            setColor(7);
            return 0; // Terminate the program
        default:
            setColor(12);
            std::cout << "[ERROR] Invalid choice! Please try again.\n"; // Handle invalid input
            setColor(7);
        }
    }
}
