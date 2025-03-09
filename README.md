# Library Management System

This repository contains the C++ code for a Library Management System, an assignment for the course CS253 : Software Development and Operations, Spring 2025 under the Prof. Indranil Saha.

## Setup Instructions

Clone this repository using the below command in terminal.

```
git clone https://github.com/Hitarth-7/Library-Management-System-CS253.git
```

Run the code below to compile the files and create an executable file.

```
g++ Main.cpp -o Main
```

Run the created executable file by running below code in cmd.

```
Main.exe
```

Run the created executable file by running below code in bash.

```
./Main.exe
```

## Assignment Structure

The repository consists of :

- `bits` Folder : This folder contains the standard header C++ file `stdc++.h` which contains every standard library and STL include file.

- `Database` Folder : This folder acts as a database for the Library and contains 4 comma separated values files to store information.

- `Faculty.csv` : This file contains the data about the Faculties. It contains 5 different columns namely `Name`, `UserID`, `Password`, `NumberOfBooksBorrowed` and `BorrowHistory`.

- `Librarian.csv` : This file contains the data about the librarians. It contains 3 different columns namely `Name`, `UserID` and `Password.

- `Library.csv` : This file contains the data about the Books in the Library. It contains 7 different columns namely `Title`, `Author`, `Publisher`, `ISBN`, `Year`, `Owner` and `BorrowDate`.

- `Student.csv` : This file contains the data about Students. It contains 6 different columns namely `Name`, `UserID`, `Password`,`NumberOfBooksBorrowed`, `Fine` and `BorrowHistory`.

- `Classes.hpp` : This file contains class declarations and some additional functions.

- `User` class :

- Parent class for Student, Faculty and Librarian.

- Attributes - Name, UserID, Password.

- `Book` class :

- Attributes - Title, Author, Publisher, ISBN, Year, Owner, BorrowDate.

- Functions - to Check whether the book is Available or not, to Borrow a book, to Calculate Fine for the book.

- `Student` class :

- Attributes - Name, UserID, Password, NumberOfBooksBorrowed, Fine, BorrowHistory.

- Functions - to Authenticate Login, to Pay Fine, to Return a book. to Display Borrow History.

- `Faculty` class :

- Attributes - Name, UserID, Password, NumberOfBooksBorrowed, BorrowHistory.

- Functions - to Authenticate Login, to Return a book, to Display Borrow History.

- `Librarian` class :

- Attributes - Name, UserID, Password.
- Functions - to Display, Add, Update and Remove Books and Users, to Display all Available and Borrowed Books.

- `Library` class :
- Attributes - A vector of Book Objects which reads from and writes to Library.csv file in the Database folder.

- Functions - to Add a book, to Remove a book, to Update a book, to Select a particular book using ISBN , get a list of all books, remove the owner of the book, to get all the Borrowed books of a particular User by its UserID, to Display all Available books.

- `studAccount` class :
- Attributes - A vector of Student objects which reads from and writes to Student.csv file in the Database folder.

- Functions - to Add an Student, to Remove an Student, to Update an Student, Select a particular Student using UserID, to get List of all Students, to Authenticate a Student using UserID and Password.

- `faculAccount` class :
- Attributes - A vector of Faculty Objects which reads from and writes to Faculty.csv file in the Database folder.

- Functions - to Add a Faculty, to Remove a Faculty, to Update a Faculty, to Select a particular Faculty using UserID, to get List of all Faculties, to Authenticate a Faculty using UserID and Password.

- `libAccount` class :
- Attributes - A vector of Librarian Objects which reads from and write to Librarian.csv file in the Database folder.

- Functions - to Add a Librarian, to Remove a Librarian, to Update a Librarian, to Select a particular Librarian using UserID, to get List of all Librarians, to Authenticate a Librarian using UserID and Password.

- Other Functions : to get Current Date, to Calculate the Number of days between 2 dates, A read as well as write function for each Library.csv, Student.csv, Faculty.csv, Librarian.csv, to check the confirmation of the user, to check if a string is a Number or not, to check if a string follows a particular Date format or not.

- `Book.cpp` : Contains function definitions of `Book` class.

- `Student.cpp` : Contains function definitions of `Student` class.

- `Faculty.cpp` : Contains function definitions of `Faculty` class.

- `Librarian.cpp` : Contains function definitions of `Librarian` class.

- `Accounts.cpp` : Contains function definitions of `studAccount`, `faculAccount`, and `libAccount` class.
- `Library.cpp` : Contains function definitions of `Library` class.

- `Main.cpp` : Contains User Interaction functions like `Student_menu`, `Faculty_menu`, `Librarian_menu` and Library Management System Menu.

## Database Structure

This repository contains 4 different comma separated values files to store information about `Students`, `Faculties`, `Librarians` and `Books`.

There are initially 10 Books, 5 Students, 3 Faculties and 1 Librarian. The details of the databases are shown below :

### Student.csv

| Name     | UserID | Password  | No. Of Books Borrowed | Fine | Borrow History                                                                                 |
| -------- | ------ | --------- | --------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| Student1 | st1    | studpass1 | 1                     | 20   | Book1:0000000000001:2025-01-01                                                                 |
| Student2 | st2    | studpass2 | 3                     | 0    | Book1:0000000000001:2025-02-01, Book2:0000000000002:2025-05-01, Book3:0000000000003:2025-07-06 |
| Student3 | st3    | studpass3 | 0                     | 0    | Book4:0000000000004:2025-04-03                                                                 |
| Student4 | st4    | studpass4 | 0                     | 0    |                                                                                                |
| Student5 | st5    | studpass5 | 0                     | 0    |                                                                                                |

### Faculty.csv

| Name     | UserID | Password | No. of Books Borrowed | Borrow History                 |
| -------- | ------ | -------- | --------------------- | ------------------------------ |
| Faculty1 | fac1   | facpass1 | 1                     | Book5:0000000000005:2025-03-07 |
| Faculty2 | fac2   | facpass2 | 0                     |                                |
| Faculty3 | fac3   | facpass3 | 0                     |                                |

### Librarian.csv

| Name       | UserID | Password |
| ---------- | ------ | -------- |
| Librarian1 | lib1   | libpass1 |

### Library.csv

| Title  | Author | Publisher | ISBN          | Year | Owner | Borrow Date |
| ------ | ------ | --------- | ------------- | ---- | ----- | ----------- |
| Book1  | Auth1  | Pub1      | 0000000000001 | 2025 | st2   | 2025-02-01  |
| Book2  | Auth2  | Pub2      | 0000000000002 | 2024 | st2   | 2025-05-01  |
| Book3  | Auth3  | Pub3      | 0000000000003 | 2023 | st2   | 2025-07-06  |
| Book4  | Auth4  | Pub4      | 0000000000004 | 2022 |       |             |
| Book5  | Auth5  | Pub5      | 0000000000005 | 2021 | fac1  | 2025-03-07  |
| Book6  | Auth6  | Pub6      | 0000000000006 | 2020 |       |             |
| Book7  | Auth7  | Pub7      | 0000000000007 | 2019 |       |             |
| Book8  | Auth8  | Pub8      | 0000000000008 | 2018 |       |             |
| Book9  | Auth9  | Pub9      | 0000000000009 | 2017 |       |             |
| Book10 | Auth10 | Pub10     | 0000000000010 | 2016 |       |             |

**NOTE : In the Student Database, if there is no book borrowed then the Borrow History[Title:ISBN:BorrowDate] is empty. Borrow History is the permanent history of the user and hence if the book is borrowed once and returned, then it will be added to history and stays even after returning the book hence it is possible to have 0 fine and 0 books borrowed but non empty history.**

## Assumptions and Design

- Librarian cannot borrow any books.

- A book borrowed by a user cannot be deleted by the Librarian.
- A Student can borrow only upto 3 books. A Faculty can borrow only upto 5 books.
- A Fine of 10Rs is levied on Student over books owned for more than 15 days. No Fine is levied on Faculties but Faculties cannot borrow a book if they own a book for more than 60 days.
- When a book is returned, the fine is calculated from scratch to the date of returning and hence user can only pay fine properly by returning a book. The pay fine option available to the user can only pay partial fine but since the book is not returned, the fine will be freshly calculated and hence it is possible to get the same amount again while paying the fine on book return, assumption is that it doesn't make sense to pay some fine and not return a book because then more fine will be imposed again on the user, However after paying fine through the pay fine option, the user still won't be able to borrow book because the fine paid but the book is not returned. The pay fine option is not independent function but a subprocess of returning a book.
- If the librarian removes a user and if the books are not returned, then the books are still owned by the user. The user has to explicitly return books always to make the book available again.
- Librarians cannot delete themselves.
- A user cannot borrow a book if there is upaid fine.
- Since the interaction with the Library Management System allows users to have spaces in the title of books and names and passwords of users, which is implemented using `getline()` function, while providing the input the user should press `Enter` in the terminal after a new blank line to receive the next prompt. Similarly to give empty strings as inputs, the user should just press `Enter`.
- The Library Management System assumes the fine to be calculated using real date and time data. Hence the fine calculation with respect to the number of days must be done either by waiting for the time period or by modifying the Database or the code by adding more days than the fine period to check for fine.
- The confirmation message only accepts one Letter. If more than one letter is provided in the input, only the first letter will be considered.

## Author

- Hitarth Makawana

- 230479
