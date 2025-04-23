//
// Created by cicero on 23/04/25.
//

#include "ExcecaoPecaIntrusa.h"

ExcecaoPecaIntrusa::ExcecaoPecaIntrusa(const IPeca &peca) :
    IExcecao("ExceçãoPecaIntrusa"){
}

const char * ExcecaoPecaIntrusa::what() const noexcept {
    return IExcecao::what();
}
