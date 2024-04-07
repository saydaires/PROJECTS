#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int code = 0;

typedef struct 
{
	char nameProduct[50];
	char brandProduct[50];
	int serialNumber;
	int yearFabrication;
	float price;
	
} Products;

Products product[3];

void registerProduct()
{
	int answer;
	do
	{
		printf("\t### REGISTER MENU ###\n\n");
		printf("PRODUCT CODE #%d\n\n", code);
		printf("NAME PRODUCT: ");
		gets(product[code].nameProduct);
		fflush(stdin);
		printf("BRAND PRODUCT: ");
		gets(product[code].brandProduct);
		fflush(stdin);
		printf("SERIAL NUMBER: ");
		scanf("%d", &product[code].serialNumber);
		fflush(stdin);
		printf("YEAR FABRICATION: ");
		scanf("%d", &product[code].yearFabrication);
		fflush(stdin);
		printf("PRICE: US$ ");
		scanf("%f", &product[code].price);
		fflush(stdin);
		code++;
		system("cls");
		printf("PRODUCT REGISTER WITH SUCESS!\nPRESS <ENTER> TO CONTINUE...");
		getchar();
		fflush(stdin);
		system("cls");
		
		printf("DESCRIPTION PRODUCT #%d:\n\n", code - 1);
		printf("NAME PRODUCT: %s\n", product[code - 1].nameProduct);
		printf("BRAND PRODUCT: %s\n", product[code - 1].brandProduct);
		printf("SERIAL NUMBER: %d\n", product[code - 1].serialNumber);
		printf("YEAR FABRICATION: %d\n", product[code - 1].yearFabrication);
		printf("PRICE: US$ %.2f\n", product[code - 1].price);
		printf("\n\nPRESS <ENTER> TO CONTINUE...");
		getchar();
		fflush(stdin);
		system("cls");
		
		if(code == 3)
		{
			system("cls");
			printf("SYSTEM FULL!\nUNABLE MORE DO REGISTER\n\n");
			printf("PRESS <ENTER> TO RETURN OPTION MENU...");
			getchar();
			fflush(stdin);
			system("cls");
			break;
		}
		
		printf("\nCONTINUE PROCESS REGISTER? (1- YES|0- RETURN MENU):\n--> ");
		scanf("%d", &answer);
		fflush(stdin);
		if(answer != 0)
		{
			system("cls");
		}
		
	} while(answer != 0);	
}

void searchProduct()
{
	if(code == 0)
	{
		printf("NOT FOUND PRODUCTS IN THE SYSTEM!\n\n");
		printf("PRESS <ENTER> TO RETURN MENU...");
		getchar();
		fflush(stdin);
		system("cls");
	}
	else
	{
		int option;
		do
		{
			int codeTyped;
			printf("\t### MENU SEARCH ###\n\n");
			printf("ENTER CODE PRODUCT (O TO 2): ");
			scanf("%d", &codeTyped);
			if(codeTyped >= 0 && codeTyped <= 2)
			{
				if(codeTyped == code - 1 || codeTyped == code - 2 || codeTyped == code - 3)
				{
					system("cls");
					printf("DESCRIPTION PRODUCT #%d:\n\n", codeTyped);
					printf("NAME PRODUCT: %s\n", product[codeTyped].nameProduct);
					printf("BRAND PRODUCT: %s\n", product[codeTyped].brandProduct);
					printf("SERIAL NUMBER: %d\n", product[codeTyped].serialNumber);
					printf("YEAR FABRICATION: %d\n", product[codeTyped].yearFabrication);
					printf("PRICE: US$ %.2f\n", product[codeTyped].price);
					printf("\nCONTINUE SEARCH? (1- YES|0- RETURN MENU):\n--> ");
					scanf("%d", &option);
					system("cls");
				}
				else
				{
					system("cls");
					printf("ERROR #01: CODE YET NO REGISTERED!\n");
					printf("REGISTER THE CODE AND COME BACK VIEW THE PRODUCT!\n\n");
					printf("DO AGAIN SEARCH? (1- YES|0- RETURN MENU):\n--> ");
					scanf("%d", &option);
					system("cls");
				}
				
			}
			else
			{
				system("cls");
				printf("ERROR #02: INVALID CODE!\n");
				printf("THERES PRODUCT WAS NOT FOUND IN THE SYSTEM!\n\n");
				printf("DO AGAIN SEARCH? (1- YES|0- RETURN MENU):\n--> ");
				scanf("%d", &option);
				system("cls");
			}
		} while(option != 0);
	}	
}

int main()
{
	int option;
	do
	{
		printf("\t#### OPTION MENU ###\n\n");
		printf("1 - REGISTER NEW PRODUCT\n2 - SEARCH PRODUCT\n");
		printf("3 - EXIT MENU\n\nOPTION --> ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option)
		{
			case 1:
				if(code < 3)
				{
					system("cls");
					registerProduct();
					system("cls");
				}
				else
				{
					system("cls");
					printf("SYSTEM FULL!\nUNABLE MORE DO REGISTER\n\n");
					printf("PRESS <ENTER> TO RETURN OPTION MENU...");
					getchar();
					fflush(stdin);
					system("cls");
				}
			break;
			
			case 2:
				system("cls");
				searchProduct();
			break;		
		}		
	} while(option != 3);
	
	system("cls");
	printf("Off System...\nPRESS <ENTER> TO EXIT: ");
	getchar();
	fflush(stdin);
	
	return 0;
}
