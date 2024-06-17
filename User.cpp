#include "User.h"
#include <algorithm> // For std::remove and std::find

// Constructor
User::User(const std::string& userId, const std::string& name) : userId(userId), name(name) {}

// Getters
std::string User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

// Borrow and return books
void User::borrowBook(Book& book) {
    borrowedBooks.push_back(book.getISBN());
    book.setAvailable(false);
}

void User::returnBook(const std::string& isbn) {
    auto it = std::remove(borrowedBooks.begin(), borrowedBooks.end(), isbn);
    borrowedBooks.erase(it, borrowedBooks.end());
}

bool User::hasBorrowedBook(const std::string& isbn) const {
    return std::find(borrowedBooks.begin(), borrowedBooks.end(), isbn) != borrowedBooks.end();
}
