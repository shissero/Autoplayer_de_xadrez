//
// Created by cicero on 23/04/25.
//

#include "ExcecaoPecaExcedente.h"

ExcecaoPecaExcedente::ExcecaoPecaExcedente() : IExcecao("Excecao PecaExcedente"){
}

const char * ExcecaoPecaExcedente::what() const noexcept {

    return mensagem.c_str();
}
