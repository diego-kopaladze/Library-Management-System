#include "User.h"
#include <iostream>

User::User(int id, const std::string& name)
    : id{id}, name{name} {}

void User::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
    book->borrowBook();
}

void User::returnBook(int bookId) {
    for (size_t i = 0; i < borrowedBooks.size(); ++i) {
        if (borrowedBooks[i]->getId() == bookId) {
            borrowedBooks[i]->returnBook();
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}

void User::viewBorrowedList() const {
    std::cout << "\nBorrowed books:\n";
    for (const auto& bookPtr : borrowedBooks) {
        std::cout << '"' << bookPtr->getTitle() << "\" by "
                  << bookPtr->getAuthor() << " (ID: " << bookPtr->getId() << ")\n";
    }
}

bool User::hasBorrowedBook(int bookId) const {
    for (const auto& book : borrowedBooks) {
        if (book->getId() == bookId) return true;
    }
    return false;
}

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}