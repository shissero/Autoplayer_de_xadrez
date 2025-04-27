/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Bispo.h"

#include"Tabuleiro.h"
#include"IPeca.h"

Bispo::Bispo(int cor, Posicao *posicao)
		: IPeca(cor, posicao) {
}

Bispo::Bispo(int cor, Posicao *posicao, Tabuleiro *tabuleiro) : IPeca(cor, posicao, tabuleiro) {
}

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/

void Bispo::gerarMovimentos(std::vector<Movimento *> &movimentos) {

	this -> gerarMovimentosColaterais(movimentos, false);
}
