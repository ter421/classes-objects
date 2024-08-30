#include <iostream>
#include <string>
using namespace std;

const int MaxBook = 100;

class Book 
{
private:
    string title;
    string author;
    int year;

public:
    Book(string YourTitle = "", string YourAuthor = "", int YourYear = 0) 
    {
        title = YourTitle;
        author = YourAuthor;
        year = YourYear;
    }


    void AboutBook() 
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }


    string Title() 
    {
        return title;
    }

    string Author()
    {
        return author;
    }

    int Year()
    {
        return year;
    }
};

class Library 
{
private:
    Book books[MaxBook];  
    int CountBook;

public:
    Library() : CountBook(0) {}

    void AddBook(string title, string author, int year) 
    {
        if (CountBook < MaxBook) 
        {
            books[CountBook] = Book(title, author, year);
            CountBook++;
            cout << "Your book has been added successfully!" << endl;
        } 
        
        else 
        {
            cout << "The Library is full, cannot add more books." << endl;
        }
    }

    void BooksDisplay() 
    {
        if (CountBook == 0) 
        {
            cout << "There are no books in the library." << endl;
            return;
        }

        else 
        {
        cout << "Title                        Author           Year" << endl;
            cout << "----------------------------------------------------" << endl;
            for (int i = 0; i < CountBook; i++) 
            {
                string title = books[i].Title();
                string author = books[i].Author();
                int year = books[i].Year();

                cout << title;
                for (int j = title.length(); j < 28; j++) cout << ' ';

                cout << author;
                for (int j = author.length(); j < 18; j++) cout << ' ';

                cout << year << endl;
            }
        }
    


        for (int i = 0; i < CountBook; i++)
        {
            books[i].AboutBook();
        }
    }

    void BookSearch(string title) 
    {
        for (int i = 0; i < CountBook; i++) 
        {
            if (books[i].Title() == title) 
            {
                cout << "Book has been found!" << endl;
                books[i].AboutBook();
                return;
            }
        }
        cout << "Book was not found!" << endl;
    }
};

int main() 
{
    Library lib;
    int choice;
    string title, author;
    int year;

    while (true) 
    {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            int year;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            Book NewBook(title, author, year);
            lib.AddBook(NewBook);
        } 
        
        else if (choice == 2) 
        {
            cout << "Book List:\n";
            lib.BooksDisplay();
        } 
        
        else if (choice == 3) 
        {
            string title;
            cout << "Enter a book to search: ";
            cin.ignore();
            getline(cin, title);
            lib.BookSearch(title);
        } 
        else if (choice == 4) 
        {
            break;
        } 
        
        else 
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}