#include "Book.h"

// Constructor
Book::Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& location)
    : isbn(isbn), title(title), author(author), location(location), available(true) {}

// Getters
std::string Book::getISBN() const {
    return isbn;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getLocation() const {
    return location;
}

bool Book::isAvailable() const {
    return available;
}

// Setters
void Book::setAvailable(bool available) {
    this->available = available;
}

// Add a transaction
void Book::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}
