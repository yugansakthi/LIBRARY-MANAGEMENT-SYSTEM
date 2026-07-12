#include"library.h"
void removebook(struct book **head)
{
	char ch;
	int id;
	char name[50];
	struct book *temp, *prev;
	while (1)
	{
		printf("\nA/a. Remove using Book ID");
		printf("\nB/b. Remove using Book Name");
		printf("\nC/c. Back to Main menu");
		printf("\nEnter your ch: ");
		scanf(" %c",&ch);
		if (ch=='A'||ch=='a')
		{
			while (1)
			{
				printf("Enter Book ID: ");
				scanf("%d",&id);
				temp=*head;
				prev=NULL;
				while(temp!=NULL)
				{
					if (temp->bookid==id)
					{
						if (prev==NULL)
							*head=temp->next;
						else
							prev->next=temp->next;
						free(temp);
						return;
					}
					prev=temp;
					temp=temp->next;
				}
				printf("Invalid Book ID. Please enter again.\n");
			}
		}
		else if (ch=='B'||ch=='b')
		{
			while (1)
			{
				printf("Enter Book Name: ");
				scanf(" %[^\n]", name);
				temp=*head;
				prev=NULL;
				while(temp!=NULL)
				{
					if(strcasecmp(temp->bookname,name)==0)
					{
						if (prev==NULL)
							*head=temp->next;
						else
							prev->next=temp->next;
						free(temp);
						return;
					}
					prev=temp;
					temp=temp->next;
				}
				printf("Invalid Book Name. Please enter again.\n");
			}
		}
		else if(ch=='C'||ch=='c')
		{
			return;
		}
		else
		{
			printf("Invalid choice. Please enter valid choice displayed on the screen.\n");

		}
	}
}
