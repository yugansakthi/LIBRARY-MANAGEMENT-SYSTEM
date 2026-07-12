#include"library.h"
struct book *loadbook()
{
	FILE *fp=fopen("book.dat","rb");
	if(fp==NULL)
		return NULL;
	struct book* hptr=NULL;
	struct book* temp=NULL;
	struct book* newnode;
	while(1)
	{
		newnode=(struct book*)malloc(sizeof(struct book));
		if(fread(newnode,sizeof(struct book),1,fp)!=1)
		{
			free(newnode);
			break;
		}
		newnode->next=NULL;
		if(hptr==NULL)
			hptr=temp=newnode;
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	fclose(fp);
	return hptr;
}
