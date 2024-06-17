#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "Transaction.h"

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string location;
    bool available;
    std::vector<Transaction> transactions;

public:
    // Constructor
    Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& location);

    // Getters
    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getLocation() const;
    bool isAvailable() const;

    // Setters
    void setAvailable(bool available);

    // Add a transaction
    void addTransaction(const Transaction& transaction);
};

#endif // BOOK_H
