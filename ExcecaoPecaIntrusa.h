//
// Created by cicero on 23/04/25.
//

#ifndef EXCECAOPECAINTRUSA_H
#define EXCECAOPECAINTRUSA_H
#include "IExcecao.h"
#include "IPeca.h"


class ExcecaoPecaIntrusa : public IExcecao{
public:
    explicit ExcecaoPecaIntrusa(const IPeca&);
    ~ExcecaoPecaIntrusa() noexcept override = default;

    const char * what() const noexcept override;
};



#endif //EXCECAOPECAINTRUSA_H
