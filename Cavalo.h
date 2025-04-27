/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef CAVALO_H_
#define CAVALO_H_

#include"IPeca.h"

class Cavalo : public IPeca {

public:
	Cavalo(int cor, Posicao *posicao);

	Cavalo(int cor, Posicao *posicao, Tabuleiro *tabuleiro);

	~Cavalo() override = default;

	void gerarMovimentos(std::vector<Movimento *> &) override;
};

#endif
