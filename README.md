
# Library Automation System

Subject: In this project, a small-scale and file-based Library Automation application will be implemented based on the working logic of relational databases.

Functional Requirements:

1- Author Add/Delete/Edit/List Operations: The name and surname of each author, and the authorID information that will be automatically increased (1, 2, .., N) with each new author record, must be stored in a ONE-WAY LINKED LIST ordered by the authorID value in a file called Authors.csv. The information collected from the user for authors and stored in the file can be deleted or corrected if requested and the latest version must be found in the same file.

2- Student Add/Delete/Edit/List Operations: Each student must have a name, surname, library score of 100 at the beginning, and a unique 8-digit student number. The information about students must be stored in a TWO-WAY LINKED LIST and in a file named Students.csv, defined by the struct structure within the application. The stored information can be deleted or corrected if requested and the latest version must be found in the same file.

3- Book Add/Delete/Edit/List Operations: Each book must have a name, a 13-digit ISBN number, and an information on the quantity. Since there may be multiple copies of a book in the library, a unique tag number with the number added automatically ISBN_1, ISBN_2, ISBN_N must be given to each sample book during the record creation. Books must be stored using a ONE-WAY LINKED LIST (struct Book) first by their names and then by ISBN numbers. For each book, a ONE-WAY LINKED LIST (struct BookCopy) must be created for the book's information, as many times as the number of samples, and this list must store the book's tag number and the book's borrowing status. In this context, if the book is borrowed, the ID number of the student who borrowed it should be included. If the book is not borrowed, the SHELF information should be written in this field.

4- Book - Author Association Operations: Taking into account that a book can be written by multiple authors and an author can write multiple books, the Book ISBN - Author ID match must be made. This information should be stored in the BookAuthor.csv. A struct should be designed for the data to be recorded in the reading operations to be performed on this file. After N spaces have been created for the data to be saved, the data must be saved in a dynamic struct array with N elements. An author can write many books, while a book can be written by many authors.

Note 1: When the author information introduced in Item-1 is deleted from the system, an update must be made in the file. In this field, -1 must be written, since the relevant author will no longer exist.
Note 2: In the Book - Author association operations, if the author is not registered, the process must be stopped.

5-Student Book Borrowing Processes: While a student can borrow a large number of books, a book can also be borrowed by a large number of students at different times. Therefore, this information must be kept in a consistent manner. Design a CSV file that keeps track of the borrowing and returning status of each book sample and a corresponding struct. This data structure must store the StudentID, BookLabelNO, Transaction Type, and Date Information. The transaction type information should be coded as BORROWED - 0 or RETURNED - 1. Additionally, when a book is borrowed, as explained in Article 3, the Shelf Status Information of a book should be updated in the relevant files and data structures as either On the Shelf or StudentNo.

NOTE 1: No transactions should be made for an unregistered student or book in book borrowing and return processes, and a warning should be issued. Necessary controls should be made for data consistency. Also, if a student's Score Information is negative, the transaction should be canceled with a "book cannot be issued" warning.

NOTE 2: If a book is returned more than 15 days after it was borrowed, the student should be penalized with -10 penalty points, and this information should be updated in the relevant files and data structures.

NOTE 3: During book borrowing processes, if all copies of a book have been borrowed by other students, a FAILED TRANSACTION warning should be issued.

Required menus in the program:
STUDENT OPERATIONS:
- Add, Delete, Update Student: All information related to the student should be taken from the user, and Add/Delete/Update operations should be performed separately on files and linked lists.
- View Student Information: The personal information of the student (Name, Surname, ID, Score, etc.) and all book transactions should be listed based on the ID information or Name-Surname information received from the user.
- List Students Who Haven't Returned Books:
- List Punished Students:
- List All Students:
- Borrow/Return Book
BOOK OPERATIONS:
- Add, Delete, Update Book: All information related to the books should be taken from the user, and Add/Delete/Update operations should be performed separately on files and linked lists.
- View Book Information: All information about each book and its sample copies based on the Book Name information received from the user should be listed.
- List Books on Shelf:
- List Books Not Returned on Time:
- Match Book-Author: The related file and struct array should be updated.
- Update Book's Author: The related file and struct array should be updated.
AUTHOR OPERATIONS:
- Add, Delete, Update Author: All information related to the authors should be taken from the user, and Add/Delete/Update operations should be performed separately on files and linked lists.
- View Author Information: All information about each author and all information about the books related to this author based on the Author Name information received from the user should be listed.
