/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef TORRE_H_
#define TORRE_H_

#include"IPeca.h"
#include"Posicao.h"

class Torre : public IPeca {
public:
    Torre(int cor, Posicao *posicao);

    Torre(int cor, Posicao *posicao, Tabuleiro *tabuleiro);

    ~Torre() override = default;

    void gerarMovimentos(std::vector<Movimento *> &) override;

private:
    bool primeiroMovimento = true;
};

#endif
