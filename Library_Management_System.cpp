#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title, author, ISBN;
    bool isAvailable = true;
};

struct Borrower {
    string name;
    vector<string> borrowedBooks;
};

vector<Book> books;
vector<Borrower> borrowers;

// Function to add a new book
void addBook() {
    Book newBook;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter Author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.ISBN);
    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Function to search for books
void searchBook() {
    string keyword;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "\nSearch Results:\n";
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || 
            book.author.find(keyword) != string::npos || 
            book.ISBN.find(keyword) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author 
                 << ", ISBN: " << book.ISBN 
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
}

// Function to check out a book
void checkoutBook() {
    string borrowerName, bookTitle;
    cout << "Enter Borrower Name: ";
    cin.ignore();
    getline(cin, borrowerName);

    cout << "Enter Book Title to Checkout: ";
    getline(cin, bookTitle);

    for (auto& book : books) {
        if (book.title == bookTitle && book.isAvailable) {
            book.isAvailable = false;
            borrowers.push_back({borrowerName, {bookTitle}});
            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book not available or not found.\n";
}

// Function to return a book
void returnBook() {
    string bookTitle;
    cout << "Enter Book Title to Return: ";
    cin.ignore();
    getline(cin, bookTitle);

    for (auto& book : books) {
        if (book.title == bookTitle && !book.isAvailable) {
            book.isAvailable = true;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found in borrowed records.\n";
}

// Function to display all books
void displayBooks() {
    cout << "\nLibrary Books:\n";
    for (const auto& book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author 
             << ", ISBN: " << book.ISBN 
             << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
    }
}

// Main function
int main() {
    int choice;
    while (true) {
        cout << "\nLibrary Management System:\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: checkoutBook(); break;
            case 4: returnBook(); break;
            case 5: displayBooks(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
