#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Librarian.cpp"
// #include "Student.cpp"
// #include "Faculty.cpp"
// #include "Book.cpp"
// #include "Library.cpp"
studAccount::studAccount()
{
    vector<vector<string>> data = readStudentCSV("./Database/Student.csv");
    vector<Student *> students;
    if (data.size() == 0)
        return;
    for (int i = 0; i < data.size(); i++)
    {
        Student *student = new Student(data[i][0], data[i][1], data[i][2], stoi(data[i][3]), stoi(data[i][4]), data[i][5]);
        students.push_back(student);
    }
    this->students = students;
}
studAccount::~studAccount()
{
    vector<vector<string>> data;
    for (int i = 0; i < students.size(); i++)
    {
        vector<string> row;
        row.push_back(students[i]->getName());
        row.push_back(students[i]->getUserID());
        row.push_back(students[i]->getPassword());
        row.push_back(to_string(students[i]->getBorrBooks()));
        row.push_back(to_string(students[i]->getFine()));
        row.push_back(students[i]->getBooksBorrowed());
        data.push_back(row);
    }
    writeStudentCSV("./Database/Student.csv", data);
}
bool studAccount::authenticate(string userID, string password)
{
    Student *student = selectStudent(userID);
    if (student == NULL)
    {
        cout << "User not found" << endl;
        return false;
    }
    if (student->getPassword() == password)
    {
        return true;
    }
    return false;
}
vector<Student *> studAccount::allStudents()
{
    return students;
}
Student *studAccount::selectStudent(string userID)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getUserID() == userID)
        {
            return students[i];
        }
    }
    return NULL;
}
void studAccount::addStudent(Student *student)
{
    if (selectStudent(student->getUserID()) != NULL)
    {
        cout << "User already exists" << endl;
        return;
    }
    students.push_back(student);
    cout << "User added successfully" << endl;
}
void studAccount::removeStudent(string userID)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getUserID() == userID)
        {
            students.erase(students.begin() + i);
            cout << "User removed successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}
void studAccount::updateStudent(Student *student, string userID)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getUserID() == userID)
        {
            students[i] = student;
            cout << "User updated successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}
faculAccount::faculAccount()
{
    vector<vector<string>> data = readFacultyCSV("./Database/Faculty.csv");
    vector<Faculty *> faculties;
    if (data.size() == 0)
        return;
    for (int i = 0; i < data.size(); i++)
    {
        Faculty *faculty = new Faculty(data[i][0], data[i][1], data[i][2], stoi(data[i][3]), data[i][4]);
        faculties.push_back(faculty);
    }
    this->faculties = faculties;
}
faculAccount::~faculAccount()
{
    vector<vector<string>> data;
    for (int i = 0; i < faculties.size(); i++)
    {
        vector<string> row;
        row.push_back(faculties[i]->getName());
        row.push_back(faculties[i]->getUserID());
        row.push_back(faculties[i]->getPassword());
        row.push_back(to_string(faculties[i]->getBorrBooks()));
        row.push_back(faculties[i]->getBooksBorrowed());
        data.push_back(row);
    }
    writeFacultyCSV("./Database/Faculty.csv", data);
}
bool faculAccount::authenticate(string userID, string password)
{
    Faculty *faculty = selectFaculty(userID);
    if (faculty == NULL)
    {
        cout << "User not found" << endl;
        return false;
    }
    if (faculty->getPassword() == password)
    {
        return true;
    }
    return false;
}
vector<Faculty *> faculAccount::allFaculties()
{
    return faculties;
}
Faculty *faculAccount::selectFaculty(string userID)
{
    for (int i = 0; i < faculties.size(); i++)
    {
        if (faculties[i]->getUserID() == userID)
        {
            return faculties[i];
        }
    }
    return NULL;
}
void faculAccount::addFaculty(Faculty *faculty)
{
    if (selectFaculty(faculty->getUserID()) != NULL)
    {
        cout << "User already exists" << endl;
        return;
    }
    faculties.push_back(faculty);
    cout << "User added successfully" << endl;
}
void faculAccount::removeFaculty(string userID)
{
    for (int i = 0; i < faculties.size(); i++)
    {
        if (faculties[i]->getUserID() == userID)
        {
            faculties.erase(faculties.begin() + i);
            cout << "User removed successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}
void faculAccount::updateFaculty(Faculty *faculty, string userID)
{
    for (int i = 0; i < faculties.size(); i++)
    {
        if (faculties[i]->getUserID() == userID)
        {
            faculties[i] = faculty;
            cout << "User updated successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}

libAccount::libAccount()
{
    vector<vector<string>> data = readLibrarianCSV("./Database/Librarian.csv");
    vector<Librarian *> librarians;
    if (data.size() == 0)
        return;
    for (int i = 0; i < data.size(); i++)
    {
        Librarian *librarian = new Librarian(data[i][0], data[i][1], data[i][2]);
        librarians.push_back(librarian);
    }
    this->librarians = librarians;
}
libAccount::~libAccount()
{
    vector<vector<string>> data;
    for (int i = 0; i < librarians.size(); i++)
    {
        vector<string> row;
        row.push_back(librarians[i]->getName());
        row.push_back(librarians[i]->getUserID());
        row.push_back(librarians[i]->getPassword());
        data.push_back(row);
    }
    writeLibrarianCSV("./Database/Librarian.csv", data);
}
bool libAccount::authenticate(string userID, string password)
{
    Librarian *librarian = selectLibrarian(userID);
    if (librarian == NULL)
    {
        cout << "User not found" << endl;
        return false;
    }
    if (librarian->getPassword() == password)
    {
        return true;
    }
    return false;
}
vector<Librarian *> libAccount::allLibrarians()
{
    return librarians;
}
Librarian *libAccount::selectLibrarian(string userID)
{
    for (int i = 0; i < librarians.size(); i++)
    {
        if (librarians[i]->getUserID() == userID)
        {
            return librarians[i];
        }
    }
    return NULL;
}
void libAccount::addLibrarian(Librarian *librarian)
{
    if (selectLibrarian(librarian->getUserID()) != NULL)
    {
        cout << "User already exists" << endl;
        return;
    }
    librarians.push_back(librarian);
    cout << "User added successfully" << endl;
}
void libAccount::removeLibrarian(string userID)
{
    for (int i = 0; i < librarians.size(); i++)
    {
        if (librarians[i]->getUserID() == userID)
        {
            librarians.erase(librarians.begin() + i);
            cout << "User removed successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}
void libAccount::updateLibrarian(Librarian *librarian, string userID)
{
    for (int i = 0; i < librarians.size(); i++)
    {
        if (librarians[i]->getUserID() == userID)
        {
            librarians[i] = librarian;
            cout << "User updated successfully" << endl;
            return;
        }
    }
    cout << "User not found" << endl;
}
