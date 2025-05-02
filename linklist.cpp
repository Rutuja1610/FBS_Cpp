#include "linklist.h"
#include <fstream>
#include <cstring>
#include <iomanip>

// Constructor
template <class  T>
LinkedList<T>::LinkedList() : head(nullptr) {}

// Destructor
template <class  T>
LinkedList<T>::~LinkedList() {
    deleteAllBooks();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr) {
    if (!other.head) return; 

    Node<T>* current = other.head;
    Node<T>** tail = &head; 

    while (current) {
        *tail = new Node<T>(current->data); 
        tail = &((*tail)->next);         
        current = current->next;
    }
}


// Insert a node
template <class  T>
void LinkedList<T>::insertNode(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

// Display all books
template <class  T>
void LinkedList<T>::displayAllBooks() const {
    Node<T>* current = head;
    if (!current) {
        cout << "No books in the list.\n";
        return;
    }
    while (current) {
        const T& book = current->data; // Use reference to avoid copies
        cout << book << endl;
        current = current->next;
       
    }
}

// Read books from a binary file
template <class  T>
void LinkedList<T>::readfile(const char* file) {
    ifstream infile(file, ios::binary);
    if (!infile) {
        cout << "Error: Could not open file for reading.\n";
        return;
    }
    T book;
    while (infile.read(reinterpret_cast<char*>(&book), sizeof(book))) {
        // Check if the book already exists before inserting
        bool exists = false;
        Node<T>* current = head;
        while (current) {
            if (current->data.getBookId() == book.getBookId()) {
                exists = true;
                break;
            }
            current = current->next;
        }
        if (!exists) {
            insertNode(book);
        }
    }
    cout << "Books loaded from file.\n";
    infile.close();
}


// Write books to a binary file
template <class  T>
void LinkedList<T>::writefile(const char* file) {
    ofstream outfile(file, ios::binary);
    if (!outfile) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }
    Node<T>* current = head;
    while (current) {
        outfile.write(reinterpret_cast<const char*>(&current->data), sizeof(current->data));
        current = current->next;
    }
     cout << "Books saved to file.\n";
    outfile.close();
}

// Display a specific book by ID
template < class T>
void LinkedList<T>::displaySpecificBook(int bookId) const {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            cout << current->data << endl;
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Search book by ID
template <class  T>
void LinkedList<T>::searchBookById(int bookId) const {
    displaySpecificBook(bookId);
}

// Search book by name
template <class  T>
void LinkedList<T>::searchBookByName(char* bookName) const {
    Node<T>* current = head;
    while (current) {
        if (strstr(current->data.getName(),bookName) == current->data.getName()) {
            cout << "Book with name " << bookName << " found.\n";
            cout << current->data << endl;
            return;
        }
        current = current->next;
    }
    cout << "Book with name " << bookName << " not found.\n";
}

// Show books by author
template <class  T>
void LinkedList<T>::showBooksByAuthor(char* author) const {
    Node<T>* current = head;
    bool found = false;
    while (current) {
        if (strstr(current->data.getAuthor(), author) == current->data.getAuthor()) {
        
            cout << current->data << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) cout << "No books found by author " << author << ".\n";
}

// Show books by category
template <class  T>
void LinkedList<T>::showBooksByCategory(char* category) const {
    Node<T>* current = head;
    bool found = false;
    while (current) {
        if (strstr(current->data.getCategory(), category) == current->data.getCategory()){
        
        
            cout << current->data << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) cout << "No books found in category " << category << ".\n";
}

// Delete book by ID
template <class  T>
void LinkedList<T>::deleteBookById(int bookId) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current) {
        if (current->data.getBookId() == bookId) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Book with ID " << bookId << " deleted.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Update book data by price
template <class  T>
void LinkedList<T>::updateBookDataByPrice(int bookId, int newPrice) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            current->data.setPrice(newPrice);
            cout << "Updated price for book ID " << bookId << ".\n";
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Update book data by rating
template <class  T>
void LinkedList<T>::updateBookDataByRating(int bookId, char* newRating) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            current->data.setRating(newRating);
            cout << "Updated rating for book ID " << bookId << ".\n";
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Purchase book
template <class  T>
void LinkedList<T>::purchaseBook(int bookId, int quantity) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            if (current->data.getStock() >= quantity) {
                current->data.setStock(current->data.getStock() - quantity);
                cout << "Purchased " << quantity << " copies of book ID " << bookId << ".\n";
            } else {
                cout << "Insufficient stock for book ID " << bookId << ".\n";
            }
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Issue book
template <class  T>
void LinkedList<T>::issueBook(int bookId, int quantity) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            if (current->data.getStock() >= quantity) {
                current->data.setStock(current->data.getStock() - quantity);
                current->data.setIssuedBooks(current->data.getIssuedBooks() + quantity);
                cout << "Issued " << quantity << " copies of book ID " << bookId << ".\n";
            } else {
                cout << "Insufficient stock to issue book ID " << bookId << ".\n";
            }
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Return book
template <class  T>
void LinkedList<T>::returnBook(int bookId, int quantity) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getBookId() == bookId) {
            current->data.setStock(current->data.getStock() + quantity);
            current->data.setIssuedBooks(current->data.getIssuedBooks() - quantity);
            cout << "Returned " << quantity << " copies of book ID " << bookId << ".\n";
            return;
        }
        current = current->next;
    }
    cout << "Book with ID " << bookId << " not found.\n";
}

// Delete all books
template <class  T>
void LinkedList<T>::deleteAllBooks() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// Sort books by price
template <class T>
void LinkedList<T>::sortBooksByPrice() const {
    LinkedList<T> copy(*this); 

    if (!copy.head || !copy.head->next) {
        cout << "No books to sort.\n";
        return;
    }

    for (Node<T>* i = copy.head; i; i = i->next) {
        for (Node<T>* j = i->next; j; j = j->next) {
            if (i->data.getPrice() > j->data.getPrice()) {
                T temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    cout << "Books sorted by price (temporary copy):\n";
    copy.displayAllBooks(); 
}


template <class T>
void LinkedList<T>::sortBooksByRating() const {
    LinkedList<T> copy(*this); // Use the copy constructor to create a copy

    if (!copy.head || !copy.head->next) {
        cout << "No books to sort.\n";
        return;
    }

    for (Node<T>* i = copy.head; i; i = i->next) {
        for (Node<T>* j = i->next; j; j = j->next) {
            if (strcmp(i->data.getRating(), j->data.getRating()) > 0) {
                T temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    cout << "Books sorted by rating (temporary copy):\n";
    copy.displayAllBooks(); 
}

