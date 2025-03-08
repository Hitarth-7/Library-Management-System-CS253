#include "bits/stdc++.h"
#include "classes.hpp"
// #include "Student.cpp"
// #include "Faculty.cpp"
// #include "Book.cpp"
// #include "Accounts.cpp"
// #include "Library.cpp"
using namespace std;
string Librarian::libLogin()
{
    string userID, password;
    int trials = 5;
    while (true)
    {
        cout << "############################################" << endl;
        cout << "#                 LIBRARIAN LOGIN          #" << endl;
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
        if (libAccount().authenticate(userID, password))
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
