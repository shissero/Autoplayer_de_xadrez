/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef MOVIMENTO_H_
#define MOVIMENTO_H_

#include"Posicao.h"


class Movimento
{
public:
        Movimento() = default;

        Movimento(int, Posicao *);

        explicit Movimento(Posicao *destino);

        Posicao &obterDestino() const; // TODO: conferir se os getters e setters em outras classes estão seguindo o padrão

        int obterNatureza() const;

        void definirNatureza(int nat);

        // Constantes de natureza devem ser inteiros positivos.
        // Não se deve pular inteiros, i.e., se uma naturez tiver
        // valor 6, todos os inteiros de 0 a 6 devem ser atribuídos
        // a alguma natureza. Se essa regra for mudade, é preciso
        // reimplementar a função validarNatureza
        static constexpr int NEUTRO = 0;
        static constexpr int CAPTURA = 1;
        static constexpr int EN_PASSANT_PASSIVA = 2;
        static constexpr int EN_PASSANT_ATIVA = 3;
        static constexpr int ROQUE = 4;

private:
        int natureza = -1; // Inicializado com valor negativo para garantir que será diferente dos valores de natureza definidos pela classe
        Posicao *destino = nullptr;

        static bool validarNatureza(int);
};

#endif
