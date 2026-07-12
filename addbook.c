#include "library.h"
void addbook(struct book **head)
{
	char bookname[50], author[30];
	char op;
	do
	{
		printf("\nEnter book Title : ");
		scanf(" %[^\n]", bookname);
		printf("Enter Author Name : ");
		scanf(" %[^\n]", author);
		struct book *temp=*head;
		while (temp!=NULL)
		{
			if (strcasecmp(bookname,temp->bookname)==0&&strcasecmp(author,temp->author)==0)
			{
				temp->quantity++;          
				printf("\nBook already exists. Quantity updated.\n");
				break;
			}
			temp = temp->next;
		}
		if (temp==NULL)
		{
			struct book *newnode = (struct book *)malloc(sizeof(struct book));
			int id = 1;
			int flag;
			while (1)
			{
				flag=0;
				temp=*head;
				while(temp!=NULL)
				{
					if (temp->bookid==id)
					{
						flag = 1;
						break;
					}
					temp = temp->next;
				}
				if (!flag)
					break;
				id++;
			}
			newnode->bookid=id;
			strcpy(newnode->bookname,bookname);
			strcpy(newnode->author,author);
			newnode->quantity=1;
			newnode->next=NULL;
			if (*head==NULL||(*head)->bookid>newnode->bookid)
			{
				newnode->next=*head;
				*head=newnode;
			}
			else
			{
				struct book *prev=*head;
				temp=(*head)->next;
				while (temp!=NULL&&temp->bookid<newnode->bookid)
				{
					prev=temp;
					temp=temp->next;
				}
				prev->next=newnode;
				newnode->next=temp;
			}
			printf("\nNew book added successfully.\n");
		}
		printf("\nDo you want to add another book? (Y/N): ");
		scanf(" %c", &op);
	} while (op=='Y'||op=='y');
}
