#pragma once
#include "bits/stdc++.h"
using namespace std;

class User
{
protected:
    string name;
    string userID;
    string password;

public:
    string getName()
    {
        return name;
    }
    string getUserID()
    {
        return userID;
    }
    string getPassword()
    {
        return password;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setUserID(string userID)
    {
        this->userID = userID;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
};

class Book
{
private:
    string title;
    string author;
    string publisher;
    string ISBN;
    string year;
    string owner;
    string borrDate;

public:
    Book()
    {
        title = "";
        author = "";
        publisher = "";
        ISBN = "";
        year = "";
        owner = "";
        borrDate = "";
    };
    Book(string title, string author, string publisher, string ISBN, string year, string owner, string borrDate)
    {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->ISBN = ISBN;
        this->year = year;
        this->owner = owner;
        this->borrDate = borrDate;
    }
    bool isAvailable()
    {
        if (owner == "")
        {
            return true;
        }
        return false;
    };
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getPublisher()
    {
        return publisher;
    }
    string getISBN()
    {
        return ISBN;
    }
    string getYear()
    {
        return year;
    }
    string getOwner()
    {
        return owner;
    }
    string getBorrDate()
    {
        return borrDate;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setPublisher(string publisher)
    {
        this->publisher = publisher;
    }
    void setISBN(string ISBN)
    {
        this->ISBN = ISBN;
    }
    void setYear(string year)
    {
        this->year = year;
    }
    void setOwner(string owner)
    {
        this->owner = owner;
    }
    void setBorrDate(string borrDate)
    {
        this->borrDate = borrDate;
    }
    void borrBook(string userID, int userIDType);
    int calcFine(int days)
    {
        int fine = 0;
        fine = ((days > 15) ? days * 10 : 0);
        return fine;
    }
};

class Student : public User
{
private:
    int borrBooks;
    int fine;
    string booksBorrowed;

public:
    Student()
    {
        userID = "";
        name = "";
        password = "";
        booksBorrowed = "";
        borrBooks = 0;
        fine = 0;
    };
    Student(string name, string userID, string password, int borrBooks, int fine, string booksBorrowed)
    {
        this->name = name;
        this->userID = userID;
        this->password = password;
        this->borrBooks = borrBooks;
        this->booksBorrowed = booksBorrowed;
        this->fine = fine;
    }
    int getBorrBooks()
    {
        return borrBooks;
    }
    int getFine()
    {
        return fine;
    }
    string getBooksBorrowed()
    {
        return booksBorrowed;
    }
    void setBorrBooks(int borrBooks)
    {
        this->borrBooks = borrBooks;
    }
    void setFine(int fine)
    {
        this->fine = fine;
    }
    void setBooksBorrowed(string booksBorrowed)
    {
        this->booksBorrowed = booksBorrowed;
    }
    void payFine();
    string studLogin();
    void returnReq();
    void displayBorrHistory();
};

class Faculty : public User
{
private:
    int borrBooks;
    string booksBorrowed;

public:
    Faculty()
    {
        userID = "";
        name = "";
        password = "";
        booksBorrowed = "";
        borrBooks = 0;
    };
    Faculty(string name, string userID, string password, int borrBooks, string booksBorrowed)
    {
        this->name = name;
        this->userID = userID;
        this->password = password;
        this->booksBorrowed = booksBorrowed;
        this->borrBooks = borrBooks;
    }
    int getBorrBooks()
    {
        return borrBooks;
    }
    string getBooksBorrowed()
    {
        return booksBorrowed;
    }
    void setBorrBooks(int borrBooks)
    {
        this->borrBooks = borrBooks;
    }
    void setBooksBorrowed(string booksBorrowed)
    {
        this->booksBorrowed = booksBorrowed;
    }
    void returnReq();
    void displayBorrHistory();
    string facLogin();
};

class Librarian : public User
{
public:
    Librarian()
    {
        userID = "";
        name = "";
        password = "";
    };
    Librarian(string name, string userID, string password)
    {
        this->name = name;
        this->userID = userID;
        this->password = password;
    }
    string libLogin();
};

class Library
{
private:
    vector<Book *> books;

public:
    Library();
    void addBook(Book *book);
    void removeBook(string ISBN);
    void updateBook(Book *book, string ISBN);
    Book *searchBook(string ISBN);
    vector<Book *> allBooks();
    void removeUser(string userID, string ISBN);
    void borrowedBooks(string userID);
    int availableBooks();
    ~Library();
};

class studAccount
{
private:
    vector<Student *> students;

public:
    studAccount();
    void addStudent(Student *student);
    void removeStudent(string userID);
    void updateStudent(Student *student, string userID);
    Student *selectStudent(string userID);
    vector<Student *> allStudents();
    bool authenticate(string userID, string password);
    ~studAccount();
};

class faculAccount
{
private:
    vector<Faculty *> faculties;

public:
    faculAccount();
    void addFaculty(Faculty *faculty);
    void removeFaculty(string userID);
    void updateFaculty(Faculty *faculty, string userID);
    Faculty *selectFaculty(string userID);
    vector<Faculty *> allFaculties();
    bool authenticate(string userID, string password);
    ~faculAccount();
};

class libAccount
{
private:
    vector<Librarian *> librarians;

public:
    libAccount();
    void addLibrarian(Librarian *librarian);
    void removeLibrarian(string userID);
    void updateLibrarian(Librarian *librarian, string userID);
    Librarian *selectLibrarian(string userID);
    vector<Librarian *> allLibrarians();
    bool authenticate(string userID, string password);
    ~libAccount();
};

string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    return to_string(year) + "-" + (month < 10 ? "0" + to_string(month) : to_string(month)) + "-" +
           (day < 10 ? "0" + to_string(day) : to_string(day));
}
int daysBetween(string date1, string date2)
{
    int y1, m1, d1, y2, m2, d2;
    sscanf(date1.c_str(), "%d-%d-%d", &y1, &m1, &d1);
    sscanf(date2.c_str(), "%d-%d-%d", &y2, &m2, &d2);

    struct tm t1 = {0, 0, 0, d1, m1 - 1, y1 - 1900};
    struct tm t2 = {0, 0, 0, d2, m2 - 1, y2 - 1900};

    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);

    return (time2 - time1) / (60 * 60 * 24); // Convert seconds to days
}
vector<vector<string>> readBookCSV(const string &filename)
{
    ifstream file(filename);
    vector<vector<string>> data;
    string line;

    while (getline(file, line))
    {
        vector<string> row;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ','))
        {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}

vector<vector<string>> readStudentCSV(const string &filename)
{
    ifstream file(filename);
    vector<vector<string>> data;
    string line;

    while (getline(file, line))
    {
        vector<string> row;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ','))
        {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}

vector<vector<string>> readFacultyCSV(const string &filename)
{
    ifstream file(filename);
    vector<vector<string>> data;
    string line;

    while (getline(file, line))
    {
        vector<string> row;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ','))
        {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}

vector<vector<string>> readLibrarianCSV(const string &filename)
{
    ifstream file(filename);
    vector<vector<string>> data;
    string line;

    while (getline(file, line))
    {
        vector<string> row;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ','))
        {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}

void writeBookCSV(const string &filename, const vector<vector<string>> &data)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Could not open file for writing");
    }

    for (const auto &row : data)
    {
        for (size_t i = 0; i <= 6; ++i)
        {
            if (i < row.size())
            {
                file << row[i];
            }
            file << ","; // Add comma except for the last column
        }
        file << "\n"; // New line after each row
    }

    file.close();
}

