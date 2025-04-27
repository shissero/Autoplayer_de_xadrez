//
// Created by cicero on 23/04/25.
//

#ifndef ADMINISTRADORDEJOGO_H
#define ADMINISTRADORDEJOGO_H
#include "Tabuleiro.h"


class AdministradorDeJogo {

public:

    void instanciarTabuleiro();

    void selecionarCasa(Posicao *);

    //static void capturar(Posicao, int);

    //static void definirEnPassant(Peao *);

    //static void definirStatusEnPassant(bool);



private:
    Tabuleiro *tabPrincipal = nullptr;
};



#endif //ADMINISTRADORDEJOGO_H
