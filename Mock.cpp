//
// Created by cicero on 25/04/25.
//

#include "Mock.h"

#include "Conjunto.h"
#include "Time.h"

Bispo Mock::iBB1 = Bispo(IPeca::BRANCO, new Posicao(2, 0));
Bispo Mock::BB2 = Bispo(IPeca::BRANCO, new Posicao(3, 3));
Torre Mock::TP1 = Torre(IPeca::PRETO, new Posicao(4, 4));
Dama Mock::DP1 = Dama(IPeca::PRETO, new Posicao(5, 5));
Time *Mock::BRANCAS = nullptr;
Conjunto *Mock::CONJ = nullptr;

Mock::~Mock()
{
}

Conjunto *Mock::obterConjunto()
{
        if(CONJ != nullptr) return CONJ;
        else
        {
                Time *ali = obterBrancas();

                auto *novo = new Conjunto();

                novo->definirAliadas(ali);

                return novo;
        }
}

Time *Mock::obterBrancas()
{
        if(BRANCAS != nullptr) return BRANCAS;
        else
        {
                Time *bra = new Time(IPeca::BRANCO);
                bra->adicionarBispo(&iBB1);
                bra->adicionarBispo(&BB2);

                return bra;
        }
}

void Mock::initMock()
{
        obterConjunto();
}

void Mock::testarMovimentosBispo()
{
        std::vector<Movimento *> movimentos;

        iBB1.gerarMovimentos(movimentos);

        movimentos.clear();

        BB2.gerarMovimentos(movimentos);
}

void Mock::testarMovimentosTorre()
{
        std::vector<Movimento *> movimentos;

        TP1.gerarMovimentos(movimentos);

        movimentos.clear();
}

void Mock::testarMovimentosDama()
{
        std::vector<Movimento *> movimentos;

        DP1.gerarMovimentos(movimentos);

        movimentos.clear();
}
