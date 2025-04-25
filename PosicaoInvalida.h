//
// Created by cicero on 23/04/25.
//

#ifndef INVALIDPOSITION_H
#define INVALIDPOSITION_H

#include "IExcecao.h"
#include "Posicao.h"

#include <string>


class PosicaoInvalida : public IExcecao
{
public:
        PosicaoInvalida(int, int);

        explicit PosicaoInvalida(Posicao &);

        ~PosicaoInvalida() noexcept override = default;

private:
        std::string message;
};


#endif //INVALIDPOSITION_H
