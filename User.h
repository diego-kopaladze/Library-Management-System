
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    int id;
    std::string name;
    std::vector<Book*> borrowedBooks;

public:
    User(int id, const std::string& name);

    void borrowBook(Book* book);
    void returnBook(int bookId);
    void viewBorrowedList() const;
    bool hasBorrowedBook(int bookId) const;

    int getId() const;
    std::string getName() const;
};

#endif //USER_H
