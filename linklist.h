#pragma once
#include "node.h"
#include "book.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& other);
    void insertNode(const T& data);
    void displayAllBooks() const;
    void readfile(const char* file);
    void writefile(const char* file);
    void displaySpecificBook(int bookId) const;
    void searchBookById(int bookId) const;
    void searchBookByName(char* bookName) const;
    void showBooksByAuthor(char* author) const;
    void showBooksByCategory(char* category) const;
    void deleteBookById(int bookId);
    void updateBookDataByPrice(int bookId, int newPrice);
    void updateBookDataByRating(int bookId, char* newRating);
    void purchaseBook(int bookId, int quantity);
    void issueBook(int bookId, int quantity);
    void returnBook(int bookId, int quantity);
    void deleteAllBooks();
    void sortBooksByPrice()const;
    void sortBooksByRating()const ;
};



