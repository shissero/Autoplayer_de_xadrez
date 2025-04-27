/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef PEAO_H_
#define PEAO_H_

#include"IPeca.h"
#include"Movimento.h"

class Peao : public IPeca
{
public:
        Peao(int cor, Posicao *posicao);

        Peao(int cor, Posicao *posicao, Tabuleiro *tabuleiro);

        ~Peao() override = default;

        void gerarMovimentos(std::vector<Movimento *> &) override;

        void gerarCasasAtacadas(std::vector<Movimento *> &) override;

        bool obterPrimeiroMovimento() const;

        void definirPrimeiroMovimento(bool valor);

private:
        bool primeiroMovimento = true;

        void gerarMovimentosCentralizada(std::vector<Movimento *> &, bool);
};

#endif
