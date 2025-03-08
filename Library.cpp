#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Librarian.cpp"
// #include "Student.cpp"
// #include "Faculty.cpp"
// #include "Book.cpp"
// #include "Accounts.cpp"
Library::Library()
{
    vector<vector<string>> data = readBookCSV("./Database/Library.csv");
    vector<Book *> books;
    if (data.size() == 0)
        return;
    for (int i = 0; i < data.size(); i++)
    {
        Book *book = new Book(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5], data[i][6]);
        books.push_back(book);
    }
    this->books = books;
}
Library::~Library()
{
    vector<vector<string>> data;
    for (int i = 0; i < books.size(); i++)
    {
        vector<string> row;
        row.push_back(books[i]->getTitle());
        row.push_back(books[i]->getAuthor());
        row.push_back(books[i]->getPublisher());
        row.push_back(books[i]->getISBN());
        row.push_back(books[i]->getYear());
        row.push_back(books[i]->getOwner());
        row.push_back(books[i]->getBorrDate());
        data.push_back(row);
    }
    writeBookCSV("./Database/Library.csv", data);
}
Book *Library::searchBook(string ISBN)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getISBN() == ISBN)
        {
            return books[i];
        }
    }
    return NULL;
}
void Library::addBook(Book *book)
{
    if (searchBook(book->getISBN()) != NULL)
    {
        cout << (book->getTitle()) << " already exists" << endl;
        return;
    }
    books.push_back(book);
    cout << (book->getTitle()) << " added successfully" << endl;
}
void Library::removeBook(string ISBN)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getISBN() == ISBN)
        {
            if (books[i]->getOwner() != "")
            {
                cout << "Book is borrowed. Cannot remove book!" << endl;
                return;
            }
            books.erase(books.begin() + i);
            cout << "Book removed successfully" << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}
void Library::updateBook(Book *book, string ISBN)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getISBN() == ISBN)
        {
            books[i] = book;
            cout << "Book updated successfully" << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}
vector<Book *> Library::allBooks()
{
    return books;
}
void Library::removeUser(string userID, string ISBN)
{
    if (searchBook(ISBN) == NULL)
    {
        cout << "Book not found" << endl;
        return;
    }
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getOwner() == userID)
        {
            books[i]->setOwner("");
            books[i]->setBorrDate("");
            cout << "User removed successfully" << endl;
            return;
        }
    }
    cout << "User has not borrowed this book" << endl;
}

void Library::borrowedBooks(string userID)
{
    int flag = 0;
    cout << "##################################################" << endl;
    cout << "#                BORROWED BOOKS                  #" << endl;
    cout << "##################################################" << endl;
    cout << endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getOwner() == userID)
        {
            flag++;
            cout << "Title : " << books[i]->getTitle() << endl;
            cout << "Author : " << books[i]->getAuthor() << endl;
            cout << "Publisher : " << books[i]->getPublisher() << endl;
            cout << "ISBN : " << books[i]->getISBN() << endl;
            cout << "Year : " << books[i]->getYear() << endl;
            cout << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No books borrowed!" << endl;
        cout << endl;
    }
    cout << "##################################################" << endl;
}
int Library::availableBooks()
{
    int flag = 0;
    cout << "##################################################" << endl;
    cout << "#                AVAILABLE BOOKS                  #" << endl;
    cout << "##################################################" << endl;
    cout << endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->isAvailable())
        {
            flag++;
            cout << "Title : " << books[i]->getTitle() << endl;
            cout << "Author : " << books[i]->getAuthor() << endl;
            cout << "Publisher : " << books[i]->getPublisher() << endl;
            cout << "ISBN : " << books[i]->getISBN() << endl;
            cout << "Year : " << books[i]->getYear() << endl;
            cout << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No books available!" << endl;
        cout << endl;
    }
    cout << "##################################################" << endl;
    return flag;
}
