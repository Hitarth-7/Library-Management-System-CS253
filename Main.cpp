#include "bits/stdc++.h"
#include "classes.hpp"
#include "Librarian.cpp"
#include "Student.cpp"
#include "Faculty.cpp"
#include "Book.cpp"
#include "Accounts.cpp"
#include "Library.cpp"
using namespace std;

void Student_menu()
{
    string userid = Student().studLogin();
    if (userid == "")
    {
        return;
    }
    int choice = 0;
    while (choice != 8)
    {
        Student *student = studAccount().selectStudent(userid);
        cout << "##################################################" << endl;
        cout << "#                STUDENT MENU                    #" << endl;
        cout << "##################################################" << endl;
        cout << "#                1. Borrow a book                #" << endl;
        cout << "#                2. Return a book                #" << endl;
        cout << "#                3. Pay fine                     #" << endl;
        cout << "#                4. Display borrowed books       #" << endl;
        cout << "#                5. Display borrowing history    #" << endl;
        cout << "#                6. Display all available books  #" << endl;
        cout << "#                7. Display fine                 #" << endl;
        cout << "#                8. Logout                       #" << endl;
        cout << "##################################################" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        if (choice == 1)
        {
            Book().borrBook(userid, 0);
        }
        else if (choice == 2)
        {
            student->returnReq();
        }
        else if (choice == 3)
        {
            student->payFine();
        }
        else if (choice == 4)
        {
            Library().borrowedBooks(userid);
        }
        else if (choice == 5)
        {
            student->displayBorrHistory();
        }
        else if (choice == 6)
        {
            Library().availableBooks();
        }
        else if (choice == 7)
        {
            int userFine = 0;
            vector<Book *> books = Library().allBooks();
            string tod = getCurrentDate();
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i]->getOwner() == userid)
                {
                    int days = daysBetween(books[i]->getBorrDate(), tod);
                    int toPay = books[i]->calcFine(days);
                    userFine += toPay;
                }
            }
            student->setFine(userFine);
            studAccount().updateStudent(student, userid);
            cout << "Total Fine to be paid by you: $" << userFine << endl;
        }
        else if (choice == 8)
        {
            cout << "Logging out..." << endl;
            return;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

void Faculty_menu()
{
    string userid = Faculty().facLogin();
    if (userid == "")
    {
        return;
    }
    int choice = 0;
    while (choice != 6)
    {
        Faculty *faculty = faculAccount().selectFaculty(userid);
        cout << "##################################################" << endl;
        cout << "#                STUDENT MENU                    #" << endl;
        cout << "##################################################" << endl;
        cout << "#                1. Borrow a book                #" << endl;
        cout << "#                2. Return a book                #" << endl;
        cout << "#                3. Display borrowed books       #" << endl;
        cout << "#                4. Display borrowing history    #" << endl;
        cout << "#                5. Display all available books  #" << endl;
        cout << "#                6. Logout                       #" << endl;
        cout << "##################################################" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        if (choice == 1)
        {
            Book().borrBook(userid, 1);
        }
        else if (choice == 2)
        {
            faculty->returnReq();
        }
        else if (choice == 3)
        {
            Library().borrowedBooks(userid);
        }
        else if (choice == 4)
        {
            faculty->displayBorrHistory();
        }
        else if (choice == 5)
        {
            Library().availableBooks();
        }
        else if (choice == 6)
        {
            cout << "Logging out..." << endl;
            return;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

void Librarian_menu()
{
    string userid = Librarian().libLogin();
    if (userid == "")
    {
        return;
    }
    int choice = 0;
    while (choice != 19)
    {
        cout << "##################################################" << endl;
        cout << "#                LIBRARIAN MENU                  #" << endl;
        cout << "##################################################" << endl;
        cout << "#                1. Display all books            #" << endl;
        cout << "#                2. Display available books      #" << endl;
        cout << "#                3. Display borrowed books       #" << endl;
        cout << "#                4. Display all Students         #" << endl;
        cout << "#                5. Display all Faculties        #" << endl;
        cout << "#                6. Display all Librarians       #" << endl;
        cout << "#                7. Add a book                   #" << endl;
        cout << "#                8. Remove a book                #" << endl;
        cout << "#                9. Update a book                #" << endl;
        cout << "#                10. Add a student               #" << endl;
        cout << "#                11. Remove a student            #" << endl;
        cout << "#                12. Update a student            #" << endl;
        cout << "#                13. Add a faculty               #" << endl;
        cout << "#                14. Remove a faculty            #" << endl;
        cout << "#                15. Update a faculty            #" << endl;
        cout << "#                16. Add a librarian             #" << endl;
        cout << "#                17. Remove a librarian          #" << endl;
        cout << "#                18. Update a librarian          #" << endl;
        cout << "#                19. Logout                      #" << endl;
        cout << "##################################################" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        if (choice == 1)
        {
            vector<Book *> books = Library().allBooks();
            cout << "##################################################" << endl;
            cout << "#                ALL BOOKS                       #" << endl;
            cout << "##################################################" << endl;
            cout << endl;
            for (int i = 0; i < books.size(); i++)
            {
                cout << "Title : " << books[i]->getTitle() << endl;
                cout << "Author : " << books[i]->getAuthor() << endl;
                cout << "Publisher : " << books[i]->getPublisher() << endl;
                cout << "ISBN : " << books[i]->getISBN() << endl;
                cout << "Year : " << books[i]->getYear() << endl;
                cout << "Owner : " << books[i]->getOwner() << endl;
                cout << "Borrowed Date : " << books[i]->getBorrDate() << endl;
                cout << endl;
            }
            if (books.size() == 0)
            {
                cout << "No books found!" << endl;
                cout << endl;
            }
        }
        else if (choice == 2)
        {
            Library().availableBooks();
        }
        else if (choice == 3)
        {
            vector<Book *> books = Library().allBooks();
            int flag = 0;
            cout << "##################################################" << endl;
            cout << "#                BORROWED BOOKS                  #" << endl;
            cout << "##################################################" << endl;
            cout << endl;
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i]->getOwner() != "")
                {
                    flag++;
                    cout << "Title : " << books[i]->getTitle() << endl;
                    cout << "Author : " << books[i]->getAuthor() << endl;
                    cout << "Publisher : " << books[i]->getPublisher() << endl;
                    cout << "ISBN : " << books[i]->getISBN() << endl;
                    cout << "Year : " << books[i]->getYear() << endl;
                    cout << "Borrower : " << books[i]->getOwner() << endl;
                    cout << "Borrowed Date : " << books[i]->getBorrDate() << endl;
                    cout << endl;
                }
            }
            if (flag == 0)
            {
                cout << "No books borrowed!" << endl;
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            vector<Student *> students = studAccount().allStudents();
            cout << "##################################################" << endl;
            cout << "#                ALL STUDENTS                    #" << endl;
            cout << "##################################################" << endl;
            cout << endl;
            for (int i = 0; i < students.size(); i++)
            {
                cout << "Name : " << students[i]->getName() << endl;
                cout << "UserID : " << students[i]->getUserID() << endl;
                cout << "Books Borrowed : " << students[i]->getBorrBooks() << endl;
                cout << "Fine : " << students[i]->getFine() << endl;
                cout << "Books Borrowed : " << students[i]->getBooksBorrowed() << endl;
                cout << endl;
            }
            if (students.size() == 0)
            {
                cout << "No students found!" << endl;
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            vector<Faculty *> faculties = faculAccount().allFaculties();
            cout << "##################################################" << endl;
            cout << "#                ALL FACULTIES                   #" << endl;
            cout << "##################################################" << endl;
            cout << endl;
            for (int i = 0; i < faculties.size(); i++)
            {
                cout << "Name : " << faculties[i]->getName() << endl;
                cout << "UserID : " << faculties[i]->getUserID() << endl;
                cout << "Books Borrowed : " << faculties[i]->getBorrBooks() << endl;
                cout << "Books Borrowed : " << faculties[i]->getBooksBorrowed() << endl;
                cout << endl;
            }
            if (faculties.size() == 0)
            {
                cout << "No faculties found!" << endl;
                cout << endl;
            }
        }
        else if (choice == 6)
        {
            vector<Librarian *> librarians = libAccount().allLibrarians();
            cout << "##################################################" << endl;
            cout << "#                ALL LIBRARIANS                  #" << endl;
            cout << "##################################################" << endl;
            cout << endl;
            for (int i = 0; i < librarians.size(); i++)
            {
                cout << "Name : " << librarians[i]->getName() << endl;
                cout << "UserID : " << librarians[i]->getUserID() << endl;
                cout << endl;
            }
            if (librarians.size() == 0)
            {
                cout << "No librarians found!" << endl;
                cout << endl;
            }
        }
        else if (choice == 7)
        {
            cout << "Enter the details of the book to be added" << endl;
            cout << "Title: ";
            string title;
            getline(cin, title);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Author: ";
            string author;
            getline(cin, author);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Publisher: ";
            string publisher;
            getline(cin, publisher);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ISBN: ";
            string ISBN;
            cin >> ISBN;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Year: [YYYY-MM-DD]";
            string year;
            cin >> year;
            cin.clear();
            cin.ignore(10000, '\n');
            Book *book = new Book(title, author, publisher, ISBN, year, "", "");
            Library().addBook(book);
        }
        else if (choice == 8)
        {
            cout << "Enter the ISBN of the book to be removed: ";
            string ISBN;
            cin >> ISBN;
            cin.clear();
            cin.ignore(10000, '\n');
            Library().removeBook(ISBN);
        }
        else if (choice == 9)
        {
            cout << "Enter the details of the book to be updated" << endl;
            cout << "Title: ";
            string title;
            getline(cin, title);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Author: ";
            string author;
            getline(cin, author);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Publisher: ";
            string publisher;
            getline(cin, publisher);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "New ISBN: ";
            string newISBN;
            cin >> newISBN;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Year: [YYYY-MM-DD]";
            string year;
            cin >> year;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Owner: ";
            string owner;
            getline(cin, owner);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Borrowed Date: ";
            string borrDate;
            getline(cin, borrDate);
            cin.clear();
            cin.ignore(10000, '\n');
            Book *book = new Book(title, author, publisher, newISBN, year, owner, borrDate);
            cout << "Enter the ISBN of the book to be updated: ";
            string ISBN;
            cin >> ISBN;
            cin.clear();
            cin.ignore(10000, '\n');
            Library().updateBook(book, ISBN);
        }
        else if (choice == 10)
        {
            cout << "Enter the details of the student to be added" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "UserID: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            Student *student = new Student(name, userID, password, 0, 0, "");
            studAccount().addStudent(student);
        }
        else if (choice == 11)
        {
            cout << "Enter the UserID of the student to be removed: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            studAccount().removeStudent(userID);
        }
        else if (choice == 12)
        {
            cout << "Enter the details of the student to be updated" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "New UserID: ";
            string newuserID;
            cin >> newuserID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "No of Borrowed Books: ";
            int borrBooks;
            cin >> borrBooks;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Fine: ";
            int fine;
            cin >> fine;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Books Borrowed till now [Title:ISBN:YYYY-MM-DD]: ";
            string booksBorrowed;
            getline(cin, booksBorrowed);
            cin.clear();
            cin.ignore(10000, '\n');
            Student *student = new Student(name, newuserID, password, borrBooks, fine, booksBorrowed);
            cout << "Enter the UserID of the student to be updated: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            studAccount().updateStudent(student, userID);
        }
        else if (choice == 13)
        {
            cout << "Enter the details of the faculty to be added" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "UserID: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            Faculty *faculty = new Faculty(name, userID, password, 0, "");
            faculAccount().addFaculty(faculty);
        }
        else if (choice == 14)
        {
            cout << "Enter the UserID of the faculty to be removed: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            faculAccount().removeFaculty(userID);
        }
        else if (choice == 15)
        {
            cout << "Enter the details of the faculty to be updated" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "New UserID: ";
            string newuserID;
            cin >> newuserID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "No. of Borrowed Books: ";
            int borrBooks;
            cin >> borrBooks;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Books Borrowed till now [Title:ISBN:YYYY-MM-DD]: ";
            string booksBorrowed;
            getline(cin, booksBorrowed);
            cin.clear();
            cin.ignore(10000, '\n');
            Faculty *faculty = new Faculty(name, newuserID, password, borrBooks, booksBorrowed);
            cout << "Enter the UserID of the faculty to be updated: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            faculAccount().updateFaculty(faculty, userID);
        }
        else if (choice == 16)
        {
            cout << "Enter the details of the librarian to be added" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "UserID: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            Librarian *librarian = new Librarian(name, userID, password);
            libAccount().addLibrarian(librarian);
        }
        else if (choice == 17)
        {
            cout << "Enter the UserID of the librarian to be removed: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            if (userid == userID)
            {
                cout << "Cannot remove yourself!" << endl;
                continue;
            }
            libAccount().removeLibrarian(userID);
        }
        else if (choice == 18)
        {
            cout << "Enter the details of the librarian to be updated" << endl;
            cout << "Name: ";
            string name;
            getline(cin, name);
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "New UserID: ";
            string newuserID;
            cin >> newuserID;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Password: ";
            string password;
            getline(cin, password);
            cin.clear();
            cin.ignore(10000, '\n');
            Librarian *librarian = new Librarian(name, newuserID, password);
            cout << "Enter the UserID of the librarian to be updated: ";
            string userID;
            cin >> userID;
            cin.clear();
            cin.ignore(10000, '\n');
            libAccount().updateLibrarian(librarian, userID);
        }
        else if (choice == 19)
        {
            cout << "Logging out..." << endl;
            return;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

int main()
{
    int option = 0;
    while (option != 4)
    {

        cout << "##################################################" << endl;
        cout << "#                LIBRARY MANAGEMENT SYSTEM       #" << endl;
        cout << "##################################################" << endl;
        cout << "#                1. Student Login                #" << endl;
        cout << "#                2. Faculty Login                #" << endl;
        cout << "#                3. Librarian Login              #" << endl;
        cout << "#                4. Exit                         #" << endl;
        cout << "##################################################" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.clear();
        cin.ignore(10000, '\n');

        if (option == 1)
        {
            system("cls");
            Student_menu();
        }
        else if (option == 2)
        {
            system("cls");
            Faculty_menu();
        }
        else if (option == 3)
        {
            system("cls");
            Librarian_menu();
        }
        else if (option == 4)
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}