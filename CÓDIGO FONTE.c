#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char name[80];
	char adress[60];
	char phone[15];
	char email[45];
	
} Client;

Client client[3];
int code = 0;

void pauseExecution()
{
	printf("PRESS <ENTER> TO CONTINUE...");
	getchar();
	fflush(stdin);
	system("cls");
}

void addClient()
{
	int option;	
	do
	{
		printf("\t### REGISTER NEW CLIENT ###\n\n");
		printf("REMAINING REGISTERS: %d\n\n", 3 - code);
		printf("NAME: ");
		gets(client[code].name);
		fflush(stdin);
		printf("ADRESS: ");
		gets(client[code].adress);
		fflush(stdin);
		printf("PHONE: ");
		gets(client[code].phone);
		fflush(stdin);
		printf("EMAIL: ");
		gets(client[code].email);
		fflush(stdin);
		pauseExecution();
		printf("REGISTER REALIZES WITH SUCCESS!\n\n");
		printf("CODE OF CLIENT: #%d\n\n", code);
		code++;
		pauseExecution();
		
		if(code == 3)
		{
			system("cls");
			printf("SYSTEM FULL!\n\n");
			printf("UNABLE MORE REGISTER NEW CLIENT!\n\n");
			pauseExecution();
			break;
		}
		printf("ADD NEW CLIENT? (1 YES | 0 NO)\n--> ");
		scanf("%d", &option);
		fflush(stdin);
		system("cls"); 
	} while(option != 0);
}

void searchClient()
{
	if(code == 0)
	{
		printf("ERROR #A00: NO HAVE CODE REGISTERED IN SYSTEM!\n\n");
		pauseExecution();
	}
	else
	{
		int option;
		do
		{
			int codeTyped;
			printf("\t### MENU SEARCH CLIENT ###\n\n");
			printf("CODE OF CLIENT: ");
			scanf("%d", &codeTyped);
			fflush(stdin);
			if(codeTyped >= 0 && codeTyped <= 2)
			{
				if(codeTyped > (code-1))
				{
					printf("\nERROR #A02: THE SEARCHED CODE DONT HAVE REGISTERS!\n\n");
					printf("NEW SEARCH? (1 YES | 0 NO)\n--> ");
					scanf("%d", &option);
					system("cls");
				}
				else
				{
					printf("\n\nCLIENT #%d ALL INFORMATIONS:\n\n", codeTyped);
					printf("NAME: %s\n", client[codeTyped].name);
					printf("ADRESS: %s\n", client[codeTyped].adress);
					printf("PHONE: %s\n", client[codeTyped].phone);
					printf("EMAIL: %s\n\n", client[codeTyped].email);
					pauseExecution();
					printf("NEW SEARCH? (1 YES | 0 NO)\n--> ");
					scanf("%d", &option);
					system("cls");
				}
			}
			else
			{
				printf("\nERROR #A01: INVALID CODE!\n\n");
				printf("NEW SEARCH? (1 YES| 0 NO)\n--> ");
				scanf("%d", &option);
				system("cls");	
			}	
		} while(option != 0);
	}	
}

void editClient()
{
	if(code == 0)
	{
		printf("ERROR #A00: NO HAVE CLIENT REGISTERED IN SYSTEM!\n\n");
	    pauseExecution();
	}
	else
	{
		int optionLoopEdit;
		do
		{
			int codeTyped;
			printf("\t### MENU EDIT ###\n\n");
			fflush(stdin);
			printf("INSERT CODE OF WANTED CLIENT: ");
			scanf("%d", &codeTyped);
			fflush(stdin);
			system("cls");
			if(codeTyped >= 0 && codeTyped <= 2)
			{
				if(codeTyped > (code - 1 ))
				{
					printf("\nERROR #A02: THE SEARCHED CODE DONT HAVE REGISTERS!\n\n");
					printf("NEW SEARCH? (1 YES | 0 NO)\n--> ");
					scanf("%d", &optionLoopEdit);
					system("cls");
				}
				else
				{
					int optionClientEdit;
					do
					{
						int optionEdit, answerEditClient;
						system("cls");
						printf("\t### EDIT MENU ###\n\n");
						printf("CLIENT CODE #%d\n\n", codeTyped);
						printf("WHAT DO YOU WANNA EDIT?\n\n");
						printf("1- NAME\n2- ADRESS\n3- PHONE\n");
						printf("4- EMAIL\n--> ");
						scanf("%d", &optionEdit);
						fflush(stdin);
						
						switch(optionEdit)
						{
							case 1:
								system("cls");
								printf("CURRENT NAME: %s\n\n", client[codeTyped].name);
								printf("INSERT NEW NAME: ");
								gets(client[codeTyped].name);
								fflush(stdin);
								printf("\n\nEDITION DONE WITH SUCESS!\n");
								printf("NEW NAME: %s\n\n", client[codeTyped].name);
								printf("CONTINUE EDITING CLIENT #%d ? (1 YES | 0 NO) ", codeTyped);
								scanf("%d", &answerEditClient);
								if(answerEditClient != 0)
								{
									continue;
								}
								else
								{
									optionClientEdit = 0;
									optionLoopEdit = 0;
									system("cls");
								}
							break;
							
							case 2:
								system("cls");
								printf("CURRENT ADRESS: %s\n\n", client[codeTyped].adress);
								printf("INSERT NEW ADRESS: ");
								gets(client[codeTyped].adress);
								fflush(stdin);
								printf("\n\nEDITION DONE WITH SUCESS!\n");
								printf("NEW ADRESS: %s\n\n", client[codeTyped].adress);
								printf("CONTINUE EDITING CLIENT #%d ? (1 YES | 0 NO) ", codeTyped);
								scanf("%d", &answerEditClient);
								if(answerEditClient != 0)
								{
									continue;
								}
								else
								{
									optionClientEdit = 0;
									optionLoopEdit = 0;
									system("cls");
								}
							break;
							
							case 3:
								system("cls");
								printf("CURRENT PHONE: %s\n\n", client[codeTyped].phone);
								printf("INSERT NEW PHONE: ");
								gets(client[codeTyped].phone);
								fflush(stdin);
								printf("\n\nEDITION DONE WITH SUCESS!\n");
								printf("NEW PHONE: %s\n\n", client[codeTyped].phone);
								printf("CONTINUE EDITING CLIENT #%d ? (1 YES | 0 NO) ", codeTyped);
								scanf("%d", &answerEditClient);
								if(answerEditClient != 0)
								{
									continue;
								}
								else
								{
									optionClientEdit = 0;
									optionLoopEdit = 0;
									system("cls");
								}
							break;
							
							case 4:
								system("cls");
								printf("CURRENT EMAIL: %s\n\n", client[codeTyped].email);
								printf("INSERT NEW EMAIL: ");
								gets(client[codeTyped].email);
								fflush(stdin);
								printf("\n\nEDITION DONE WITH SUCESS!\n");
								printf("NEW EMAIL: %s\n\n", client[codeTyped].email);
								printf("CONTINUE EDITING CLIENT #%d ? (1 YES | 0 NO) ", codeTyped);
								scanf("%d", &answerEditClient);
								if(answerEditClient != 0)
								{
									continue;
								}
								else
								{
									optionClientEdit = 0;
									optionLoopEdit = 0;
									system("cls");
								}
							break;
							
							default:
								printf("INVALID OPTION!\n\n");
								pauseExecution();											
						}
					} while(optionClientEdit != 0);
				}
			}
			else
			{
				printf("ERROR #A01: INVALID CODE!\n\n");
				printf("DO INSERT AGAIN? (1 YES|0 NO)\n--> ");
				scanf("%d", &optionLoopEdit);
				system("cls");
			}
		} while(optionLoopEdit != 0);
	}	
}

