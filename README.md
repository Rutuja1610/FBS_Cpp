# FBS_Cpp
Java Full Stack Developer Training – FirstBit Solutions 
# 📚 Book Management System – C++ (Linked List Based)

This is a console-based application that allows users to manage books using a custom **Linked List** implementation in **C++**, built without using arrays. It supports real-time operations such as insertion, deletion, searching, sorting, issuing, and purchasing books. All data is dynamically stored in memory and can be saved to/retrieved from a binary file.

---

## 🚀 Features

- ✅ Add, view, and update books
- 🔍 Search books by ID, name, author, and category
- 🧾 Issue, return, and purchase books
- ❌ Delete books (by ID or all)
- 🔄 Sort books by price or rating
- 💾 Persistent storage via binary file (`books.bin`)
- 🔗 Uses custom templated Linked List class (`LinkedList<Book>`)

---

## 🛠 Tech Stack

- **Language:** C++
- **Data Structure:** Linked List (Singly or Doubly depending on your `linklist.cpp`)
- **File Handling:** Binary file (`books.bin`) using `fstream`
- **OOP Concepts:** Classes, Constructors, Operator Overloading, Templates

---

## 📂 Project Structure

**/book-management/**
- **main.cpp # Main menu logic and user interaction**
- **book.cpp # Book class implementation (with operator overloading)**
- **linklist.cpp # Templated LinkedList class for book storage**
- **books.bin # Binary file for persistent storage (auto-generated)**
- **node.cpp # For Node**
- **linklist.h # for headers in linklist.cpp**
  
