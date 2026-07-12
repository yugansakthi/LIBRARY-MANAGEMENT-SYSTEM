#include "library.h"
void searchbook(struct book *head)
{
    char ch;
    int id, flag;
    char bookname[50], authorname[30];
    struct book *temp;
    while(1)
    {
        printf("\n********** Search Book **********\n");
        printf("A. Book ID\n");
        printf("B. Book Name\n");
        printf("C. Author Name\n");
        printf("D. Back to Main Menu\n");
        printf("\nEnter your choice : ");
        scanf(" %c",&ch);

        switch(ch)
        {
            case 'A':
            case 'a':
                printf("\nEnter Book ID : ");
                scanf("%d", &id);
                temp=head;
                flag = 0;
                printf("\n--------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s %-50s %-30s %-10s\n","Book ID", "Book Name", "Author", "Quantity");
                printf("--------------------------------------------------------------------------------------------------------------\n");
                while(temp!=NULL)
                {
                    if(temp->bookid==id)
                    {
                        printf("%-10d %-50s %-30s %-10d\n",temp->bookid,temp->bookname,temp->author,temp->quantity);
                        flag=1;
                    }
                    temp=temp->next;
                }
                printf("--------------------------------------------------------------------------------------------------------------\n");
                if(flag==0)
                    printf("\nBook ID not found.\n");
                break;
            case 'B':
            case 'b':
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]",bookname);
                temp=head;
                flag=0;
                printf("\n--------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s %-50s %-30s %-10s\n","Book ID", "Book Name", "Author", "Quantity");
                printf("--------------------------------------------------------------------------------------------------------------\n");
                while(temp!=NULL)
                {
                    if(strcasecmp(temp->bookname,bookname)==0)
                    {
                        printf("%-10d %-50s %-30s %-10d\n",temp->bookid,temp->bookname,temp->author,temp->quantity);
                        flag = 1;
                    }
                    temp=temp->next;
                }
                printf("--------------------------------------------------------------------------------------------------------------\n");
                if(flag==0)
                    printf("\nBook Name not found.\n");
                break;
            case 'C':
            case 'c':
                printf("\nEnter Author Name : ");
                scanf(" %[^\n]",authorname);
                temp=head;
                flag=0;
                printf("\n--------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s %-50s %-30s %-10s\n","Book ID", "Book Name", "Author", "Quantity");
                printf("--------------------------------------------------------------------------------------------------------------\n");
                while(temp!=NULL)
                {
                    if(strcasecmp(temp->author,authorname)==0)
                    {
                        printf("%-10d %-50s %-30s %-10d\n",temp->bookid,temp->bookname,temp->author,temp->quantity);
                        flag=1;
                    }
                    temp=temp->next;
                }
                printf("--------------------------------------------------------------------------------------------------------------\n");
                if(flag==0)
                    printf("\nAuthor Name not found.\n");
                break;
            case 'D':
            case 'd':
                return;
            default:
                printf("\nInvalid Choice. Please enter again.\n");
        }
    }
}
