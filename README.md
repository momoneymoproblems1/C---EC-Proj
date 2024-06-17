Library Management System
This project implements a simple Library Management System in C++, providing basic functionalities for managing books, users, and transactions within a library setting.

Features
Book Management:

---Add new books with details such as ISBN, title, author, and shelf location.

---Search books by title or author.

---Check availability and manage borrowing status.


User Management:
---Register new users with a unique ID and name.

---Manage borrowed books for each user, including borrowing and returning.

Transaction Management:

---Record transactions for each book borrowing, capturing user ID, book ISBN, borrow date, and return date.

Reports:

---Generate reports to view current book inventory, user details, and active transactions.

Requirements

---C++ compiler with C++11 support (e.g., g++ 4.8+)
Usage

Clone the repository:


---Copy code
git clone https://github.com/momoneymoproblems1/EC---EC-Proj.git


Compile the program:

---Copy code
g++ main.cpp Book.cpp User.cpp Transaction.cpp Library.cpp -o LibraryManagementSystem


Run the executable:

---Copy code
./LibraryManagementSystem


Follow the console prompts to interact with the Library Management System:

Add books, register users, borrow and return books.
Generate reports to view current library status.
Contributing
Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request.
