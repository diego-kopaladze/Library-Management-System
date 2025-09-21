#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "../Book/Book.h"
#include "../User/User.h"

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
    //Updated code
    void checkBookQuantity(std::vector<Book> books);
    std::vector<Book> returnBooks();
    std::vector<User> returnUsers();
    bool checkBookQuantity();
    bool checkUserQuantity();

};

#endif //LIBRARY_H
