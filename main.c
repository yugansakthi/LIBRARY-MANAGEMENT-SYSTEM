#include "library.h"

int main()
{
    char ch;

    struct book *bookhead = NULL;
    struct issue *issuehead = NULL;

    bookhead = loadbook();
    issuehead = loadissues();

    while(1)
    {
        printf("\n----------------------------------------\n");
        printf("|          Book Management Menu          |\n");
        printf("------------------------------------------\n");
        printf("| 1. Add New Book                        |\n");
        printf("| 2. Update Book Details                 |\n");
        printf("| 3. Remove Book                         |\n");
        printf("| 4. Search Book                         |\n");
        printf("| 5. View All Books                      |\n");
        printf("| 6. Issue Book                          |\n");
        printf("| 7. Return Book                         |\n");
        printf("| 8. List Issued Books                   |\n");
        printf("| 9. Save                                |\n");
        printf("| 0. Exit                                |\n");
        printf("------------------------------------------\n");

        printf("Enter your choice : ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case '1':
                addbook(&bookhead);
                break;

            case '2':
                updatebook(bookhead);
                break;

            case '3':
                removebook(&bookhead);
                break;

            case '4':
                searchbook(bookhead);
                break;

            case '5':
                viewbook(bookhead);
                break;

            case '6':
                issuebook(bookhead, &issuehead);
                break;

            case '7':
                returnbook(bookhead, issuehead);
                break;

            case '8':
                listIssuedBooks(issuehead);
                break;

            case '9':
                savebook(bookhead);
                saveissues(issuehead);
                printf("\nData saved successfully.\n");
                break;

            case '0':
                lib_exit(bookhead, issuehead);
                return 0;

            default:
                printf("\nInvalid Choice. Please enter again.\n");
                break;
        }
    }
}
