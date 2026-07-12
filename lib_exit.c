#include"library.h"
void lib_exit(struct book *bookhead,struct issue *issuehead)
{
	char ch;
	while(1)
	{
		printf("\nExit Menu\n");
		printf("S/s : Save and Exit\n");
		printf("E/e : Exit without Saving\n");
		printf("Enter Your Choice: ");
		scanf(" %c", &ch);
		switch(ch)
		{
			case 'S':
			case 's':
				savebook(bookhead);
				saveissues(issuehead);
				printf("Exiting...\n");
				exit(0);
				break;
			case 'E':
			case 'e':
				printf("Exiting without saving...\n");
				exit(0);
				break;
			default:
				printf("Invalid Choice. Please enter S/s or E/e.\n");
				break;
		}
	}
}
