#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void Compactar();
void Descompactar();

int main(int argc, char *argv[])
{
	int op;
	printf("--- Algoritmo de Huffman ---\n\n");
	printf("Insira a opcao:\n");
	printf("1- Compactar\n");
	printf("2- Descompactar\n");
	printf("0- Sair\n\n");
	scanf("%d", &op);
	
	switch(op)
	{
		case 0:
			exit(0);
			break;
		case 1:
			Compactar();
			break;
		case 2:
			Descompactar();
			break;
	}
}

void Compactar()
{
	char texto[50];
	char palavra[5];
	char compactado[50];
	int tamanho;
	int i;
	int posicao;
	
	printf("Digite o texto a ser compactado: ");
	scanf("%s", texto);
	tamanho = strlen(texto);
	posicao = 0;
	
	for(i=0; i<tamanho-4; i+=4)
	{
		palavra[0] = texto[i];
      	palavra[1] = texto[i+1];
      	palavra[2] = texto[i+2];
      	palavra[3] = texto[i+3];
      	palavra[4] = 0;
      	
      	if(strcmp(palavra, "0000")==0)
		{
			compactado[posicao] = '#';
			posicao++;
		}
		else if (strcmp(palavra, "1111")==0)
		{
			compactado[posicao] = '$';
			posicao++;
		}
		else if (strcmp(palavra, "0101")==0)
		{
			compactado[posicao] = '%';
			posicao++;
		}
		else if (strcmp(palavra, "1010")==0)
		{
			compactado[posicao] = '@';
			posicao++;
		}
		else if (strcmp(palavra, "0011")==0)
		{
			compactado[posicao] = '&';
			posicao++;
		}
		else if (strcmp(palavra, "1100")==0)
		{
			compactado[posicao] = '!';
			posicao++;
		}
		else
		{
			compactado[posicao]= palavra[0];
        	compactado[posicao+1]= palavra[0+1];
        	compactado[posicao+2]= palavra[0+2];
        	compactado[posicao+3]= palavra[0+3];
        	posicao += 4;
		}
	}
	printf("\nCompactado: %s", compactado);
}

void Descompactar()
{
	char texto[50];
	char descompactado[50];
	char palavra[5];
	int tamanho;
	int i;
	int posicao;
	
	printf("Digite o texto a ser descompactado: ");
	scanf("%s", &texto);
	tamanho = strlen(texto);
	posicao = 0;
	
	for(i=0; i<tamanho; i++)
	{
		palavra[0] = texto[i];
      	palavra[1] = texto[i+1];
      	palavra[2] = texto[i+2];
      	palavra[3] = texto[i+3];
      	palavra[4] = 0;
      	
      	if(strcmp(texto, "#")==0)
      	{
      		descompactado[posicao] = '0';
      		descompactado[posicao + 1] = '0';
      		descompactado[posicao + 2] = '0';
      		descompactado[posicao + 3] = '0';
      		posicao+=4;
		}
		else if(strcmp(texto, "$")==0)
		{
      		descompactado[posicao] = '1';
      		descompactado[posicao + 1] = '1';
      		descompactado[posicao + 2] = '1';
      		descompactado[posicao + 3] = '1';
      		posicao+=4;
		}
		else if(strcmp(texto, "%")==0)
		{
      		descompactado[posicao] = '0';
      		descompactado[posicao + 1] = '1';
      		descompactado[posicao + 2] = '0';
      		descompactado[posicao + 3] = '1';
      		posicao+=4;
		}
		else if(strcmp(texto, "@")==0)
		{
      		descompactado[posicao] = '1';
      		descompactado[posicao + 1] = '0';
      		descompactado[posicao + 2] = '1';
      		descompactado[posicao + 3] = '0';
      		posicao+=4;
		}
		else if(strcmp(texto, "&")==0)
		{
      		descompactado[posicao] = '0';
      		descompactado[posicao + 1] = '0';
      		descompactado[posicao + 2] = '1';
      		descompactado[posicao + 3] = '1';
      		posicao+=4;
		}
		else if(strcmp(texto, "!")==0)
		{
      		descompactado[posicao] = '1';
      		descompactado[posicao + 1] = '1';
      		descompactado[posicao + 2] = '0';
      		descompactado[posicao + 3] = '0';
      		posicao+=4;
		}
		else
		{
			descompactado[posicao]= palavra[0];
        	descompactado[posicao+1]= palavra[0+1];
        	descompactado[posicao+2]= palavra[0+2];
        	descompactado[posicao+3]= palavra[0+3];
        	posicao += 4;
		}
    }
	printf("\nDesompactado: %s", descompactado);
}

