#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char user[20]; 
	char password[50];
	char name[50];
	int accountNumber;
	float balance; // saldo;
		
}Account;

int code = 0;
int accountVector = 0;
int accountNumber = 10;
Account account[3];

void pauseExecution()
{
	printf("Press <ENTER> to continue...");
	getchar();
	fflush(stdin);
	system("cls");
}

int initialMenu()
{
	int opInitialMenu;
	printf("1-CREATE BANK ACCOUNT\n");
	printf("2-ACESS ACCOUNT\n0-EXIT PROGRAM\n");
	printf("\nENTER OPTION --> ");
	scanf("%d", &opInitialMenu);
	return opInitialMenu;
}

void createAccount()
{
	if(code == 3)
	{
		printf("FULL SERVER!\n\nNOT MORE POSSIBLE CREATE NEW ACCOUNT AT THIS MOMENT.\n");
		pauseExecution();
	}
	else
	{
		int answerRegister;
		printf("\t### CREATE BANK ACCOUNT MENU ###\n\n");
		printf("REMAINING REGISTERS: %d\n\n", 3 - code);
		printf("USER: ");
		gets(account[code].user);
		printf("FULL NAME: ");
		gets(account[code].name);
		printf("INITIAL VALUE DEPOSITED: US$ ");
		scanf("%f", &account[code].balance);
		fflush(stdin);
		printf("\nWARNING: YOUR PASSWORD IS MOST IMPORTANT! MAKE SURE YOU KEEP IT.\n");
		printf("IF YOU UNDERSTAND, PRESS <ENTER> TO CONTINUE ");
		getchar();
		fflush(stdin);
		printf("\nACCOUNT PASSWORD: ");
		gets(account[code].password);
		fflush(stdin);
		pauseExecution();
		system("cls");
		printf("ACCOUNT CREATE WITH SUCCESS!\n\n");
		printf("YOUR ACCOUNT NUMBER IS: %d\n\n", accountNumber);
		account[code].accountNumber = accountNumber;
		accountNumber *= 3;
		code++;
		pauseExecution();
	}
}

int optionAccOperator;

void cashWithdrawal()
{
	float amountWithdrawal;
	printf("YOUR BALANCE: US$ %.2f\n\n", account[accountVector].balance);
	printf("AMOUNT WITHDRAWAL: ");
	scanf("%f", &amountWithdrawal);
	fflush(stdin);
	if(amountWithdrawal > 0 && amountWithdrawal <= account[accountVector].balance)
	{
		int optionWithdrawal;
		printf("CONFIRM WITHDRAWAL US$ %.2f ?(1 YES | 0 NO):\n--> ", amountWithdrawal);
		scanf("%d", &optionWithdrawal);
		fflush(stdin);
		if(optionWithdrawal == 0)
		{
			optionAccOperator = 0;
		}
		else
		{
			account[accountVector].balance -= amountWithdrawal;
			printf("WITHDRAWAL REALIZES WITH SUCESS!\n\n");
			printf("NEW BALANCE: %.2f\n", account[accountVector].balance);
			pauseExecution();
			optionAccOperator = 0;
		}
	}
	else
	{
		printf("INVALID OPERATION! INSUFICIENT BALANCE OR INVALID AMOUNT.");
		pauseExecution();
	}
}

void cashDeposit()
{
	float amountDeposit;
	printf("YOUR BALANCE: %.2f\n\n", account[accountVector].balance);
	printf("AMOUNT DEPOSIT: US$ ");
	scanf("%f", &amountDeposit);
	fflush(stdin);
	if(amountDeposit > 0)
	{
		int optionDeposit;
		printf("CONFIRM DEPOSIT US$ %.2f ?(1 YES | 0 NO):\n--> ", amountDeposit);
		scanf("%d", &optionDeposit);
		fflush(stdin);
		if(optionDeposit == 0)
		{
			optionAccOperator = 0;
		}
		else
		{
			account[accountVector].balance += amountDeposit;
			printf("DEPOSIT REALIZES WITH SUCESS!\n\n");
			printf("NEW BALANCE: %.2f\n", account[accountVector].balance);
			pauseExecution();
			optionAccOperator = 0;			
		}		
	}
	else
	{
		printf("INVALID OPERATION! INVALID AMOUNT.");
		pauseExecution();
	}
}

