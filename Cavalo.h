/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef CAVALO_H_
#define CAVALO_H_

#include<string>

#include"IPeca.h"

class Cavalo : public IPeca {

public:
	Cavalo(int cor, Posicao *posicao);

	~Cavalo() override = default;

	void gerarMovimentos(std::vector<Movimento> &) override;
};

#endif
