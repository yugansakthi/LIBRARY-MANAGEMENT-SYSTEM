#include "library.h"
void updatebook(struct book *head)
{
	struct book *temp,*modify=NULL;
	int id, choice,flag;
	char name[50];
	char search, ch;
	do
	{
		printf("\n========== UPDATE BOOK ==========");
		printf("\n1. Search by Book ID");
		printf("\n2. Search by Book Name");
		printf("\n3. Back to Main Menu");
		printf("\nEnter your choice: ");
		scanf(" %c", &search);
		switch(search)
		{
			case '1':
				while(1)
				{
					printf("\nEnter Book ID: ");
					scanf("%d",&id);
					temp=head;
					flag=0;
					while(temp!=NULL)
					{
						if(temp->bookid==id)
						{
							modify=temp;
							flag=1;
							break;
						}
						temp=temp->next;
					}
					if(flag)
						break;
					printf("\nInvalid Book ID! Please enter again.\n");
				}
				printf("\n--------------------------------------------------------------------------------");
				printf("\n%-10s %-25s %-25s %-10s","Book ID", "Book Name", "Author Name", "Quantity");
				printf("\n--------------------------------------------------------------------------------");
				printf("\n%-10d %-25s %-25s %-10d",modify->bookid,modify->bookname,modify->author,modify->quantity);
				printf("\n--------------------------------------------------------------------------------\n");
				break;
			case '2':
				while(1)
				{
					printf("\nEnter Book Name: ");
					scanf(" %[^\n]",name);
					temp=head;
					flag=0;
					while(temp!=NULL)
					{
						if(strcasecmp(temp->bookname, name) == 0)
						{
							if(flag==0)
							{
								printf("\n--------------------------------------------------------------------------------");
								printf("\n%-10s %-25s %-25s %-10s","Book ID", "Book Name", "Author Name", "Quantity");
								printf("\n--------------------------------------------------------------------------------");
							}
							printf("\n%-10d %-25s %-25s %-10d",temp->bookid,temp->bookname,temp->author,temp->quantity);
							flag = 1;
						}
						temp=temp->next;
					}
					if(flag)
					{
						printf("\n--------------------------------------------------------------------------------\n");
						break;
					}
					printf("\nInvalid Book name! Please enter again.\n");
				}
				while(1)
				{
					printf("\nEnter Book ID to Modify: ");
					scanf("%d",&id);
					temp=head;
					flag=0;
					while(temp!=NULL)
					{
						if(temp->bookid==id&&strcasecmp(temp->bookname,name)==0)
						{
							modify=temp;
							flag=1;
							break;
						}
						temp=temp->next;
					}
					if(flag)
						break;
					printf("\nInvalid Book ID! Please enter again.\n");
				}
				break;
			case '3':
				return;
			default:
				printf("\nInvalid Choice! Please enter again.\n");
				continue;
		}
		printf("\nModify Menu");
		printf("\n1. Book Name");
		printf("\n2. Author Name");
		printf("\n3. Quantity");
		printf("\n4. Back to Search Menu");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter New Book Name: ");
				scanf(" %[^\n]", modify->bookname);
				break;
			case 2:
				printf("\nEnter New Author Name: ");
				scanf(" %[^\n]", modify->author);
				break;
			case 3:
				printf("\nEnter New Quantity: ");
				scanf("%d", &modify->quantity);
				break;
			case 4:
				continue;
			default:
				printf("\nInvalid Choice!\n");
				continue;
		}
		printf("\nBook Updated Successfully.\n");
		printf("\nDo you want to update another book? (y/n): ");
		scanf(" %c",&ch);
	} while(ch=='y'||ch=='Y');
}
