# Library Management System

**Library Management System** developed in **C** using **Singly Linked Lists**. This project allows users to efficiently manage library books and book issue records with features like adding, updating, removing, searching, issuing, returning, viewing, and saving records using binary files.

## Features

### Add Book

- Automatically assigns the **smallest available Book ID**.
- Accepts Book Title and Author Name.
- If the same book (same title and author) already exists, its quantity is incremented.
- Otherwise, a new book node is dynamically created and inserted into the linked list.

### Update Book

Search books using:

- Book ID
- Book Name

Modify:

- Book Title
- Author Name
- Quantity

### Remove Book

Remove books using:

- Book ID
- Book Name


### Search Book

Search books using:

- Book ID
- Book Name
- Author Name

Displays all matching book records in a formatted table.

### View Books

- Displays all available books in a formatted table.
- Shows Book ID, Book Title, Author Name, and Available Quantity.

### Issue Book

Search books using:

- Book ID
- Book Name

- Displays matching book records before issuing.
- Accepts User ID and User Name.
- Automatically records the Issue Date.
- Automatically calculates the Due Date (7 days from the issue date).
- Reduces the available quantity after successful issue.

### Return Book

- Returns books using Book ID and User ID.
- Automatically records the Return Date.
- Calculates overdue fine based on the Due Date.
- Fine is calculated at **Rs.2 per late day**.
- Increases the available quantity after successful return.

### List Issued Books

- Displays all issued book records.
- Shows Book ID, Book Title, User ID, User Name, Issue Date, Due Date, Return Date, and Fine.

### Save Records

- Saves all book records to `book.dat`.
- Saves all issued book records to `issue.dat`.
- Ensures data is preserved after the program is closed.

### Load Records

- Automatically loads book records from `book.dat`.
- Automatically loads issued book records from `issue.dat`.
- Dynamically reconstructs the linked lists during program startup.
- Ensures previously saved records are available.

### Exit Option

- Save and Exit
- Exit Without Saving

---
