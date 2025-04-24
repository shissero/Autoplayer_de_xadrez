//
// Created by cicero on 23/04/25.
//

#include "ExcecaoPecaExcedente.h"
#include "ExcecaoPecaIntrusa.h"

#include "Time.h"

#include <iostream>

#include "Cavalo.h"

Time::Time(int cor) : cor(cor), linhaPeca(3.5f - cor*(3.5f)) {
}

Time *Time::criarTimeCompleto(int cor) {

    Time *novo = new Time(cor);

    novo -> adicionarBisposPadrao();
    novo -> adicionarPeoesPadrao();
    novo -> adicionarTorresPadrao();
    novo -> adicionarCavalosPadrao();
    novo -> dama = new Dama(cor, new Posicao(3, novo -> linhaPeca));
    novo -> rei = new Rei(cor, new Posicao(4, novo -> linhaPeca));

    return novo;
}

void Time::adicionarBispo(Bispo *bispo) {

    if (bispo -> obterCor() != cor) throw ExcecaoPecaIntrusa(*bispo);

    if (bispos.size() >= 2) throw ExcecaoPecaExcedente();

    bispos.emplace_back(bispo);
}

void Time::adicionarBisposPadrao() {

    bispos.emplace_back(new Bispo(cor, new Posicao(2, linhaPeca)));
    bispos.emplace_back(new Bispo(cor, new Posicao(5, linhaPeca)));
}

void Time::adicionarPeoesPadrao() {

    for(int i = 0; i < 8; i++) peoes.emplace_back(new Peao(cor, new Posicao(i, linhaPeca + cor)));
}

void Time::adicionarTorresPadrao() {

    torres.emplace_back(new Torre(cor, new Posicao(0, linhaPeca)));
    torres.emplace_back(new Torre(cor, new Posicao(7, linhaPeca)));
}

void Time::adicionarCavalosPadrao() {

    cavalos.emplace_back(new Cavalo(cor, new Posicao(1, linhaPeca)));
    cavalos.emplace_back(new Cavalo(cor, new Posicao(6, linhaPeca)));
}
