/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/
#ifndef DAMA_H_
#define DAMA_H_


#include"IPeca.h"

class Dama : public IPeca {
public:
    Dama(int cor, Posicao *posicao);

    Dama(int cor, Posicao *posicao, Conjunto *conjunto);

    ~Dama() override = default;

    void gerarMovimentos(std::vector<Movimento> &) override;
};

#endif
