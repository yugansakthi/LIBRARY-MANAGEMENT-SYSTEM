#include"library.h"
void savebook(struct book *head)
{
	struct book *temp=head;
	FILE *fp=fopen("book.dat","wb");
	while(temp){
		fwrite(temp,sizeof(struct book),1,fp);
		temp=temp->next;
	}
	fclose(fp);
	printf("Book Records are saved\n");
}

