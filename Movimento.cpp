/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Movimento.h"

/***********************************************************************************************************************
************************************************************************************************************************
***********************************************************************************************************************/

Movimento::Movimento(int nat, Posicao *des) : natureza(nat), destino(des)
{
}

Movimento::Movimento(Posicao *destino): destino(destino)
{
}

Posicao *Movimento::obterDestino() const
{
        return destino;
}

/***********************************************************************************************************************
************************************************************************************************************************
***********************************************************************************************************************/

int Movimento::obterNatureza() const
{
        return natureza;
}

bool Movimento::validarNatureza(int nat)
{
        return !(nat < DESLOCAMENTO || nat > ROQUE);
}

void Movimento::definirNatureza(int nat)
{
        natureza = nat;
}
