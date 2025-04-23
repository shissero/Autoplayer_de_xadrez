//
// Created by cicero on 23/04/25.
//

#include "PosicaoInvalida.h"

PosicaoInvalida::PosicaoInvalida(const int coluna, const int linha) :
    IExcecao("Posição inválida: cooordenadas (" + std::to_string(coluna) + ", " + std::to_string(linha) + ")"){
}
