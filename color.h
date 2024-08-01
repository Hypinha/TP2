#pragma once


// Definição de cores

#define limpar "\033[m"

enum cores { preto = 0, branco = 15, azul = 18, verde = 34, ciano = 51, vermelho = 124, roxo = 128, rosa = 200, laranja = 208, amarelo = 226, cinza = 247 };


//prototipos das funções

void Cor(cores, cores);									// Função simples para mudar a cor do texto

void Colorir(char[], cores, cores);						// Função para mudar a cor do texto de um vetor

void Limpar(void);										// Função para voltar o terminal para a cor original

