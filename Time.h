//
// Created by cicero on 23/04/25.
//

#ifndef TIME_H
#define TIME_H

#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Posicao.h"
#include "Rei.h"
#include "Torre.h"

#include <vector>


class Time {

public:
    explicit Time(int);

    Time(const Time&);

    ~Time();

    static Time *criarTimeCompleto(int, Tabuleiro *tabuleiro);

    void adicionarPeao(Peao*);

    void adicionarTorre(Torre*);

    void adicionarBispo(Bispo*);

    void adicionarCavalo(Cavalo*);

    void adicionarDama(Dama*);

    void adicionarRei(Rei*);

    void destruir(Posicao*);

    int obterCor() const;

    void definirTabuleiro(Tabuleiro*);

    bool ocupada(Posicao *) const;

    bool atacada(const Posicao *) const;

    const Posicao *obterPosicaoRei() const;

    IPeca *obterPeca(const Posicao *) const;

private:
    int cor = 0;
    int linhaPeca = 0;
    std::vector<Peao*> peoes;
    std::vector<Torre*> torres;
    std::vector<Cavalo*> cavalos;
    std::vector<Bispo*> bispos;
    std::vector<Dama*> damas;
    Rei *rei = nullptr;
    std::vector<IPeca*> todasPecas;

    void adicionarBisposPadrao(Tabuleiro *tabuleiro);

    void adicionarPeoesPadrao(Tabuleiro *tabuleiro);

    void adicionarTorresPadrao(Tabuleiro *tabuleiro);

    void adicionarCavalosPadrao(Tabuleiro *tabuleiro);
};



#endif //TIME_H
