//
// Created by cicero on 25/04/25.
//

#ifndef ASSISTENTELOGGING_H
#define ASSISTENTELOGGING_H
#include "IPeca.h"
#include "Movimento.h"

#include <string>
#include <vector>


class AssistenteLogging {

public:
        static std::string comoString(Movimento &);
        static std::string comoString(Posicao &);

        static std::string comoString(IPeca &);

        template<typename T>
        static std::string comoString(std::vector<T*>&);

};

template<typename T>
std::string AssistenteLogging::comoString(std::vector<T*> &vec)
{
        std::string resultado = "";

        for(T *t : vec) resultado = comoString(*t);

        return resultado;
}


#endif //ASSISTENTELOGGING_H
