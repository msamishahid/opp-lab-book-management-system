#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to represent individual books
class Book {
public:
    string title;
    string author;
    string genre;

    Book(string title, string author, string genre) : title(title), author(author), genre(genre) {}
};

// BookManager class to manage the collection of books
class BookManager {
private:
    vector<Book> books;

public:
    // Add a new book to the collection
    void addBook(string title, string author, string genre) {
        Book book(title, author, genre);
        books.push_back(book);
        cout << "Book '" << title << "' added successfully." << endl;
    }

    // Remove a book from the collection
    void removeBook(string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book '" << title << "' removed successfully." << endl;
                return;
            }
        }
        cout << "Book '" << title << "' not found." << endl;
    }

    // List all books in the collection
    void listBooks() {
        if (books.empty()) {
            cout << "No books available." << endl;
        }
        else {
            cout << "List of books:" << endl;
            int index = 1;
            for (const auto& book : books) {
                cout << index << ". " << book.title << " by " << book.author << " (" << book.genre << ")" << endl;
                index++;
            }
        }
    }
};

int main() {
    BookManager bookManager;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. List All Books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        string title, author, genre;

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            cin.ignore(); // Clear input buffer
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book genre: ";
            getline(cin, genre);
            bookManager.addBook(title, author, genre);
            break;
        case 2:
            cout << "Enter title of the book to remove: ";
            cin.ignore(); // Clear input buffer
            getline(cin, title);
            bookManager.removeBook(title);
            break;
        case 3:
            bookManager.listBooks();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

