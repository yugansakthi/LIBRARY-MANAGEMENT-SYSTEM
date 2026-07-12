#include"library.h"
int calculateFine(char dueDate[], char returnDate[])
{
	int d1,m1,y1;
	int d2,m2,y2;
	struct tm due = {0};
	struct tm ret = {0};
	time_t duetime;
	time_t returntime;
	double difference;
	int latedays;
	sscanf(dueDate,"%d-%d-%d",&d1,&m1,&y1);
	sscanf(returnDate,"%d-%d-%d",&d2,&m2,&y2);
	due.tm_mday=d1;
	due.tm_mon=m1-1;
	due.tm_year=y1-1900;
	ret.tm_mday=d2;
	ret.tm_mon=m2-1;
	ret.tm_year=y2-1900;
	duetime=mktime(&due);
	returntime = mktime(&ret);
	difference = difftime(returntime,duetime);
	latedays=(int)(difference/(60*60*24));
	if(latedays>0)
		return latedays * 2;
	return 0;
}
