#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string userId;
    std::string isbn;
    std::string borrowDate;
    std::string returnDate;
    double fineAmount;

public:
    // Constructor
    Transaction(const std::string& userId, const std::string& isbn, const std::string& borrowDate);

    // Getters
    std::string getUserId() const;
    std::string getISBN() const;
    std::string getBorrowDate() const;
    std::string getReturnDate() const;
    double getFineAmount() const;

    // Setters
    void setReturnDate(const std::string& returnDate);
    void setFineAmount(double fineAmount);
};

#endif // TRANSACTION_H
