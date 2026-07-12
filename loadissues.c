#include"library.h"
struct issue *loadissues()
{
	FILE *fp=fopen("issue.dat","rb");
	if(fp==NULL)
		return NULL;
	struct issue* hptr=NULL;
	struct issue* temp=NULL;
	struct issue* newnode;
	while(1)
	{
		newnode=(struct issue*)malloc(sizeof(struct issue));
		if(fread(newnode,sizeof(struct issue),1,fp)!=1)
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
