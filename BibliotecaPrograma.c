#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char Title[100];
	char Author[50];
	int yearPublication;
	float price;
} Book;

int main()
{
	Book book[10];
	int i, answer;
	for(i = 0; i < 10; i++)
	{
		printf("\t### Registration Book Process ###\n\n");
		printf("Title of Book #%d: ", i);
		gets(book[i].Title);
		
		printf("Author: ");
		gets(book[i].Author);
		
		printf("Year of Publication: ");
		scanf("%d", &book[i].yearPublication);
		
		printf("Price: US$ ");
		scanf("%f", &book[i].price);
		fflush(stdin);
		system("cls");
	}
	
	int switchMenu;
	do
	{
		switchMenu = 0;
		char nameBook[100];
		
		system("cls");
		printf("\t### MENU LIBRARY ###\n\n");
		printf("1 - SEARCH BOOK WITH CODE\n2 - SEARCH BOOK WITH NAME\n");
		printf("3 - EXIT MENU\n\n---> ");
		scanf("%d", &switchMenu);
		fflush(stdin);
	
		if(switchMenu == 1)
		{
			int answerCode;
			do {
				system("cls");
				printf("\t### MENU LIBRARY ###\n\n");
				int code;
				printf("Enter the Code Book (0 to 9): ");
				scanf("%d", &code);
				system("cls");
				if(code >= 0 && code <= 9)
				{
					printf("\t### MENU LIBRARY ###\n\n");
					printf("Book #%d Description:\n\n", code);
					printf("Name: %s\n", book[code].Title);
					printf("Author: %s\n", book[code].Author);
					printf("Year of Publication: %d\n", book[code].yearPublication);
					printf("Price: US$ %.2f\n\n", book[code].price);
					printf("Do you want to continue? (1 - YES | 0 - RETURN MENU): ");
					scanf("%d", &answerCode);
				}
				else
				{
					printf("ERROR: Invalid Code!\n");
					printf("Do you wanna Try again? (1 - YES | 0 - RETURN MENU): ");
					scanf("%d", &answerCode);
				}
			} while (answerCode == 1);
		}
		else if (switchMenu == 2)
		{
			int answerCode;
			
			do
			{
				char bookSearched[100];
				int positionBook = -1;
				
				system("cls");
				printf("\t### MENU LIBRARY ###\n\n");
				printf("Write searched book: ");
				gets(bookSearched);
				fflush(stdin);
			
				for(i = 0; i <= 9; i++)
				{
					if(strcmp(bookSearched, book[i].Title)==0)
					{
						positionBook = i;
						break;
					}
				}
				if(positionBook != -1)
				{
					printf("Description:\n\n");
					printf("Book Code #%d\n", positionBook);
					printf("Name: %s\n", book[positionBook].Title);
					printf("Author: %s\n", book[positionBook].Author);
					printf("Year of Publication: %d\n", book[positionBook].yearPublication);
					printf("Price: US$ %.2f\n\n", book[positionBook].price);
					printf("\n\nDo you want to continue? (1 - YES | 0 - RETURN MENU): ");
					scanf("%d", &answerCode);
					fflush(stdin);
				}
				else
				{
					printf("ERROR: Book not find!");
					printf("\n\nDo you wanna Try again? (1 - YES | 0 - RETURN MENU): ");
					scanf("%d", &answerCode);
					fflush(stdin);
				}
			
			} while(answerCode == 1);	
		}
	} while(switchMenu != 3);
	
	printf("Press <ENTER> to exit...");
	getchar();
	return 0;
}
