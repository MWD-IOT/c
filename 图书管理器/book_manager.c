#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 50

typedef struct {
    int book_id;
    char title[50];
    char author[50];
    int is_available; // 1 if available, 0 if checked out
} Book;

typedef struct {
    int user_id;
    char name[50];
    int books_checked_out[MAX_BOOKS];
    int num_books_checked_out;
} User;

Book library[MAX_BOOKS];
User users[MAX_USERS];
int num_books = 0;
int num_users = 0;

// Function prototypes
void addBook();
void addUser();
void displayBooks();
void displayUsers();
void checkoutBook();
void returnBook();

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Add User\n");
        printf("3. Display Books\n");
        printf("4. Display Users\n");
        printf("5. Checkout Book\n");
        printf("6. Return Book\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addUser();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                displayUsers();
                break;
            case 5:
                checkoutBook();
                break;
            case 6:
                returnBook();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

void addBook() {
    if (num_books < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf("%s", library[num_books].title);

        printf("Enter author name: ");
        scanf("%s", library[num_books].author);

        library[num_books].book_id = num_books + 1;
        library[num_books].is_available = 1;

        printf("Book added successfully. Book ID: %d\n", library[num_books].book_id);
        num_books++;
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void addUser() {
    if (num_users < MAX_USERS) {
        printf("Enter user name: ");
        scanf("%s", users[num_users].name);

        users[num_users].user_id = num_users + 1;
        users[num_users].num_books_checked_out = 0;

        printf("User added successfully. User ID: %d\n", users[num_users].user_id);
        num_users++;
    } else {
        printf("User limit reached. Cannot add more users.\n");
    }
}

void displayBooks() {
    printf("\nBooks in the library:\n");
    printf("ID\tTitle\t\tAuthor\t\tAvailability\n");

    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", library[i].book_id, library[i].title, library[i].author,
               library[i].is_available ? "Available" : "Checked Out");
    }
}

void displayUsers() {
    printf("\nUsers in the system:\n");
    printf("ID\tName\t\tBooks Checked Out\n");

    for (int i = 0; i < num_users; i++) {
        printf("%d\t%s\t\t%d\n", users[i].user_id, users[i].name, users[i].num_books_checked_out);
    }
}

void checkoutBook() {
    int bookId, userId;

    printf("Enter Book ID to checkout: ");
    scanf("%d", &bookId);

    if (bookId <= 0 || bookId > num_books) {
        printf("Invalid Book ID.\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d", &userId);

    if (userId <= 0 || userId > num_users) {
        printf("Invalid User ID.\n");
        return;
    }

    if (library[bookId - 1].is_available && users[userId - 1].num_books_checked_out < MAX_BOOKS) {
        library[bookId - 1].is_available = 0;
        users[userId - 1].books_checked_out[users[userId - 1].num_books_checked_out++] = bookId;

        printf("Book checked out successfully.\n");
    } else {
        printf("Book is not available for checkout or user has reached the maximum limit of checked out books.\n");
    }
}

void returnBook() {
    int bookId, userId;

    printf("Enter Book ID to return: ");
    scanf("%d", &bookId);

    if (bookId <= 0 || bookId > num_books) {
        printf("Invalid Book ID.\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d", &userId);

    if (userId <= 0 || userId > num_users) {
        printf("Invalid User ID.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < users[userId - 1].num_books_checked_out; i++) {
        if (users[userId - 1].books_checked_out[i] == bookId) {
            found = 1;
            break;
        }
    }

    if (found) {
        library[bookId - 1].is_available = 1;

        for (int i = 0; i < users[userId - 1].num_books_checked_out; i++) {
            if (users[userId - 1].books_checked_out[i] == bookId) {
                // Remove the returned book from the user's checked out books
                for (int j = i; j < users[userId - 1].num_books_checked_out - 1; j++) {
                    users[userId - 1].books_checked_out[j] = users[userId - 1].books_checked_out[j + 1];
                }
                users[userId - 1].num_books_checked_out--;
                break;
            }
        }

        printf("Book returned successfully.\n");
    } else {
        printf("User has not checked out this book.\n");
    }
}
