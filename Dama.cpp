/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Dama.h"

#include"Tabuleiro.h"
#include"IPeca.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/
		
void Dama::gerarMovimentos(std::vector<Movimento *> &movimentos){

	this -> IPeca::gerarMovimentosCardeais(movimentos, false, false);

	this -> IPeca::gerarMovimentosColaterais(movimentos, false, false);
}

void Dama::gerarCasasAtacadas(std::vector<Movimento *> &movimentos)
{

	this -> IPeca::gerarMovimentosCardeais(movimentos, false, true);

	this -> IPeca::gerarMovimentosColaterais(movimentos, false, true);
}

Dama::Dama(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Dama::Dama(int cor, Posicao *posicao, Tabuleiro *tabuleiro): IPeca(cor, posicao, tabuleiro) {
}
