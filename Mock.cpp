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
Cavalo Mock::CB1 = Cavalo(IPeca::BRANCO, new Posicao(4, 4));
Cavalo Mock::CB2 = Cavalo(IPeca::BRANCO, new Posicao(7, 4));
Peao Mock::PP1 = Peao(IPeca::PRETO, new Posicao(5, 0));
Rei Mock::RP1 = Rei(IPeca::PRETO, new Posicao(5, 5));
Time *Mock::BRANCAS = nullptr;
Time *Mock::PRETAS = nullptr;
Conjunto *Mock::CONJ = nullptr;

Mock::~Mock()
{
}

Conjunto *Mock::obterConjunto()
{
        if(CONJ != nullptr) return CONJ;

        obterBrancas();

        CONJ = new Conjunto();

        CONJ->definirAliadas(BRANCAS);

        return CONJ;
}

Time *Mock::obterBrancas()
{
        if(BRANCAS != nullptr) return BRANCAS;

        BRANCAS = new Time(IPeca::BRANCO);

        BRANCAS->adicionarBispo(&iBB1);
        BRANCAS->adicionarBispo(&BB2);

        BRANCAS->adicionarCavalo(&CB1);

        return BRANCAS;
}

Time * Mock::obterPretas()
{
        if(PRETAS != nullptr) return PRETAS;

        PRETAS = new Time(IPeca::PRETO);

        return PRETAS;
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

void Mock::testarMovimentosCavalo()
{
        std::vector<Movimento *> movimentos;

        CB1.gerarMovimentos(movimentos);

        movimentos.clear();

        CB2.gerarMovimentos(movimentos);

        movimentos.clear();
}

void Mock::testarMovimentosPeao()
{
        std::vector<Movimento *> movimentos;

        PP1.gerarMovimentos(movimentos);

        movimentos.clear();
}

void Mock::testarMovimentosRei()
{
        std::vector<Movimento *> movimentos;

        RP1.gerarMovimentos(movimentos);

        movimentos.clear();
}

void Mock::testarTimeOcupada()
{
        Posicao aux_posicao1 = Posicao(4, 4);
        Posicao aux_posicao2 = Posicao(0, 4);

        bool resultado1 = BRANCAS->ocupada(aux_posicao1);
        bool resultado2 = BRANCAS->ocupada(aux_posicao2);

        return;
}
