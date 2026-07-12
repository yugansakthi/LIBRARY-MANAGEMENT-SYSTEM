#include"library.h"
void viewbook(struct book* ptr)
{
	if(ptr==NULL){
		printf("\nRecords not found\n");
		return;
	}
	printf("--------------------------------------------------------------------------\n");
	printf("%-10s %-30s %-20s %-10s\n","BookID","Title","Author","Quantity");
	printf("--------------------------------------------------------------------------\n");
	while (ptr!=NULL)
	{
		printf("%-10d %-30s %-20s %-10d\n",ptr->bookid,ptr->bookname,ptr->author,ptr->quantity);
		ptr=ptr->next;
	}
	printf("--------------------------------------------------------------------------\n");
}
