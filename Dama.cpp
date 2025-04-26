/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Dama.h"

#include"Conjunto.h"
#include"IPeca.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/
		
void Dama::gerarMovimentos(std::vector<Movimento *> &movimentos){

	this -> IPeca::gerarMovimentosCardeais(movimentos, false);

	this -> IPeca::gerarMovimentosColaterais(movimentos, false);
}

Dama::Dama(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Dama::Dama(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto) {
}
