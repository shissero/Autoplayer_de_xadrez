//
// Created by cicero on 25/04/25.
//

#include "AssistenteLogging.h"

#include <vector>

std::string AssistenteLogging::comoString(Movimento &movimento)
{
        std::vector<std::string> naturezas = {"neutro"};

        return comoString(movimento.obterDestino()) + ", " + naturezas[movimento.obterNatureza()];
}

std::string AssistenteLogging::comoString(Posicao &posicao)
{
        return "{" + std::to_string(posicao.coluna()) + ", " + std::to_string(posicao.linha()) + "}";
}

std::string AssistenteLogging::comoString(IPeca &)
{
        return "Loggin IPeca not implemented";
}
