#include <iostream>
#include "book.cpp"
#include "linklist.cpp"

using namespace std;

void displayMenu() {
    cout << "\n==== Book Management System ====\n";
    cout << "1. Add a Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Display Specific Book by ID\n";
    cout << "4. Search Book \n";
    cout << "5. Show Books by Author\n";
    cout << "6. Show Books by Category\n";
    cout << "7. Delete Book by ID\n";
    cout << "8. Update Book\n";
    cout << "8. Purchase Book\n";
    cout << "10. Issue Book\n";
    cout << "11. Return Book\n";
    cout << "12. Delete All Books\n";
    cout << "13. Sort Books \n";
    cout << "14. Exit\n";
    cout << "Enter your choice: "<<endl;
}

int main() {
    LinkedList<Book>books;
    const char* filename = "books.bin";
   books.readfile(filename);
    int choice, bookId, price, quantity;
    char name[20], author[25], category[27], rating[29];
    

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                cin >> newBook;
               books.insertNode(newBook);
                cout << "Book added successfully.\n";
                break;
            }
            case 2:
               books.displayAllBooks();
                break;
            case 3:
                 cout << "Enter Book ID to display: ";
                cin >> bookId;
               books.displaySpecificBook(bookId);
                
                break;
            case 4:
                int op;
    
                 cout <<"1.Search book by Id"<< endl;
                 cout <<"2.Search book by Name"<< endl;
                 cin>>op;
                if (op==1)
                {
                cout << "Enter Book ID to search: ";
                cin >> bookId;
               books.searchBookById(bookId);
                }
                else
                {
                cout << "Enter Book Name to search: ";
                cin.ignore();
                cin.getline(name, 20);
               books.searchBookByName(name);
                }
                break;
            case 5:
                cout << "Enter Author to search: ";
                cin.ignore();
                cin.getline(author, 25);
               books.showBooksByAuthor(author);
               
                break;
            case 6:
               cout << "Enter Category to search: ";
                cin.ignore();
                cin.getline(category, 27);
               books.showBooksByCategory(category);
               
                break;
            case 7:
                cout << "Enter Book ID to delete: ";
                cin >> bookId;
               books.deleteBookById(bookId);
                break;
    
            case 8:
              int choi;
              
              cout <<"1.Update book by Id"<< endl;
              cout <<"2.Update book by Price"<< endl;
              cin>>choi;
              if (choi==1)
              {
                cout << "Enter Book ID to update price: ";
                cin >> bookId;
                cout << "Enter new price: ";
                cin >> price;
               books.updateBookDataByPrice(bookId, price);
              }
              else
              {
                cout << "Enter Book ID to update rating: ";
                cin >> bookId;
                cout << "Enter new rating: ";
                cin.ignore();
                cin.getline(rating, 29);
               books.updateBookDataByRating(bookId, rating);
              }
                break;
            case 9:
               cout << "Enter Book ID to purchase: ";
                cin >> bookId;
                cout << "Enter quantity: ";
                cin >> quantity;
               books.purchaseBook(bookId, quantity);
                break;
            case 10:
             cout << "Enter Book ID to issue: ";
                cin >> bookId;
                cout << "Enter quantity: ";
                cin >> quantity;
               books.issueBook(bookId, quantity);
               break;
            case 11:
                cout << "Enter Book ID to return: ";
                cin >> bookId;
                cout << "Enter quantity: ";
                cin >> quantity;
               books.returnBook(bookId, quantity);
                break;
                break;
            case 12:
              books.deleteAllBooks();
                cout << "All books deleted.\n";
                break;
            case 13:
               int l;
               cout <<"1.Sort book by Price"<< endl;
              cout <<"2.Sort book by Rating"<< endl;
              cin>>l;
             
              if (l==1)
              {
               books.sortBooksByPrice();
              }
              else
              {
                 books.sortBooksByRating();
              }
                break;
            case 14:
                  cout << "Exiting program. Goodbye!\n";
                break;
             
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 19);
    books.writefile(filename);

    return 0;
}
