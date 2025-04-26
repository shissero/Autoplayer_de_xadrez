/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

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

Posicao *Posicao::operator+(const Posicao &pos) const {

		auto copia = new Posicao(*this);

		*copia += pos;

		return copia;
}

void Posicao::operator+=(const Posicao &pos)
{

	coordinates[COLUNA] += pos.coordinates[COLUNA];
	coordinates[LINHA] += pos.coordinates[LINHA];
}

bool Posicao::validarPosicao(int col, int lin)
{

	return !(col < 0 || col > 7 || lin < 0 || lin > 7);
}

bool Posicao::validarPosicao() const
{

	return !(coordinates[COLUNA] < 0 || coordinates[COLUNA] > 7 || coordinates[LINHA] < 0 || coordinates[LINHA] > 7);
}

void Posicao::rotacionarEm90()
{
	int aux = coordinates[COLUNA];
	coordinates[COLUNA] = -coordinates[LINHA];
	coordinates[LINHA] = aux;
}
