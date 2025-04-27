/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Torre.h"

#include"Tabuleiro.h"
#include"IPeca.h"

#include<vector>

Torre::Torre(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Torre::Torre(int cor, Posicao *posicao, Tabuleiro *tabuleiro): IPeca(cor, posicao, tabuleiro) {
}

void Torre::gerarMovimentos(std::vector<Movimento *> &movimentos){

	this -> IPeca::gerarMovimentosCardeais(movimentos, false, false);
}

void Torre::gerarCasasAtacadas(std::vector<Movimento *> &movimentos)
{
	this -> IPeca::gerarMovimentosCardeais(movimentos, false, true);
}
