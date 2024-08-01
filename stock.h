#pragma once
#include "date.h"



struct Transa�ao							//Cria��o do tipo transa��o
{	
	Data data;
	int quantidade;
	double pre�o;
};

struct Empresas								//Cria��o do tipo empresa
{
	char nome[50];
	char ticker[10];
	int transa�oes;
	Transa�ao * acoes;
};

//prototipos das fun��es

double Carteira(Empresas[], int);