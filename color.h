#pragma once


// Defini��o de cores

#define limpar "\033[m"

enum cores { preto = 0, branco = 15, azul = 18, verde = 34, ciano = 51, vermelho = 124, roxo = 128, rosa = 200, laranja = 208, amarelo = 226, cinza = 247 };


//prototipos das fun��es

void Cor(cores, cores);									// Fun��o simples para mudar a cor do texto

void Colorir(char[], cores, cores);						// Fun��o para mudar a cor do texto de um vetor

void Limpar(void);										// Fun��o para voltar o terminal para a cor original

