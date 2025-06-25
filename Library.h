#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook();
    bool removeBook(int bookId);
    Book* searchBookByTitle(const std::string& title);
    void registerUser();
    void listUsers() const;
    void listBooks() const;
    void borrowBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
};

#endif //LIBRARY_H
