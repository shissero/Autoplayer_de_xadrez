/*

	Autor: Cícero Augusto Alcântara de Sousa

*/
#ifndef BISPO_H_
#define BISPO_H_


#include"IPeca.h"

class Bispo : public IPeca {
public:
	Bispo(int, Posicao*);

	Bispo(int cor, Posicao * posicao, Conjunto * conjunto);

	~Bispo() override = default;

	void gerarMovimentos(std::vector<Movimento *> &) override;
};

#endif
