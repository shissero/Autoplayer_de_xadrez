//
// Created by cicero on 23/04/25.
//

#ifndef EXCECAOPECAEXCEDENTE_H
#define EXCECAOPECAEXCEDENTE_H
#include "IExcecao.h"


class ExcecaoPecaExcedente : public IExcecao{
public:
    ExcecaoPecaExcedente();
    ~ExcecaoPecaExcedente() noexcept override = default;

    const char *what() const noexcept override;
};


#endif //EXCECAOPECAEXCEDENTE_H
