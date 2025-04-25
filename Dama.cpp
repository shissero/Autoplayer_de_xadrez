/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Dama.h"

#include"Conjunto.h"
#include"IPeca.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/
		
void Dama::gerarMovimentos(std::vector<Movimento *> &){
/*
	this -> IPeca::gerarMovimentosCardeais(movimentos, 0);

	this -> IPeca::gerarMovimentosColaterais(movimentos, 0);*/
}

Dama::Dama(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Dama::Dama(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto) {
}
