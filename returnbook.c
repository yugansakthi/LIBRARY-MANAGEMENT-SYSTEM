#include "library.h"
void returnbook(struct book *bookhead, struct issue *issuehead)
{
	struct issue *tempissue;
	struct book *tempbook;
	int bookid, userid;
	int flag;
	char op;
	if(bookhead==NULL)
	{
		printf("\nNo books available.\n");
		return;
	}
	if(issuehead==NULL)
	{
		printf("\nNo books have been issued.\n");
		return;
	}
	do
	{
		printf("\nEnter Book ID : ");
		scanf("%d", &bookid);
		printf("Enter User ID : ");
		scanf("%d", &userid);
		tempissue=issuehead;
		flag = 0;
		while(tempissue!=NULL)
		{
			if(tempissue->bookid==bookid &&tempissue->userid==userid &&tempissue->returned==0)
			{
				flag=1;
				break;
			}
			tempissue=tempissue->next;
		}
		if(flag==0)
		{
			printf("\nIssue Record Not Found.\n");
			printf("\nDo you want to return another book? (Y/N): ");
			scanf(" %c", &op);
			continue;
		}
		getCurrentDate(tempissue->returndate);
		tempissue->fine=calculateFine(tempissue->duedate,tempissue->returndate);
		tempissue->returned=1;
		tempbook=bookhead;
		while(tempbook!=NULL)
		{
			if(tempbook->bookid==bookid)
			{
				tempbook->quantity++;
				break;
			}
			tempbook=tempbook->next;
		}
		printf("\nBook Returned Successfully.\n");
		if(tempissue->fine>0)
			printf("Fine Amount : Rs.%d\n",tempissue->fine);
		else
			printf("No Fine.\n");
		printf("\nDo you want to return another book? (Y/N): ");
		scanf(" %c", &op);
	} while(op=='Y'||op=='y');
}
