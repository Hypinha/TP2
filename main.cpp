#include <iostream>
#include "date.h"
#include "stock.h"
#include "color.h"
#include "text.h"
using namespace std;

istream& operator>>(istream& is, Data& data)				// Ensinando o operador >> a ler o tipo ata
{
	char barra;
	is >> data.dia >> barra >> data.mes >> barra >> data.ano;
	return is;
}

ostream& operator << (ostream& os, Data& data)				// Ensinando o operador << a mostrar o tipo ata
{
	const char barras = '/';
	corrige(data.dia);
	os << barras;
	corrige(data.mes);
	os << barras << data.ano;
	return os;
}


int main()
{
	system("chcp 1252 > nul");
	int tamanho = 0;
	char apresenta[] = "Carteira de Ações:";
	char carteira[] = "Transações Realizadas:";
	double Aporte = 0;
	double RendimentoEstimado = 0;
	double Investido[21];
	double Rendimento[21];
	double Acumulado[21];
	Cor(preto, vermelho);																// Muda a cor do texto
	cout << "Bem-vindo ao sistema de conferência de ações!\n" << endl;		
	Cor(vermelho, preto);																// Muda a cor do texto
	cout << "Informe a quantidade de empresas na sua carteira:\n";
	Limpar();																			// Retorna a cor do texto para a original
	cin >> tamanho;

	system("cls");																		// Limpa tela


	Empresas* empresas = new Empresas[tamanho];

	Alinhado(apresenta, preto, amarelo, 4);												// Alinha e colore o vetor "apresenta"
	cout << "\n";
	Cor(vermelho, preto);																// Muda a cor do texto
	cout<< "Quantidade de empresas[" << tamanho << "]" << endl;
	Limpar();																			// Retorna a cor do texto para a original
	Linha('-', 25, amarelo, preto);														// Cria  uma linha colorida

	for (int i = 0; i < tamanho; i++)													// Laço de repetição
	{																					// para ler os valores
		cout << '\n';																	// dr empresa, ticker
		cin.ignore();																	// e transações.
		Cor(amarelo, preto);
		cout << "Empresa: ";
		Limpar();
		cin.getline(empresas[i].nome, 50);
		Cor(amarelo, preto);
		cout << "Ticker: ";
		Limpar();
		cin.getline(empresas[i].ticker, 10);
		Cor(amarelo, preto);
		cout << "Transações: ";
		Limpar();
		cin >> empresas[i].transaçoes;
		Linha('-', 25, amarelo, preto);
	}
	

	system("cls");																		// Limpa tela

	Alinhado(carteira, preto, amarelo, 4);												// Alinha e colore o vetor "apresenta"
	cout << '\n';
	int transacoes = 0;
	for (int i = 0; i < tamanho; i++)													// Laço de repetição
	{																					// para contar a
		int soma = empresas[i].transaçoes;												// quantidade total de
		transacoes = transacoes + soma;													// transações.
		
	}
	Transaçao* transacao = new Transaçao[transacoes];
	for (int i = 0; i < tamanho; i++)													// Laço de repetição
	{																					// para apresentar o 
		empresas[i].acoes = new Transaçao[transacoes];									// nome e ticker da empresa
		int transacoes = empresas[i].transaçoes;										// e iniciar a leitura
			Transaçao * transacao = new Transaçao[transacoes];							// da data, quantidade
		Cor(amarelo, preto);															// e preço.
		cout << '\n';
		cout << empresas[i].nome << " - " << empresas[i].ticker << endl;
		Limpar();

		for (int j = 0; j < empresas[i].transaçoes; j++)								// Laço de repetição
		{																				// para fazer a leitura
			cout << '\n';																// dos valores para
			Cor(amarelo, preto);														// a data, a quantidade
			cout << "Data: ";															// e o preço.
			Limpar();
			cin >> transacao[j].data;
			empresas[i].acoes[j].data = transacao[j].data;
			Cor(amarelo, preto);
			cout << "Quantidade: ";
			Limpar();
			cin >> transacao[j].quantidade;
			empresas[i].acoes[j].quantidade = transacao[j].quantidade;
			Cor(amarelo, preto);
			cout << "Preço: ";
			Limpar();
			cin >> transacao[j].preço;
			empresas[i].acoes[j].preço = transacao[j].preço;
			
		}
	}
	system("cls");
	
	Investido[0] = Carteira(empresas, tamanho);

	system("pause");
	system("cls");

	cout << "Aporte anual R$ ";															// Verifica qual o aporte
	cin >> Aporte;
	cout << "\n% de rendimento anual estimado em ";										// Verifica o rendimento esperado
	cin >> RendimentoEstimado;
	cout << '\n';
	
	
	char rentabilidade[] = "Rentabilidade da carteira ";
	Alinhado(rentabilidade, preto, amarelo, 38);
	cout << '\n';
	Linha('-', 102, amarelo, preto);
	cout << '\n';
	Cor(preto, amarelo);
	cout << "Ano ";
	cout << "   Investido  ";
	cout << "   Rendimento  ";
	cout << "      Acumulado  ";
	char grafico[] = "Gráfico";
	Alinhado(grafico, preto, amarelo, 23);
	cout << '\n';
	double graf[21];

	Rendimento[0] = 0;
	Acumulado[0] = Investido[0];
	for (int k = 0; k <= 20; k++)														// Laço de repetição para
	{																					// preencher os vetores
		if (k != 0)																		// investido, rendimento
		{																				// e acumulado.
				Investido[k] = ((Investido[k - 1]) + Aporte);
				Rendimento[k] = ((Aporte + Acumulado[k - 1]) * (RendimentoEstimado / 100));
				Acumulado[k] = ((Acumulado[k - 1]) + Aporte + Rendimento[k]);
				
			
			
		}


	}
	for (int t = 0; t <= 20; t++)														// Laço de repetição para
	{																					// preencher o vetor ddo gráfico
		system("chcp 850 > nul");														// e apresentar os dados na tela.
		graf[t] = (((Acumulado[t]) / (Acumulado[20]))*21);
		Cor(preto, amarelo);
		cout << t;
		Limpar();

		if (t != 0)
		{
			if (t <= 9)
			{
				cout << right; cout.width(6); cout << " " << Investido[t];
				cout << right; cout.width(9); cout << " " << Rendimento[t];
				cout << left; cout.width(9); cout << " " << Acumulado[t];
				cout << right; cout.width(5); cout << " ";
				for (int z = 0; z <= graf[t]; z++)
				{	
					//cout << left; 
					cout << " ";
					cout << '\xDF';
				}
				cout << '\n';
			}
			else
			{
				cout << right; cout.width(5); cout << " " << Investido[t];
				cout << right; cout.width(8); cout << " " << Rendimento[t];
				cout << right; cout.width(8); cout << " " << Acumulado[t];
				cout << right; cout.width(5); cout << " ";
				
				cout << left;
				 for (int y = 0; y <= graf[t]; y++)
				{
					
					cout << " ";
					cout << '\xDF';
				}
				cout << '\n';
			}
		}
		else
		{
			cout << right; cout.width(6); cout << " " << Investido[t];
			cout << right; cout.width(9); cout << " " << Rendimento[t];
			cout << right; cout.width(12); cout << " " << Acumulado[t];
			cout << right; cout.width(5); cout << " ";
			cout << right;
			cout << " ";
			cout << '\xDF';
			cout << '\n';
		}
		
	}
	Linha('-', 102, amarelo, preto);
	


	for (int i = 0; i < tamanho; i++)													// Deleção dos vetores dinamicos
	delete[] empresas[i].acoes;
	delete[] transacao;
	delete [] empresas;
	return 0;
}