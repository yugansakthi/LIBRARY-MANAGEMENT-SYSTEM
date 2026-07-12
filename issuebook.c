#include "library.h"

void issuebook(struct book *bookhead, struct issue **issuehead)
{
    struct book *selectedbook, *tempbook;
    struct issue *newnode, *temp;
    char ch, op, choice;
    char bookname[50];
    int bookid;
    int id, flag, found;

    do
    {
        printf("\n********** Issue Book **********\n");
        printf("A. Search and Issue Book\n");
        printf("B. Back to Main Menu\n");
        printf("\nEnter your choice : ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case 'A':
            case 'a':
                break;

            case 'B':
            case 'b':
                return;

            default:
                printf("\nInvalid Choice. Please enter again.\n");
                continue;
        }

        printf("\nSearch Book By:\n");
        printf("1. Book ID\n");
        printf("2. Book Name\n");
        printf("Enter your choice : ");
        scanf(" %c", &choice);

        selectedbook = NULL;

        switch(choice)
        {
            case '1':

                printf("\nEnter Book ID : ");
                scanf("%d", &bookid);

                tempbook = bookhead;

                while(tempbook != NULL)
                {
                    if(tempbook->bookid == bookid)
                    {
                        selectedbook = tempbook;
                        break;
                    }

                    tempbook = tempbook->next;
                }

                break;

            case '2':

                printf("\nEnter Book Name : ");
                scanf(" %[^\n]", bookname);

                tempbook = bookhead;
                found = 0;

                printf("\n--------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s %-50s %-30s %-10s\n",
                       "Book ID", "Book Name", "Author", "Quantity");
                printf("--------------------------------------------------------------------------------------------------------------\n");

                while(tempbook != NULL)
                {
                    if(strcasecmp(tempbook->bookname, bookname) == 0)
                    {
                        printf("%-10d %-50s %-30s %-10d\n",
                               tempbook->bookid,
                               tempbook->bookname,
                               tempbook->author,
                               tempbook->quantity);

                        found = 1;
                    }

                    tempbook = tempbook->next;
                }

                printf("--------------------------------------------------------------------------------------------------------------\n");

                if(found == 0)
                {
                    printf("\nBook not found.\n");
                    continue;
                }

                printf("\nEnter the Book ID you want to issue : ");
                scanf("%d", &bookid);

                tempbook = bookhead;

                while(tempbook != NULL)
                {
                    if(tempbook->bookid == bookid &&
                       strcasecmp(tempbook->bookname, bookname) == 0)
                    {
                        selectedbook = tempbook;
                        break;
                    }

                    tempbook = tempbook->next;
                }

                break;

            default:
                printf("\nInvalid Choice.\n");
                continue;
        }

        if(selectedbook == NULL)
        {
            printf("\nBook not found.\n");
            continue;
        }

        if(selectedbook->quantity == 0)
        {
            printf("\nBook is currently unavailable.\n");
            continue;
        }

        newnode = (struct issue *)malloc(sizeof(struct issue));

        if(newnode == NULL)
        {
            printf("\nMemory Allocation Failed.\n");
            return;
        }

        id = 1;

        while(1)
        {
            flag = 0;
            temp = *issuehead;

            while(temp != NULL)
            {
                if(temp->issueid == id)
                {
                    flag = 1;
                    break;
                }

                temp = temp->next;
            }

            if(flag == 0)
                break;

            id++;
        }

        newnode->issueid = id;
        newnode->bookid = selectedbook->bookid;
        strcpy(newnode->bookname, selectedbook->bookname);

        printf("\nEnter User ID : ");
        scanf("%d", &newnode->userid);

        printf("Enter User Name : ");
        scanf(" %[^\n]", newnode->username);

        getCurrentDate(newnode->issuedate);
        calculateDueDate(newnode->issuedate, newnode->duedate);

        strcpy(newnode->returndate, "");
        newnode->fine = 0;
        newnode->returned = 0;
        newnode->next = NULL;

        selectedbook->quantity--;

        if(*issuehead == NULL)
        {
            *issuehead = newnode;
        }
        else
        {
            temp = *issuehead;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }

        printf("\nBook Issued Successfully.\n");
        printf("\nDo you want to issue another book? (Y/N): ");
        scanf(" %c", &op);

    } while(op == 'Y' || op == 'y');
}
