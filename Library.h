#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Transaction> transactions;

public:
    // Book management
    void addBook(const Book& book);
    Book* findBookByISBN(const std::string& isbn);
    std::vector<Book> searchBooksByTitle(const std::string& title);
    std::vector<Book> searchBooksByAuthor(const std::string& author);

    // User management
    void registerUser(const User& user);
    User* findUserById(const std::string& userId);

    // Transaction management
    void borrowBook(const std::string& userId, const std::string& isbn, const std::string& borrowDate);
    void returnBook(const std::string& userId, const std::string& isbn, const std::string& returnDate);
    void generateReport();
};

#endif // LIBRARY_H