void cashTransfer()
{
	int verifyAccountNumber = 0;
	int accountNumberTransfer;
	int transferVector;
	int i;
	printf("\t### BANKER TRANSFER ###\n\n");
	printf("YOUR BALANCE: US$ %.2f\n", account[accountVector].balance);
	printf("ACCOUNT NUMBER TRANSFER: ");
	scanf("%d", &accountNumberTransfer);
	fflush(stdin);
	for(i = 0; i < code; i++)
	{
		if(accountNumberTransfer == account[i].accountNumber && accountNumberTransfer != account[accountVector].accountNumber)
		{
			verifyAccountNumber = 1;
			transferVector = i;
			break;
		}
	}
		if(verifyAccountNumber == 1)
		{
			int continueTransfer;
			printf("ACCOUNT NAME: %s\n\n", account[transferVector].name);
			printf("WISH CONTINUE TRANSFER?(1-YES | 0-NO): ");
			scanf("%d", &continueTransfer);
			fflush(stdin);
			system("cls");
			if(continueTransfer == 0)
			{
				printf("TRANSFER ABORT!\n");
				printf("PRESS <ENTER> TO RETURN MENU");
				getchar();
				fflush(stdin);
				system("cls");
			}
			else if(continueTransfer == 1)
			{
				int abortTransfer;
				do
				{
					float valueTransfer;
					printf("VALUE TRANSFER: US$ ");
					scanf("%f", &valueTransfer);
					fflush(stdin);
					if(valueTransfer > 0 && valueTransfer <= account[accountVector].balance)
					{
						account[accountVector].balance -= valueTransfer;
						account[transferVector].balance += valueTransfer;
						printf("TRANSFER REALIZED WITH SUCCESS!\n");
						printf("NEW BALANCE: US$ %.2f\n\n", account[accountVector].balance);
						printf("PRESS <ENTER> TO EXIT: ");
						getchar();
						fflush(stdin); //systemcls na proxima linha;
						abortTransfer = 0;
					}
					else
					{
						printf("INSUFICIENT BALANCE!\n\n");
						printf("DOES WISH RETRY?(1-YES | 0-NO): ");
						scanf("%d", &abortTransfer);
						fflush(stdin);
						system("cls");
					}
				} while(abortTransfer != 0);
			}
		}
		else if(verifyAccountNumber == 0)
		{
			printf("INVALID OPERATION OR ACCOUNT HAS NOT FOUND IN THE SYSTEM!\n");
			printf("PRESS <ENTER> TO RETURN MENU: ");
			getchar();
			fflush(stdin);
			system("cls");
		}
}

void accountMenu()
{
	do
	{
		int option;
		printf("WELCOME, %s\n\n", account[accountVector].name);
		printf("ACCOUNT NUMBER: %d\n\n", account[accountVector].accountNumber);
		printf("WHAT OPERATION DO YOU WANT REALIZES?\n\n");
		printf("1-CHECK BALANCE\n2-CASH DEPOSIT\n3-CASH WITHDRAWAL\n");
		printf("4-TRANSFER BETWEEN ACCOUNTS\n0-EXIT MENU\nOPTION --> ");
		scanf("%d", &option);
		system("cls");
		switch(option)
		{
			case 0:
				optionAccOperator = 0;
				printf("CLOSED OPERATIONS!\nPRESS <ENTER> TO RETURN SERVER BANK...");
				getchar();
				fflush(stdin);
				system("cls");
				break;	
				
			case 1:
				printf("BANK BALANCE: US$ %.2f\n\n", account[accountVector].balance);
				printf("NEW ACCOUNT OPERATOR? (1-YES | 0-NO)\nOPTION --> ");
				scanf("%d", &optionAccOperator);
				system("cls");
				break;
			
			case 2:
				cashDeposit();
				system("cls");
				break;
			
			case 3:
				cashWithdrawal();
				system("cls");
				break;
			
			case 4:
				cashTransfer();
				system("cls");
			break;
								
		}
	} while(optionAccOperator != 0);
}

void acessAccount()
{
	if(code == 0)
	{
		printf("EMPTY SERVER! NONE ACCOUNT HAS REGISTER.\n\n");
		pauseExecution();
	}
	else
	{
		char userWrited[20];
		char passwordWrited[50];
		int i;
		int userVerification = 0;
		int passwordVerification = 0;
		printf("USER: ");
		gets(userWrited);
		fflush(stdin);
		for(i = 0; i < code; i++)
		{
			if(strcmp(userWrited, account[i].user)==0)
			{
				accountVector = i;
				userVerification = 1;
			}
		}
		if(userVerification == 1)
		{
			printf("ACCOUNT PASSWORD: ");
			gets(passwordWrited);
			fflush(stdin);
		
			if(strcmp(passwordWrited, account[accountVector].password)==0)
			{
				passwordVerification = 1;
			}
			if(passwordVerification == 1)
			{
				system("cls");
				accountMenu();
				printf("CLOSED OPERATIONS!\nPRESS <ENTER> TO RETURN SERVER BANK...");
				getchar();
				fflush(stdin);
				system("cls");
			}
			else if(passwordVerification == 0)
			{
				system("cls");
				printf("PASSWORD DOES NOT MATCH USER!\n\n");
				pauseExecution();
			}
		}
		else if(userVerification == 0)
		{
			printf("USER NOT FOUND!\n");
			pauseExecution();
		}
	}
}

void switchOperator(int opSwitch)
{
	switch(opSwitch)
	{
		case 0:
			printf("Off System...\n");
			printf("PRESS <ENTER> TO CLOSE BANK SERVER...");
			getchar();
			fflush(stdin);
			system("cls");
			break;		
		case 1:
			createAccount();
			break;
		case 2:
			acessAccount();
			break;
		default:
			printf("INVALID OPTION!\n");
			printf("PRESS <ENTER> TO RETURN INITIAL MENU");
			getchar();
			fflush(stdin);
			system("cls");
			break;		
	}
}

int main()
{
	int opMenuExecute;
	do
	{
		printf("\t### BANK SERVER ###\n\n");
		opMenuExecute = initialMenu();
		fflush(stdin);
		system("cls");
		switchOperator(opMenuExecute);
	} while(opMenuExecute != 0);
	
	return 0;
}
