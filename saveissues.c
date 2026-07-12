#include"library.h"
void saveissues(struct issue *head)
{
	struct issue *temp=head;
	FILE *fp=fopen("issue.dat","wb");
	while(temp){
		fwrite(temp,sizeof(struct issue),1,fp);
		temp=temp->next;
	}
	fclose(fp);
	printf("Issue Records are saved\n");
}


