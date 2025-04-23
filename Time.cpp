//
// Created by cicero on 23/04/25.
//

#include "ExcecaoPecaExcedente.h"
#include "ExcecaoPecaIntrusa.h"

#include "Time.h"

#include <iostream>

Time::Time(int cor) : cor(cor) {
}

Time *Time::criarTimeCompleto(int cor) {

    Time *novo = new Time(cor);

    int linha_pecas = 4.5f - cor*(3.5f);

    novo -> adicionarBispo(new Bispo(cor, new Posicao(3, linha_pecas)));
    novo -> adicionarBispo(new Bispo(cor, new Posicao(6, linha_pecas)));

    return novo;
}

void Time::adicionarBispo(Bispo *bispo) {

    if (bispo -> obterCor() != cor) throw ExcecaoPecaIntrusa(*bispo);

    if (bispos.size() >= 2) throw ExcecaoPecaExcedente();

    bispos.emplace_back(bispo);
}
