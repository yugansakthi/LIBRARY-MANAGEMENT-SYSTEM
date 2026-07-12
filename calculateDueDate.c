#include"library.h"
void calculateDueDate(char issueDate[], char dueDate[])
{
	int day, month, year;
	struct tm date = {0};
	sscanf(issueDate,"%d-%d-%d",&day,&month,&year);
	date.tm_mday=day;
	date.tm_mon=month-1;
	date.tm_year=year-1900;
	mktime(&date);
	date.tm_mday+=7;
	mktime(&date);
	sprintf(dueDate,"%02d-%02d-%04d",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
}
