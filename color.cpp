#include <iostream>
#include "color.h"


using namespace std;



// Corpo das fun��es

void Cor(cores letra, cores fundo)											// Fun��o simples para mudar a cor do texto
{
	cout << "\033[38;5;" << letra << "m";									// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";									// Altera a cor da fundo no texto
}

void Colorir(char texto[], cores letra, cores fundo)						// Fun��o para mudar a cor do texto de um vetor
{
	
	cout << "\033[38;5;" << letra << "m";									// Altera a cor da letra no texto
	cout << "\033[48;5;" << fundo << "m";									// Altera a cor da fundo no texto
	for (int i = 0; i < strlen(texto); ++i)									// La�o de repeti��o para colorir os caracteres do texto
		cout << texto[i];
	
	cout << limpar;															// Reseta a cor do texto no terminal para a padr�o
};

void Limpar(void)															// Fun��o para voltar o terminal para a cor original
{
	cout << limpar;															// Reseta a cor do texto no terminal para a padr�o
}

