📚 Library Management System (C++)

A console-based application developed in C++ to simulate a simple library management system using Object-Oriented Programming (OOP) principles.

Features
- Add new books to the library
- Prevent duplicate Book IDs
- Display all books
- Issue books
- Return books
- Search books by:
  - ID
  - Title
  - Author
- Shows book availability status (Issued / Available)

Technologies Used
- C++ Programming Language
- Object-Oriented Programming (OOP)
  - Classes and Objects
  - Encapsulation
- Standard Template Library (STL)
  - vector (dynamic array)
  - string (text handling)

How It Works
- Books are stored inside a vector container
- Each book is represented as an object of the Book class
- Users interact through a menu-driven system
- Searching is performed using linear search and string matching

How to Run

Compile:
```bash
g++ library_management_system.cpp -o library
```

Run:
```bash
./library
```

Author  
Rahul Kumar
