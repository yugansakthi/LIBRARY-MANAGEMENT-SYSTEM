#include"library.h"
void listIssuedBooks(struct issue *head)
{
	struct issue *temp=head;
	if(temp==NULL)
	{
		printf("\nIssued books not found.\n");
		return;
	}
	printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-8s %-30s %-8s %-20s %-15s %-15s %-15s %-8s\n","Book ID","Book Title","User ID","User Name","Issue Date","Due Date",
			"Return Date","Fine");
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	while(temp)
	{
		printf("%-8d %-30s %-8d %-20s %-15s %-15s %-15s %-8d\n",temp->bookid,temp->bookname,temp->userid,temp->username,temp->issuedate,temp->duedate,temp->returndate,
				temp->fine);
		temp = temp->next;
	}
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
}
