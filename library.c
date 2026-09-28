#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for storing book details
struct Book
{
    int id;
    char name[50];
    char author[50];
    int status;       // 0 = Available, 1 = Issued
};

struct Book books[MAX];
int count = 0;


// Function to add a book
void addBook()
{
    if (count >= MAX)
    {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].status = 0;

    count++;

    printf("\nBook added successfully!\n");
}


// Function to search a book
void searchBook()
{
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            printf("\nBook Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);

            if (books[i].status == 0)
                printf("Status: Available\n");
            else
                printf("Status: Issued\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}


// Function to issue a book
void issueBook()
{
    int id, i, found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            if (books[i].status == 0)
            {
                books[i].status = 1;
                printf("\nBook issued successfully!\n");
            }
            else
            {
                printf("\nBook is already issued!\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}


// Function to return a book
void returnBook()
{
    int id, i, found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            if (books[i].status == 1)
            {
                books[i].status = 0;
                printf("\nBook returned successfully!\n");
            }
            else
            {
                printf("\nBook is already available!\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}


// Function to delete a book
void deleteBook()
{
    int id, i, j, found = 0;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            // Shift remaining records
            for (j = i; j < count - 1; j++)
            {
                books[j] = books[j + 1];
            }

            count--;

            printf("\nBook deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}


// Function to display all books
void displayBooks()
{
    int i;

    if (count == 0)
    {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n========== LIBRARY BOOK RECORDS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nBook ID     : %d", books[i].id);
        printf("\nBook Name   : %s", books[i].name);
        printf("\nAuthor      : %s", books[i].author);

        if (books[i].status == 0)
            printf("\nStatus      : Available\n");
        else
            printf("\nStatus      : Issued\n");

        printf("-----------------------------------------\n");
    }
}


// Main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========== LIBRARY MANAGEMENT SYSTEM ==========");
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Delete Book");
        printf("\n6. Display All Books");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                searchBook();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                displayBooks();
                break;

            case 7:
                printf("\nThank you for using Library Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
        
        

