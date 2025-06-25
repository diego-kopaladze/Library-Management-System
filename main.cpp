#include <iostream>
#include "Library.h"

void showMenu() {
    std::cout << "\n--- Library Menu ---\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. List Books\n";
    std::cout << "3. Register User\n";
    std::cout << "4. List Users\n";
    std::cout << "5. Borrow Book\n";
    std::cout << "6. Return Book\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Library library;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();  // clear newline

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.listBooks();
                break;
            case 3:
                library.registerUser();
                break;
            case 4:
                library.listUsers();
                break;
            case 5: {
                int userId, bookId;
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                std::cout << "Enter Book ID: ";
                std::cin >> bookId;
                library.borrowBook(userId, bookId);
                break;
            }
            case 6: {
                int userId, bookId;
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                std::cout << "Enter Book ID: ";
                std::cin >> bookId;
                library.returnBook(userId, bookId);
                break;
            }
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}