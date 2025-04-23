//
// Created by cicero on 23/04/25.
//

#ifndef INVALIDPOSITION_H
#define INVALIDPOSITION_H

#include "IExcecao.h"

#include <exception>
#include <string>


class PosicaoInvalida : public IExcecao {

public:

    PosicaoInvalida(int, int);

    ~PosicaoInvalida() noexcept override = default;

private:
    std::string message;
};



#endif //INVALIDPOSITION_H
