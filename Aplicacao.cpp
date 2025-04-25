//
// Created by cicero on 25/04/25.
//

#include "Aplicacao.h"

#include "Log.h"
#include "Mock.h"

void Aplicacao::iniciar()
{
        Log::initLog();
        Mock::initMock();
}

void Aplicacao::finalizar()
{
        Log::finishLog();
}
