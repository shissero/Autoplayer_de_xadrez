/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef PEAO_H_
#define PEAO_H_

#include<array>
#include<string>

#include"Movimento.h"
#include"IPeca.h"

using namespace std;

class Peao : public IPeca {
public:
    Peao(int cor, Posicao *posicao);

    Peao(int cor, Posicao *posicao, Conjunto *conjunto);

    ~Peao() override = default;

    void gerarMovimentos(std::vector<Movimento> &) override;

    bool obterPrimeiroMovimento() const;

    void definirPrimeiroMovimento(bool valor);

private:
    bool primeiroMovimento = true;
};

#endif
