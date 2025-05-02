#include "Book.h"
#include <iomanip>
#include <string>

Book::Book() : bookId(0), price(0), stock(0), issuedBooks(0) {
    strcpy(name, "");
    strcpy(author, "");
    strcpy(category, "");
    strcpy(rating, "");
}

Book::Book(int id, const char* name, const char* author, int price, const char* category, const char* rating, int stock, int issuedBooks)
    : bookId(id), price(price), stock(stock), issuedBooks(issuedBooks) {
    strcpy(this->name, name);
    strcpy(this->author, author);
    strcpy(this->category, category);
    strcpy(this->rating, rating);
}

int Book::getBookId() const { return bookId; }
const char* Book::getName() const { return name; }
const char* Book::getAuthor() const { return author; }
int Book::getPrice() const { return price; }
const char* Book::getCategory() const { return category; }
const char* Book::getRating() const { return rating; }
int Book::getStock() const { return stock; }
int Book::getIssuedBooks() const { return issuedBooks; }

void Book::setPrice(int price) { this->price = price; }
void Book::setRating(const char* rating) { strcpy(this->rating, rating); }
void Book::setStock(int stock) { this->stock = stock; }
void Book::setIssuedBooks(int issuedBooks) { this->issuedBooks = issuedBooks; }

ostream& operator<<(ostream& out, const Book& book) {

    out << "\nBook ID      : " << book.bookId << "\n"
        << "Book Name    : " << book.name << "\n"
        << "Author       : " << book.author << "\n"
        << "Category     : " << book.category << "\n"
        << "Price        : $" << fixed << setprecision(2) << book.price << "\n"
        << "Rating       : " << fixed << setprecision(1) << book.rating << "\n";
       out <<"---------------------\n";
    return out;
}



istream& operator>>(istream& in, Book& book) {

    cout << "\nEnter Book ID: ";
    in >> book.bookId;
    in.ignore();

    cout << "Enter Name: ";
    in.getline(book.name, 20);

    cout << "Enter Author: ";
    in.getline(book.author, 25);

    cout << "Enter Price: ";
    in >> book.price;
    in.ignore();

    cout << "Enter Category: ";
    in.getline(book.category, 27);

    cout << "Enter Rating: ";
    in.getline(book.rating, 29);

    cout << "Enter Stock: ";
    in >> book.stock;

    cout << "Enter Issued Books: ";
    in >> book.issuedBooks;

    return in;
}
