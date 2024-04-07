#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void forca(int fase) {
	int i;
	
	if(fase == 0) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 1) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 2) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		printf("\n|          |");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 3) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		printf("\n|         -|");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 4) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		printf("\n|         -|-");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 5) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		printf("\n|         -|-");
		printf("\n|         /");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	
	} else if(fase == 6) {
		for(i = 0; i < 12; i++) {
			printf("-");
		}
		printf("\n|          |");
		printf("\n|          0");
		printf("\n|         -|-");
		printf("\n|         / \\");
		for(i = 0; i < 10; i++) {
			printf("\n|");
		}
		for(i = 0; i < 12; i++) {
			printf("_");
		}
	}	
}

int main() {
	char palavraSecreta[100], palavraExibida[100], letraDigitada;
	int quantidadeCaracter, i, x, quantidadeErros = 0;
	
	printf("Digite a Palavra Secreta: ");
	scanf(" %s", palavraSecreta);	
	
	quantidadeCaracter = strlen(palavraSecreta);
	strcpy(palavraExibida, palavraSecreta);
	system("cls");
	
	printf("A palavra Secreta possui %d letras: ", quantidadeCaracter);
	for(i = 0; i < quantidadeCaracter; i++) {
		palavraExibida[i] = '_';
	}
	printf("\nAdvinhe a palavra: ");
	do {
		int palavraErrada = 1;
		
		printf("\n\nDigite uma letra:\n-->");
		scanf(" %c", &letraDigitada);
		
		for(i = 0; i < quantidadeCaracter; i++) {
			if(letraDigitada == palavraSecreta[i]) {
				palavraExibida[i] = letraDigitada;
				palavraErrada = 0;
			} 	
		}
		
		if(palavraErrada == 1) {
			quantidadeErros++;
		} 
		system("cls");
		forca(quantidadeErros);
		printf("\n\nPalavra Exibida = %s", palavraExibida);	
		
		if(strcmp(palavraExibida, palavraSecreta)==0) {
			system("cls");
			forca(quantidadeErros);
			printf("\n\nParabens!! Vc Ganhou!!!\n");
			break;
		} else if(quantidadeErros == 6) {
			system("cls");
			forca(quantidadeErros);
			printf("\n\nGAME OVER!!!\nGAME OVER!!!\n");
		}	

	} while(quantidadeErros < 6);
	
	system("pause");
	return 0;		
}
