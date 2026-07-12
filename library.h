#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<strings.h>
#include <time.h>

struct book
{
	int bookid;
	char bookname[50];
	char author[30];
	int quantity;
	struct book *next;
};

struct issue
{
	int issueid;
	int bookid;
	char bookname[50];
	int userid;
	char username[30];
	char issuedate[20];
	char duedate[20];
	char returndate[20];
	int fine;
	int returned;
	struct issue *next;
};

void addbook(struct book **head);
void updatebook(struct book *head);
void removebook(struct book **head);
void searchbook(struct book *head);
void viewbook(struct book *head);

void issuebook(struct book *bookHead, struct issue **issueHead);
void returnbook(struct book *bookHead, struct issue *issueHead);
void listIssuedBooks(struct issue *issueHead);

void savebook(struct book *head);
struct book *loadbook();

void saveissues(struct issue *head);
struct issue *loadissues();

void getCurrentDate(char date[]);
void calculateDueDate(char issueDate[], char dueDate[]);
int calculateFine(char dueDate[], char returnDate[]);
void lib_exit(struct book *bookhead,struct issue *issuehead);

