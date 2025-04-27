//
// Created by cicero on 25/04/25.
//

#ifndef MOCK_H
#define MOCK_H

#include "Bispo.h"
#include "Peao.h"
#include "Time.h"


class Mock {

public:
        ~Mock() = default;

        // Pecas prefixadas com i- estão em alguma das suas possíveis posições iniciais no tabuleiro
        static Torre *TP1;
        static Dama *DP1;
        static Peao *PP1;
        static Rei RP1;

        static Bispo *iBB1;
        static Bispo *BB2;
        static Bispo BB3;
        static Cavalo *CB1;
        static Cavalo CB2;

        static Time *BRANCAS;
        static Time *PRETAS;
        static Tabuleiro *TAB;

        static Tabuleiro *obterTabuleiro();

        static void obterTabTestMovsBispo();

        static void obterTabTestMovsTorre();

        static void obterTabTestMovsDama();

        static void finalizarMock();
        static Time *obterBrancas();

        static Time *obterPretas();

        static void initMock();

        static void testarMovimentosBispo();

        static void testarMovimentosTorre();

        static void testarMovimentosDama();

        static void testarMovimentosCavalo();

        static void testarMovimentosPeao();

        static void testarMovimentosRei();

        static void testarTimeOcupada();
};



#endif //MOCK_H