void writeStudentCSV(const string &filename, const vector<vector<string>> &data)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Could not open file for writing");
    }

    for (const auto &row : data)
    {
        for (size_t i = 0; i <= 5; ++i)
        {
            if (i < row.size())
            {
                file << row[i];
            }
            file << ","; // Add comma except for the last column
        }
        file << "\n"; // New line after each row
    }

    file.close();
}

void writeFacultyCSV(const string &filename, const vector<vector<string>> &data)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Could not open file for writing");
    }

    for (const auto &row : data)
    {
        for (size_t i = 0; i <= 4; ++i)
        {
            if (i < row.size())
            {
                file << row[i];
            }
            file << ","; // Add comma except for the last column
        }
        file << "\n"; // New line after each row
    }

    file.close();
}

void writeLibrarianCSV(const string &filename, const vector<vector<string>> &data)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Could not open file for writing");
    }

    for (const auto &row : data)
    {
        for (size_t i = 0; i <= 2; ++i)
        {
            if (i < row.size())
            {
                file << row[i];
            }
            file << ","; // Add comma except for the last column
        }
        file << "\n"; // New line after each row
    }

    file.close();
}

bool confirm()
{
    cout << "[Input] Confirm ? (Y/N): ";
    char confirm;
    cin >> confirm;
    cin.clear();
    cin.ignore(10000, '\n');
    if (confirm == 'N' || confirm == 'n')
    {
        cout << "Process Cancelled!" << endl;
        return false;
    }
    else if (confirm != 'Y' && confirm != 'y')
    {
        cout << "Invalid input!" << endl;
        cout << "Process Cancelled!" << endl;
        return false;
    }
    return true;
}

bool isNumber(string temp)
{
    for (int i = 0; i < temp.length(); i++)
    {
        if (isdigit(temp[i]) == false)
        {
            cout << "Invalid input!" << endl;
            cout << "Process Cancelled!" << endl;
            return false;
        }
    }
    return true;
}
bool isValidDateFormat(const string &date)
{
    // Regular expression to check the format YYYY-MM-DD where YYYY, MM, and DD are numbers
    regex datePattern(R"(^\d{4}-\d{2}-\d{2}$)");
    return regex_match(date, datePattern);
}