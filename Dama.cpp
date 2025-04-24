/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 11/01/2021

*/

#include"Conjunto.h"
#include"Dama.h"
#include"IPeca.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/
		
void Dama::gerarMovimentos(std::vector<Movimento>&){
/*
	this -> IPeca::gerarMovimentosCardeais(movimentos, 0);

	this -> IPeca::gerarMovimentosColaterais(movimentos, 0);*/
}

Dama::Dama(int cor, Posicao *posicao): IPeca(cor, posicao) {
}
