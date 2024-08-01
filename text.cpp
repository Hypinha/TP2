#include <iostream>
#include "text.h"
#include "color.h"
using namespace std;

// Corpo das funções

void Alinhado(char texto[], cores letra, cores fundo, int espaço)						// Função para alinhar e colorir o texto
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espaço);																	// Alinha o texto
	for (int i = 0; i != strlen(texto); ++i)											// Laço para percorrer o vetor e apresentar ele
	{
		cout << texto[i];
	}
	cout.width(espaço); cout << " ";
	cout << limpar;
}

void AlinhadoInteiro(int texto[], cores letra, cores fundo, int espaço)					// Função para alinhar e colorir inteiros
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espaço);																	// Alinha o texto
	for (int i = 0; texto[i] != '\0'; ++i)												// Laço para percorrer o vetor e apresentar ele
		cout << texto[i];
	cout << limpar;
}

void AlinhadoFlutuante(double texto[], cores letra, cores fundo, int espaço)			// Função para alinhar e colorir ponto-flutuantes
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espaço);																	// Alinha o texto
	for (int i = 0; texto[i] != '\0'; ++i)												// Laço para percorrer o vetor e apresentar ele
		cout << texto[i];
	cout << limpar;
}

void Linha(char caractere, int tamanho, cores letra, cores fundo)						// Função para criar a linha
{
	
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	for (int i = 0; i != tamanho; i++)													// Laço para repetir o caractere e criar a linha
		cout << caractere;
	cout << limpar;
}

void Caps(char texto[])																	// Função para deixar o texto em maiúsculo
{
	int i = 0;
	while (texto[i] != '\0')															// Laço de repetição para passar letra a letra deixando em maiúsculo
	{
		if (texto[i] >= 'a' && texto[i] <= 'z')											// Valida se é uma leetra minúscula, para que possa alterar
		{
			texto[i] = (texto[i] - 32);
			cout << texto[i];
			i++;
		}
		else {																			// Caso não seja uma letra minúscula, só mostra o caractere
			cout << texto[i];
			i++;
		}
	}
}