/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 23/04/2024

*/

#include "PosicaoInvalida.h"

#include"Posicao.h"


Posicao::Posicao(int coluna, int linha) {

	coordinates[COLUNA] = coluna;
	coordinates[LINHA] = linha;
}

int Posicao::coluna() const {

	return coordinates[COLUNA];
}

int Posicao::linha() const {

	return coordinates[LINHA];
}

void Posicao::coluna(int valor) {

	coordinates[COLUNA] = valor;
}

void Posicao::linha(int valor) {

	coordinates[LINHA] = valor;
}

/***********************************************************************************************************************
************************************************************************************************************************
***********************************************************************************************************************/

bool Posicao::operator==(const Posicao &posicao) const {

	return this->coluna() == posicao.coluna() &&
		(this->linha() == posicao.linha());
}

Posicao Posicao::operator+(const Posicao &pos) const {

	int aux_coluna = this->coluna() + pos.coluna();
	int aux_linha = this->linha() + pos.linha();

	if (aux_coluna < 0 || aux_coluna > 7 || aux_linha < 0 || aux_linha > 7) { // não é necessário testar se o valor é menor que zero. Se isso acontecer, a variável estoura e seu valor vai ficar acima de 8

		throw PosicaoInvalida(aux_coluna, aux_linha);
	}
	else return {aux_coluna, aux_linha};
}
