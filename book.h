#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string.h>

using namespace std;

class Book {
private:
    int bookId;
    char name[20];
    char author[25];
    int price;
    char category[27];
    char rating[29];
    int stock;
    int issuedBooks;

public:
    Book();
    Book(int id, const char* name, const char* author, int price, const char* category, const char* rating, int stock, int issuedBooks);

    // Getters
    int getBookId() const;
    const char* getName() const;
    const char* getAuthor() const;
    int getPrice() const;
    const char* getCategory() const;
    const char* getRating() const;
    int getStock() const;
    int getIssuedBooks() const;

    // Setters
    void setPrice(int price);
    void setRating(const char* rating);
    void setStock(int stock);
    void setIssuedBooks(int issuedBooks);

    friend ostream& operator<<(ostream& out, const Book& book);
    friend istream& operator>>(istream& in, Book& book);
};

#endif
