//
// Created by cicero on 23/04/25.
//

#ifndef TIME_H
#define TIME_H

#include "Bispo.h"

#include <vector>

#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Torre.h"


class Time {

public:
    explicit Time(int);

    static Time *criarTimeCompleto(int);

    void adicionarBispo(Bispo*);

    //void adicionarCavalo(Cavalo*);

    //void adicionarDama(Dama*);

    //void adicionarPeao(Peao*);

    //void definirRei(Rei*);

    //void definirDama(Dama*);

private:
    const int cor;
    int linhaPeca;
    std::vector<Peao*> peoes;
    std::vector<Torre*> torres;
    std::vector<Cavalo*> cavalos;
    std::vector<Bispo*> bispos;
    Dama *dama;
    //Rei *rei;

    void adicionarBisposPadrao();

    void adicionarPeoesPadrao();

    void adicionarTorresPadrao();

    void adicionarCavalosPadrao();
};



#endif //TIME_H
