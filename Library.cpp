#include "Library.h"
#include <iostream>  // For generating reports
#include <algorithm> // For std::remove

// Book management
void Library::addBook(const Book& book) {
    books.push_back(book);
}

Book* Library::findBookByISBN(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

std::vector<Book> Library::searchBooksByTitle(const std::string& title) {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> Library::searchBooksByAuthor(const std::string& author) {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            result.push_back(book);
        }
    }
    return result;
}

// User management
void Library::registerUser(const User& user) {
    users.push_back(user);
}

User* Library::findUserById(const std::string& userId) {
    for (auto& user : users) {
        if (user.getUserId() == userId) {
            return &user;
        }
    }
    return nullptr;
}

// Transaction management
void Library::borrowBook(const std::string& userId, const std::string& isbn, const std::string& borrowDate) {
    User* user = findUserById(userId);
    Book* book = findBookByISBN(isbn);

    if (user && book && book->isAvailable()) {
        Transaction transaction(userId, isbn, borrowDate);
        transactions.push_back(transaction);
        user->borrowBook(*book);
        book->addTransaction(transaction);
    }
}

void Library::returnBook(const std::string& userId, const std::string& isbn, const std::string& returnDate) {
    User* user = findUserById(userId);
    Book* book = findBookByISBN(isbn);

    if (user && book && user->hasBorrowedBook(isbn)) {
        for (auto& transaction : transactions) {
            if (transaction.getUserId() == userId && transaction.getISBN() == isbn && transaction.getReturnDate().empty()) {
                transaction.setReturnDate(returnDate);
                break;
            }
        }
        user->returnBook(isbn);
        book->setAvailable(true);
    }
}

void Library::generateReport() {
    std::cout << "Library Report:" << std::endl;
    std::cout << "Total Books: " << books.size() << std::endl;
    std::cout << "Total Users: " << users.size() << std::endl;
    std::cout << "Total Transactions: " << transactions.size() << std::endl;

    std::cout << "\nBooks:" << std::endl;
    for (const auto& book : books) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << std::endl;
    }

    std::cout << "\nUsers:" << std::endl;
    for (const auto& user : users) {
        std::cout << "User ID: " << user.getUserId() << ", Name: " << user.getName() << std::endl;
    }

    std::cout << "\nTransactions:" << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << "User ID: " << transaction.getUserId() << ", ISBN: " << transaction.getISBN() << ", Borrow Date: " << transaction.getBorrowDate() << ", Return Date: " << (transaction.getReturnDate().empty() ? "Not returned yet" : transaction.getReturnDate()) << std::endl;
    }
}
