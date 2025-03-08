#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Librarian.cpp"
// #include "Student.cpp"
// #include "Book.cpp"
// #include "Accounts.cpp"
// #include "Library.cpp"
using namespace std;
string Faculty::facLogin()
{
    string userID, password;
    int trials = 5;
    while (true)
    {
        cout << "############################################" << endl;
        cout << "#                 FACULTY LOGIN            #" << endl;
        cout << "############################################" << endl;
        cout << endl;
        cout << "Enter userID: ";
        cin >> userID;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter password: ";
        cin >> password;
        cin.clear();
        cin.ignore(10000, '\n');
        if (faculAccount().authenticate(userID, password))
        {
            cout << "Login successful!" << endl;
            return userID;
        }
        else
        {
            cout << "Invalid credentials!" << endl;
            trials--;
            if (trials == 0)
            {
                cout << "Maximum trials reached!" << endl;
                return "";
            }
            cout << "Trials left: " << trials << endl;
        }
    }
}

void Faculty::displayBorrHistory()
{
    Faculty *faculty = faculAccount().selectFaculty(this->getUserID());
    if (faculty == NULL)
    {
        cout << "Faculty not found" << endl;
        return;
    }
    string booksBorrowed = faculty->getBooksBorrowed();
    if (booksBorrowed == "")
    {
        cout << "No books borrowed" << endl;
        return;
    }
    cout << "##################################################" << endl;
    cout << "#              BOOKS BORROWED BY YOU             #" << endl;
    cout << "##################################################" << endl;
    cout << "Title      :         ISBN          :          Date" << endl;
    cout << endl;
    for (int i = 0; i < booksBorrowed.size(); i++)
    {

        if (booksBorrowed[i] == ' ' && i > 10 && isValidDateFormat(booksBorrowed.substr(i - 10, 10)))
        {
            cout << '\n'
                 << endl;
            continue;
        }
        // else if (booksBorrowed[i] == ' ')
        // {
        //     cout << '\n';
        //     continue;
        // }
        else if (booksBorrowed[i] == ':')
        {
            cout << " : ";
            continue;
        }
        cout << booksBorrowed[i];
    }
    cout << endl;
    cout << "##################################################" << endl;
}

void Faculty::returnReq()
{
    if (this->getBorrBooks() == 0)
    {
        cout << "No books borrowed!" << endl;
        return;
    }
    cout << "##################################################" << endl;
    cout << "#                RETURN A BOOK                   #" << endl;
    cout << "##################################################" << endl;
    cout << endl;
    Library().borrowedBooks(this->getUserID());
    cout << "Enter ISBN of the book you want to return: ";
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
    if (book->getOwner() != this->getUserID())
    {
        cout << "You have not borrowed this book!" << endl;
        return;
    }
    string tod = getCurrentDate();
    int days = daysBetween(book->getBorrDate(), tod);

    if (days > 30)
    {
        cout << "You have exceeded the due date by " << days - 30 << " days" << endl;
        cout << "##################################################" << endl;
        if (!confirm())
        {
            return;
        }
        this->setBorrBooks(this->getBorrBooks() - 1);
        faculAccount().updateFaculty(this, this->getUserID());
        book->setOwner("");
        book->setBorrDate("");
        Library().updateBook(book, ISBN);
        cout << "Book returned successfully!" << endl;
    }
    else
    {
        cout << "##################################################" << endl;
        if (!confirm())
        {
            return;
        }
        this->setBorrBooks(this->getBorrBooks() - 1);
        faculAccount().updateFaculty(this, this->getUserID());
        book->setOwner("");
        book->setBorrDate("");
        Library().updateBook(book, ISBN);
        cout << "Book returned successfully!" << endl;
    }
}
