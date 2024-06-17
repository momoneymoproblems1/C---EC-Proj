#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    std::string userId;
    std::string name;
    std::vector<std::string> borrowedBooks;

public:
    // Constructor
    User(const std::string& userId, const std::string& name);

    // Getters
    std::string getUserId() const;
    std::string getName() const;

    // Borrow and return books
    void borrowBook(Book& book);
    void returnBook(const std::string& isbn);
    bool hasBorrowedBook(const std::string& isbn) const;
};

#endif // USER_H
