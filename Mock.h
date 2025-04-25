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
        ~Mock();

        // Pecas prefixadas com i- estão em alguma das suas possíveis posições iniciais no tabuleiro
        static Bispo iBB1;
        static Bispo BB2;
        static Time *BRANCAS;
        static Conjunto *CONJ;

        static Conjunto *obterConjunto();
        static Time *obterBrancas();

        static void initMock();

        static void testarMovimentosBispoInicial();
};



#endif //MOCK_H
