#include <iostream>
#include "Library.h"
#include "Book.h"
#include "User.h"
#include "Transaction.h"

int main() {
    // Creating a library object
    Library library;

    // Adding books to the library
    library.addBook(Book("9780316769488", "The Catcher in the Rye", "J.D. Salinger", "Shelf A1"));
    library.addBook(Book("9780451524935", "1984", "George Orwell", "Shelf B2"));

    // Registering users
    library.registerUser(User("user123", "John Doe"));
    library.registerUser(User("user456", "Jane Smith"));

    // Borrowing a book
    std::cout << "Borrowing 'The Catcher in the Rye' by user123." << std::endl;
    library.borrowBook("user123", "9780316769488", "2024-06-16"); // Update to pass std::string for dates

    // Generating a report
    std::cout << "\nLibrary Report after borrowing a book:" << std::endl;
    library.generateReport();

    // Returning a book
    std::cout << "\nReturning 'The Catcher in the Rye' by user123." << std::endl;
    library.returnBook("user123", "9780316769488", "2024-06-17"); // Update to pass std::string for dates

    // Generating a report after returning the book
    std::cout << "\nLibrary Report after returning a book:" << std::endl;
    library.generateReport();

    return 0;
}
