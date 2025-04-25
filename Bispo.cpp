/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 11/01/2021

*/

#include"Bispo.h"
#include"Conjunto.h"
#include"IPeca.h"

Bispo::Bispo(int cor, Posicao *posicao)
		: IPeca(cor, posicao) {
}

Bispo::Bispo(int cor, Posicao *posicao, Conjunto *conjunto) : IPeca(cor, posicao, conjunto) {
}

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/

void Bispo::gerarMovimentos(std::vector<Movimento> &movimentos) {
}
