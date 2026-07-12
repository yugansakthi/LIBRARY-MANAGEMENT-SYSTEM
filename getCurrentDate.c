#include"library.h"
void getCurrentDate(char date[])
{
	time_t t;
	struct tm *current;
	t=time(NULL);
	current=localtime(&t);
	sprintf(date,"%02d-%02d-%04d",current->tm_mday,current->tm_mon+1,current->tm_year+1900);
}
