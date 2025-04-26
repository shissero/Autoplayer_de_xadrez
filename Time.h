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

    static Time *criarTimeCompleto(int, Conjunto *conjunto);

    void adicionarPeao(Peao*);

    void adicionarTorre(Torre*);

    void adicionarBispo(Bispo*);

    void adicionarCavalo(Cavalo*);

    //void adicionarDama(Dama*);

    //void definirRei(Rei*);

    //void definirDama(Dama*);

    int obterCor() const;

    bool ocupada(Posicao&) const;

private:
    int cor = 0;
    int linhaPeca = 0;
    std::vector<Peao*> peoes;
    std::vector<Torre*> torres;
    std::vector<Cavalo*> cavalos;
    std::vector<Bispo*> bispos;
    Dama *dama = nullptr;
    Rei *rei = nullptr;
    std::vector<IPeca*> todasPecas;

    void adicionarBisposPadrao(Conjunto *conjunto);

    void adicionarPeoesPadrao(Conjunto *conjunto);

    void adicionarTorresPadrao(Conjunto *conjunto);

    void adicionarCavalosPadrao(Conjunto *conjunto);
};



#endif //TIME_H
