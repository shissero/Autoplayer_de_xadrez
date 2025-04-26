/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Peao.h"

#include "Conjunto.h"
#include"IPeca.h"
#include"Movimento.h"

#include<vector>


Peao::Peao(int cor, Posicao *posicao) : IPeca(cor, posicao)
{
}

Peao::Peao(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto)
{
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

void Peao::gerarMovimentos(std::vector<Movimento *> &movimentos)
{
        Posicao incremento_front = Posicao(0, cor);
        Posicao incremento_ataque = Posicao(cor, cor);


        Posicao *n_pos = *posicao + incremento_front;
        bool destruir_n_pos = true;

        // Não é feita validação da posição dos movimentos de deslocamento.
        // Esse tipo de movimento é impossível de ser inválido, pois quando
        // o peão chega na borda, é promovido.
        int ocupada = conjunto->ocupadaPor(n_pos);

        if(ocupada == Conjunto::VAZIA)
        {
                movimentos.emplace_back(new Movimento(Movimento::DESLOCAMENTO, n_pos));
                // Gera-se o movimento onde o peão anda apenas uma casa


                if(primeiroMovimento) // Agora, tenta-se gerar o movimento onde se anda duas
                {
                        n_pos = *n_pos + incremento_front;

                        ocupada = conjunto->ocupadaPor(n_pos);

                        if(ocupada == Conjunto::VAZIA)
                        {
                                movimentos.emplace_back(new Movimento(Movimento::DESLOCAMENTO, n_pos));

                                destruir_n_pos = false; // Se o movimento é possível, a posição não é destruída
                        }
                }
                else destruir_n_pos = false;
        }

        if(destruir_n_pos) delete n_pos;


        destruir_n_pos = true; // Resetando o valor dessa variável, pois agora podem ocorrer movimentos inválidos

        for(int i = 0; i < 2; ++i)
        {
                n_pos = *posicao + incremento_ataque;

                if(n_pos->validarPosicao())
                {
                        int ocupada = conjunto->ocupadaPor(n_pos);

                        if(ocupada != cor && ocupada != Conjunto::VAZIA)
                        {

                                movimentos.emplace_back(new Movimento(Movimento::CAPTURA, n_pos));

                                destruir_n_pos = false;
                        }
                }

                if(destruir_n_pos) delete n_pos;

                incremento_ataque.rotacionarEm90();
        }
}

bool Peao::obterPrimeiroMovimento() const
{
        return primeiroMovimento;
}

void Peao::definirPrimeiroMovimento(bool valor)
{
        primeiroMovimento = valor;
}
