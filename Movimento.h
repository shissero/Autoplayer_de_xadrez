/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 05/01/2021

*/

#ifndef MOVIMENTO_H_
#define MOVIMENTO_H_

#include"Posicao.h"


class Movimento
{
public:
        Movimento(int, Posicao *);

        Posicao &obterDestino() const;

        int obterNatureza() const;

        static constexpr int NEUTRO = 0;
        static constexpr int CAPTURA = 1;
        static constexpr int EN_PASSANT_PASSIVA = 2;
        static constexpr int EN_PASSANT_ATIVA = 3;
        static constexpr int ROQUE = 4;

private:
        int natureza = -1; // Inicializado com valor negativo para garantir que será diferente dos valores de natureza definidos pela classe
        Posicao *destino = nullptr;
};

#endif
