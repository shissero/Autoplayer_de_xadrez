//
// Created by cicero on 23/04/25.
//

#include "IExcecao.h"

IExcecao::IExcecao(const std::string &mensagem)
        : mensagem(mensagem) {
}

const char * IExcecao::what() const noexcept {

        return mensagem.c_str();
}
