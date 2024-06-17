#include "Transaction.h"

// Constructor
Transaction::Transaction(const std::string& userId, const std::string& isbn, const std::string& borrowDate)
    : userId(userId), isbn(isbn), borrowDate(borrowDate), returnDate(""), fineAmount(0.0) {}

// Getters
std::string Transaction::getUserId() const {
    return userId;
}

std::string Transaction::getISBN() const {
    return isbn;
}

std::string Transaction::getBorrowDate() const {
    return borrowDate;
}

std::string Transaction::getReturnDate() const {
    return returnDate;
}

double Transaction::getFineAmount() const {
    return fineAmount;
}

// Setters
void Transaction::setReturnDate(const std::string& returnDate) {
    this->returnDate = returnDate;
}

void Transaction::setFineAmount(double fineAmount) {
    this->fineAmount = fineAmount;
}
