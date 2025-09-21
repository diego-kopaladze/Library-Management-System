#include "Library.h"
#include <iostream>

void Library::addBook() {
    int id;
    std::string title, author;

    std::cout << "Enter ID of book (integer): ";
    while (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Enter an integer: ";
    }
    std::cin.ignore();

    std::cout << "Title of book: ";
    std::getline(std::cin, title);

    std::cout << "Author of book: ";
    std::getline(std::cin, author);

    Book book(id, title, author);
    books.push_back(book);

    std::cout << "Book \"" << title << "\" added successfully!\n";
}

bool Library::removeBook(int bookId) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getId() == bookId) {
            std::cout << "Book id: " << books[i].getId()
                      << ", title: " << books[i].getTitle()
                      << ", author: " << books[i].getAuthor()
                      << " removed successfully\n";
            books.erase(books.begin() + i);
            return true;
        }
    }
    std::cout << "Book ID not found.\n";
    return false;
}

Book* Library::searchBookByTitle(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            std::cout << "\"" << title << "\" was found.\n";
            return &book;
        }
    }
    std::cout << "\"" << title << "\" was not found.\n";
    return nullptr;
}

void Library::registerUser() {
    int idOfUser;
    std::string nameOfUser;

    std::cout << "Enter ID of user: ";
    while (!(std::cin >> idOfUser)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Enter an integer: ";
    }
    std::cin.ignore();

    std::cout << "Enter user's name: ";
    std::getline(std::cin, nameOfUser);

    User user(idOfUser, nameOfUser);
    users.push_back(user);

    std::cout << "\nUser registered successfully.\n";
}

void Library::listUsers() const {
    if (users.empty()) {
        std::cout << "No users registered.\n";
    } else {
        std::cout << "Listing users:\n";
        for (const auto& u : users) {
            std::cout << "ID: " << u.getId()
                      << ", Name: " << u.getName() << "\n";
        }
    }
}

void Library::listBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
    } else {
        std::cout << "Listing books:\n";
        for (const auto& b : books) {
            std::cout << "ID: " << b.getId()
                      << ", Title: " << b.getTitle()
                      << ", Author: " << b.getAuthor()
                      << " (Borrowed: " << (b.getIsBorrowed() ? "Yes" : "No") << ")\n";
        }
    }
}

void Library::borrowBook(int userId, int bookId) {
    User* foundUser = nullptr;
    for (auto& u : users) {
        if (u.getId() == userId) {
            foundUser = &u;
            break;
        }
    }
    if (!foundUser) {
        std::cout << "User not found.\n";
        return;
    }

    Book* foundBook = nullptr;
    for (auto& b : books) {
        if (b.getId() == bookId) {
            foundBook = &b;
            break;
        }
    }
    if (!foundBook) {
        std::cout << "Book not found.\n";
        return;
    }

    if (foundBook->getIsBorrowed()) {
        std::cout << "Book is already borrowed.\n";
        return;
    }

    foundUser->borrowBook(foundBook);
    std::cout << "Book borrowed successfully.\n";
}

void Library::returnBook(int userId, int bookId) {
    User* foundUser = nullptr;
    for (auto& u : users) {
        if (u.getId() == userId) {
            foundUser = &u;
            break;
        }
    }
    if (!foundUser) {
        std::cout << "User not found.\n";
        return;
    }

    Book* foundBook = nullptr;
    for (auto& b : books) {
        if (b.getId() == bookId) {
            foundBook = &b;
            break;
        }
    }
    if (!foundBook) {
        std::cout << "Book not found.\n";
        return;
    }

    if (!foundUser->hasBorrowedBook(bookId)) {
        std::cout << "This user did not borrow the book with ID " << bookId << ".\n";
        return;
    }

    foundUser->returnBook(bookId);
    foundBook->returnBook();

    std::cout << "Book returned successfully.\n";
}

bool Library::checkBookQuantity() {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return false;
    }
    return true;
}

bool Library::checkUserQuantity() {
    if (users.empty()) {
        std::cout << "No users in the library.\n";
        return false;
    }
    return true;
}

