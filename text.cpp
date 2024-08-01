#include <iostream>
#include "text.h"
#include "color.h"
using namespace std;

// Corpo das fun��es

void Alinhado(char texto[], cores letra, cores fundo, int espa�o)						// Fun��o para alinhar e colorir o texto
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espa�o);																	// Alinha o texto
	for (int i = 0; i != strlen(texto); ++i)											// La�o para percorrer o vetor e apresentar ele
	{
		cout << texto[i];
	}
	cout.width(espa�o); cout << " ";
	cout << limpar;
}

void AlinhadoInteiro(int texto[], cores letra, cores fundo, int espa�o)					// Fun��o para alinhar e colorir inteiros
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espa�o);																	// Alinha o texto
	for (int i = 0; texto[i] != '\0'; ++i)												// La�o para percorrer o vetor e apresentar ele
		cout << texto[i];
	cout << limpar;
}

void AlinhadoFlutuante(double texto[], cores letra, cores fundo, int espa�o)			// Fun��o para alinhar e colorir ponto-flutuantes
{
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	cout.width(espa�o);																	// Alinha o texto
	for (int i = 0; texto[i] != '\0'; ++i)												// La�o para percorrer o vetor e apresentar ele
		cout << texto[i];
	cout << limpar;
}

void Linha(char caractere, int tamanho, cores letra, cores fundo)						// Fun��o para criar a linha
{
	
	cout << "\033[38;5;" << letra << "m";												// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";												// Altera a cor do fundo do texto
	for (int i = 0; i != tamanho; i++)													// La�o para repetir o caractere e criar a linha
		cout << caractere;
	cout << limpar;
}

void Caps(char texto[])																	// Fun��o para deixar o texto em mai�sculo
{
	int i = 0;
	while (texto[i] != '\0')															// La�o de repeti��o para passar letra a letra deixando em mai�sculo
	{
		if (texto[i] >= 'a' && texto[i] <= 'z')											// Valida se � uma leetra min�scula, para que possa alterar
		{
			texto[i] = (texto[i] - 32);
			cout << texto[i];
			i++;
		}
		else {																			// Caso n�o seja uma letra min�scula, s� mostra o caractere
			cout << texto[i];
			i++;
		}
	}
}