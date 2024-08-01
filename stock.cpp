#include <iostream>
#include "date.h"
#include "stock.h"
#include "color.h"
#include "text.h"
using namespace std;

// Corpo das funções

double Carteira(Empresas empresas[], int tamanho)					// Função para gerar o Resumo da carteira
{	
	//criação de variáveis
	char resumo[] = "Resumo da Carteira";
	char emp[] = "Empresa";
	char ticker[] = "Ticker";
	char qtd[] = "Qtd.";
	char preço[] = "Preço Médio";
	char investido[] = "Investido";
	double TotalInvestido = 0;

	Alinhado(resumo,preto, amarelo, 28);						// Gera o nome "Resumo da Carteira" com alinhamento
	cout << '\n';
	Limpar();
	Linha('-', 73, amarelo, preto);
	cout << '\n';
	Alinhado(emp, preto, amarelo, 1);							// Gera o nome "Empresa" com alinhamento e cor
	Limpar();
	Alinhado(ticker, preto, amarelo, 6);						// Gera o nome "Ticker" com alinhamento e cor					
	Limpar();
	Alinhado(qtd, preto, amarelo, 6);							// Gera o nome "Qtd." com alinhamento e cor
	Limpar();
	Alinhado(preço, preto, amarelo, 6);							// Gera o nome "Preço" com alinhamento e cor
	Limpar();
	Alinhado(investido, preto, amarelo, 1);						// Gera o nome "Investido" com alinhamento e cor
	cout << '\n';
	Limpar();
	
	
	for (int i = 0; i < tamanho; i++) {
		int TamanhoNome = strlen(empresas[i].nome);
		int TamamnhoTicker = strlen(empresas[i].ticker);
		cout.width(1); cout << empresas[i].nome;
		cout.width(13 - TamanhoNome + TamamnhoTicker); cout << empresas[i].ticker;

		double investimento = 0;
		double total = 0;
		double qt = 0;
		double pre = 0;
		double quant = 0;
		for (int j = 0; j < empresas[i].transaçoes; j++) 
		{	
			qt = empresas[i].acoes[j].quantidade;
			pre = empresas[i].acoes[j].preço;
			quant = quant + qt;
			total = qt * pre;
			investimento = investimento + (qt * pre);
			TotalInvestido = TotalInvestido + total;
		}

		cout << fixed;
		cout.precision(0);
		cout.width(15); cout << quant;
		cout << fixed;
		cout.precision(2);														//Trava a exibição dos resultados com 2 casa após a virgulacout.width(20); cout << pro;
		cout.width(20); cout << investimento/quant;
		
		cout.width(18); cout << investimento << endl;
	}
	
	Linha('-', 73, amarelo, preto);
	cout << '\n';
	Cor(preto, amarelo);
	cout << left; cout << "Total Investido: ";
	cout << right; cout.width(55); cout << TotalInvestido;
	Limpar();
	cout << '\n';

	return TotalInvestido;
}