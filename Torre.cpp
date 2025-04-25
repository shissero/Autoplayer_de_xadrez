/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#include<vector>

#include"Conjunto.h"
#include"IPeca.h"
#include"Torre.h"

Torre::Torre(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Torre::Torre(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto) {
}

void Torre::gerarMovimentos(std::vector<Movimento>&){

	//this -> IPeca::gerarMovimentosCardeais(movimentos, 0);
}
