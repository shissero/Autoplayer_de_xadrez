//
// Created by cicero on 25/04/25.
//

#include "Mock.h"

#include "Conjunto.h"
#include "Time.h"


Cavalo Mock::CB1 = Cavalo(IPeca::BRANCO, new Posicao(4, 4));
Cavalo Mock::CB2 = Cavalo(IPeca::BRANCO, new Posicao(6, 5));
Bispo Mock::iBB1 = Bispo(IPeca::BRANCO, new Posicao(4, 3));
Bispo Mock::BB2 = Bispo(IPeca::BRANCO, new Posicao(3, 3));

Peao Mock::PP1 = Peao(IPeca::PRETO, new Posicao(5, 0));
Torre Mock::TP1 = Torre(IPeca::PRETO, new Posicao(4, 3));
Dama Mock::DP1 = Dama(IPeca::PRETO, new Posicao(5, 5));
Rei Mock::RP1 = Rei(IPeca::PRETO, new Posicao(0, 6));

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
        obterPretas();

        CONJ = new Conjunto();

        CONJ->definirAliadas(BRANCAS);
        CONJ->definirAdversarias(PRETAS);

        return CONJ;
}

Time *Mock::obterBrancas()
{
        if(BRANCAS != nullptr) return BRANCAS;

        BRANCAS = new Time(IPeca::BRANCO);

        BRANCAS->adicionarBispo(&iBB1);
        BRANCAS->adicionarBispo(&BB2);

        BRANCAS->adicionarCavalo(&CB1);
        BRANCAS->adicionarCavalo(&CB2);

        return BRANCAS;
}

Time * Mock::obterPretas()
{
        if(PRETAS != nullptr) return PRETAS;

        PRETAS = new Time(IPeca::PRETO);

        PRETAS->adicionarPeao(&PP1);
        PRETAS->adicionarDama(&DP1);

        return PRETAS;
}

void Mock::initMock()
{
        obterConjunto();
}

void Mock::testarMovimentosBispo()
{
        std::vector<Movimento *> movimentos;

        BB2.gerarMovimentos(movimentos);

        return;
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

        bool result = false;

        for(Movimento *m : movimentos) if(m->obterNatureza() != Movimento::NEUTRO) result = true;

        return;;
}

void Mock::testarMovimentosCavalo()
{
        std::vector<Movimento *> movimentos;

        CB1.gerarMovimentos(movimentos);

        return;
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
        auto pos_vazia = Posicao(1, 7);
        auto pos_ali = Posicao(4, 4);
        auto pos_adv = Posicao(5, 0);

        Conjunto *con = CONJ;

        int resultado1 = CONJ->ocupadaPor(&pos_vazia);
        int resultado2 = CONJ->ocupadaPor(&pos_ali);
        int resultado3 = CONJ->ocupadaPor(&pos_adv);

        return;
}
