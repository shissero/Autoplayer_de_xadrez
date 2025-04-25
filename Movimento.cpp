/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 25/04/2025

*/

#include"Movimento.h"

#include <stdexcept>

/***********************************************************************************************************************
************************************************************************************************************************
***********************************************************************************************************************/

Movimento::Movimento(int nat, Posicao *des) : natureza(nat), destino(des)
{
}

Movimento::Movimento(Posicao *destino): destino(destino)
{
}

Posicao &Movimento::obterDestino() const
{
        return *destino;
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
        return !(nat < NEUTRO || nat > ROQUE);
}

void Movimento::definirNatureza(int nat)
{
        natureza = nat;
}
