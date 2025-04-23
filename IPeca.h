/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef PECA_H_
#define PECA_H_

#include"Movimento.h"
#include"Posicao.h"

#include<vector>

class Conjunto;

class IPeca {
public:
    IPeca(int cor, Posicao *);

    IPeca(int cor, Posicao*, Conjunto*);

    virtual ~IPeca() = default;

    static constexpr int BRANCO = 1;
    static constexpr int PRETO = -1;

    virtual void gerarMovimentos(std::vector<Movimento> &) = 0;

    int obterCor() const;

    const Posicao *obterPosicao() const;

protected:
    const int cor;
    Posicao *posicao;
    Conjunto *conjunto;

    static void gerarMovimentosCardeais(std::vector<Movimento> &, bool);

    static void gerarMovimentosColaterais(std::vector<Movimento> &, bool);
};

#endif
