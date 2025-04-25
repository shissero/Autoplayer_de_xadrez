/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/
#ifndef BISPO_H_
#define BISPO_H_


#include"IPeca.h"
#include "Bispo.h"

class Bispo : public IPeca {
public:
	Bispo(int, Posicao*);

	Bispo(int cor, Posicao * posicao, Conjunto * conjunto);

	~Bispo() override = default;

	void gerarMovimentos(std::vector<Movimento> &) override;
};

#endif
