#include <iostream>
#include "date.h"
using namespace std;

// Corpo das funções
void corrige(int a)											// Função para a apresentação do dia e mês com 2 digitos 
{
	if (a < 10)
		cout << "0";
	cout << a;
}