void deleteClient()
{
	if(code == 0)
	{
		printf("ERROR #A00: NO HAVE CLIENT REGISTERED IN SYSTEM!\n\n");
	    pauseExecution();
	}
	else
	{
		int optionLoopDelete;
		do
		{
			int codeTyped;
			int optionFinal;
			printf("\t###DELETE MENU###\n\n");
			printf("CODE OF CLIENT WHAT BE DELETE: ");
			scanf("%d", &codeTyped);
			fflush(stdin);
			system("cls");
			if(codeTyped >= 0 && codeTyped <= 2)
			{
				if(codeTyped > (code - 1))
				{
					printf("\nERROR #A02: THE SEARCHED CODE DONT HAVE REGISTERS!\n\n");
					printf("NEW SEARCH? (1 YES | 0 NO)\n--> ");
					scanf("%d", &optionLoopDelete);
					system("cls");
				}
				else
				{
					printf("CLIENT #%d INFORMATIONS\n\n", codeTyped);
					printf("NAME: %s\n", client[codeTyped].name);				
					printf("ADRESS: %s\n", client[codeTyped].adress);				
					printf("PHONE: %s\n", client[codeTyped].phone);				
					printf("EMAIL: %s\n\n", client[codeTyped].email);
					printf("REALLY WANT DELETE THIS CLIENT? (1 YES | 0 NO): ");
					scanf("%d", &optionFinal);
					fflush(stdin);
					if(optionFinal == 0)
					{
						system("cls");
						optionLoopDelete = 0;	
					}
					else
					{
						int i;
						for(i = codeTyped; i < code - 1; i++)
						{
							client[i] = client[i+1];
						}
						code--;
						system("cls");
						printf("DELETE CLIENT WITH SUCESS!\n\n");
						pauseExecution();
						optionLoopDelete = 0;	
					}	
				}			
			}
			else
			{
				printf("ERROR #A01: INVALID CODE!\n\n");
				printf("DO INSERT AGAIN? (1 YES|0 NO)\n--> ");
				scanf("%d", &optionLoopDelete);
				system("cls");
			}
		} while(optionLoopDelete != 0);	
	}		
}

int main()
{
	int option;
	do
	{
		printf("\t### CENTRAL MENU ###\n\n");
		printf("1- ADD NEW CLIENT\n2- SEARCH CLIENT\n");
		printf("3- EDIT CLIENT\n4- DELETE CLIENT\n");
		printf("0- EXIT MENU\n\nINSERT OPTION --> ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option)
		{
			case 1:
				if(code == 3)
				{
					system("cls");
					printf("SYSTEM FULL!\n\n");
					printf("UNABLE MORE REGISTER NEW CLIENT!\n\n");
					pauseExecution();
				}
				else
				{
					system("cls");
					addClient();
				}
			break;
			
			case 2:
				system("cls");
				searchClient();	
			break;
			
			case 3:
				system("cls");
				editClient();
			break;
			
			case 4:
				system("cls");
				deleteClient();	
		}

	} while(option != 0);
	system("cls");
	printf("Off System...\n");
	printf("Press <ENTER> to close program...");
	getchar();
	fflush(stdin);
	
	return 0;
}


