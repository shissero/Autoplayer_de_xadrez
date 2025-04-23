//
// Created by cicero on 23/04/25.
//

#ifndef TIME_H
#define TIME_H

#include "Bispo.h"

#include <vector>


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

protected:
    const int cor;
    //std::vector<Peao*> peoes;
    //std::vector<Torre*> torres;
    //std::vector<Cavalo*> cavalos;
    std::vector<Bispo*> bispos;
    //Dama *dama;
    //Rei *rei;
};



#endif //TIME_H
