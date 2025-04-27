/*

	Autor: Cícero Augusto Alcântara de Sousa

*/
#ifndef DAMA_H_
#define DAMA_H_


#include"IPeca.h"

class Dama : public IPeca {
public:
    Dama(int cor, Posicao *posicao);

    Dama(int cor, Posicao *posicao, Tabuleiro *tabuleiro);

    ~Dama() override = default;

    void gerarMovimentos(std::vector<Movimento *> &) override;

    void gerarCasasAtacadas(std::vector<Movimento *> &) override;
};

#endif
