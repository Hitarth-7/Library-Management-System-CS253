#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Librarian.cpp"
// #include "Student.cpp"
// #include "Faculty.cpp"
// #include "Accounts.cpp"
// #include "Library.cpp"
using namespace std;
void Book::borrBook(string userID, int userIDtype)
{
    vector<Book *> books = Library().allBooks();
    string tod = getCurrentDate();
    if (books.size() == 0)
    {
        cout << "No books available to borrow!" << endl;
        return;
    }
    if (userIDtype == 0)
    {
        Student *student = studAccount().selectStudent(userID);
        if (student == NULL)
        {
            cout << "User not found" << endl;
            return;
        }
        else if (student->getBorrBooks() >= 3)
        {
            cout << "You have already borrowed 3 books. Cannot borrow more!" << endl;
            return;
        }
        int userFine = 0;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->getOwner() == userID)
            {
                int days = daysBetween(books[i]->getBorrDate(), tod);
                int toPay = books[i]->calcFine(days);
                userFine += toPay;
            }
        }
        student->setFine(userFine);
        if (userFine > 0)
        {
            cout << "You have a fine of " << userFine << ". Cannot borrow book!" << endl;
            return;
        }
        int avlBooks = Library().availableBooks();
        if (avlBooks == 0)
        {
            return;
        }
        cout << "Enter the ISBN of the book you want to borrow: ";
        string ISBN;
        cin >> ISBN;
        cin.clear();
        cin.ignore(10000, '\n');
        Book *book = Library().searchBook(ISBN);
        if (book == NULL)
        {
            cout << "Book not found" << endl;
            return;
        }
        if (book->getOwner() != "")
        {
            cout << "Book is not available to borrow. Cannot borrow book!" << endl;
            return;
        }
        string hist = student->getBooksBorrowed();
        hist.append(book->getTitle());
        hist.append(":");
        hist.append(ISBN);
        hist.append(":");
        hist.append(tod);
        hist.append(" ");
        book->setOwner(userID);
        book->setBorrDate(tod);
        student->setBorrBooks(student->getBorrBooks() + 1);
        student->setBooksBorrowed(hist);
        studAccount().updateStudent(student, userID);
        Library().updateBook(book, ISBN);
        cout << "Book borrowed successfully!" << endl;
    }
    else if (userIDtype == 1)
    {
        Faculty *faculty = faculAccount().selectFaculty(userID);
        if (faculty == NULL)
        {
            cout << "User not found" << endl;
            return;
        }
        else if (faculty->getBorrBooks() >= 5)
        {
            cout << "You have already borrowed 5 books. Cannot borrow more!" << endl;
            return;
        }
        bool day60 = false;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->getOwner() == userID)
            {
                int days = daysBetween(books[i]->getBorrDate(), tod);
                if (days > 60)
                {
                    day60 = true;
                    break;
                }
            }
        }
        if (day60)
        {
            cout << "You have exceeded the borrowing limit of 60 days. Cannot borrow book!" << endl;
            return;
        }
        cout << "Enter the ISBN of the book you want to borrow: ";
        string ISBN;
        cin >> ISBN;
        cin.clear();
        cin.ignore(10000, '\n');
        Book *book = Library().searchBook(ISBN);
        if (book == NULL)
        {
            cout << "Book not found" << endl;
            return;
        }
        if (book->getOwner() != "")
        {
            cout << "Book is not available to borrow. Cannot borrow book!" << endl;
            return;
        }
        string hist = faculty->getBooksBorrowed();
        hist.append(book->getTitle());
        hist.append(":");
        hist.append(ISBN);
        hist.append(":");
        hist.append(tod);
        hist.append(" ");
        book->setOwner(userID);
        book->setBorrDate(tod);
        faculty->setBorrBooks(faculty->getBorrBooks() + 1);
        faculty->setBooksBorrowed(hist);
        faculAccount().updateFaculty(faculty, userID);
        Library().updateBook(book, ISBN);
        cout << "Book borrowed successfully!" << endl;
    }
    else if (userIDtype == 2)
    {
        cout << "Invalid User. Cannot borrow book!" << endl;
    }
    else
    {
        cout << "Invalid User Type" << endl;
    }
}
