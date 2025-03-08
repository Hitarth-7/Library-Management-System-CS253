#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Faculty.cpp"
// #include "Book.cpp"
// #include "Accounts.cpp"
// #include "Library.cpp"
// #include "Librarian.cpp"
using namespace std;
string Student::studLogin()
{
    string userID, password;
    int trials = 5;
    while (true)
    {
        cout << "############################################" << endl;
        cout << "#                 STUDENT LOGIN            #" << endl;
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
        if (studAccount().authenticate(userID, password))
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

void Student::displayBorrHistory()
{
    Student *student = studAccount().selectStudent(this->getUserID());
    if (student == NULL)
    {
        cout << "Student not found" << endl;
        return;
    }
    string booksBorrowed = student->getBooksBorrowed();
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

void Student::returnReq()
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

    if (days > 15)
    {
        int toPay = book->calcFine(days);
        this->setFine(this->getFine() + toPay);
        cout << "You have exceeded the due date by " << days - 15 << " days" << endl;
        cout << "Fine to be paid: " << (toPay) << endl;
        cout << "##################################################" << endl;
        if (!confirm())
        {
            return;
        }
        // this->setFine(this->getFine() - toPay);
        this->payFine();
        this->setBorrBooks(this->getBorrBooks() - 1);
        studAccount().updateStudent(this, this->getUserID());
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
        studAccount().updateStudent(this, this->getUserID());
        book->setOwner("");
        book->setBorrDate("");
        Library().updateBook(book, ISBN);
        cout << "Book returned successfully!" << endl;
    }
}

void Student::payFine()
{
    if (this->getFine() == 0)
    {
        cout << "No fine to be paid!" << endl;
        return;
    }
    cout << "##################################################" << endl;
    cout << "#                PAY FINE                        #" << endl;
    cout << "##################################################" << endl;
    cout << "Fine to be paid: $" << this->getFine() << endl;
    cout << "##################################################" << endl;
    cout << "Enter the amount you would like to pay : $" << endl;
    string amount;
    cin >> amount;
    if (!isNumber(amount))
    {
        return;
    }
    int toPay = stoi(amount);
    if (toPay > this->getFine())
    {
        cout << "Invalid amount entered!" << endl;
        cout << "Amount entered is greater than the fine to be paid!" << endl;
        return;
    }
    if (toPay < 0)
    {
        cout << "Invalid amount entered!" << endl;
        cout << "Amount entered cannot be negative" << endl;
        return;
    }
    if (!confirm())
    {
        return;
    }
    this->setFine(this->getFine() - toPay);
    studAccount().updateStudent(this, this->getUserID());
    cout << "Fine paid successfully!" << endl;
}