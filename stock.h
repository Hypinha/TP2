#pragma once
#include "date.h"



struct Transaçao							//Criação do tipo transação
{	
	Data data;
	int quantidade;
	double preço;
};

struct Empresas								//Criação do tipo empresa
{
	char nome[50];
	char ticker[10];
	int transaçoes;
	Transaçao * acoes;
};

//prototipos das funções

double Carteira(Empresas[], int);