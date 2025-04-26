/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Cavalo.h"

#include"Conjunto.h"
#include"IPeca.h"
#include"Posicao.h"
#include "PosicaoInvalida.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/

void Cavalo::gerarMovimentos(std::vector<Movimento *> &movimentos)
{
        Posicao incremento = Posicao(2, 1);


        for(int i = 0; i < 2; ++i)
        {
                for(int j = 0; j < 4; ++j)
                {
                        Posicao *n_pos = *posicao + incremento;
                        bool destruir_n_pos = true;

                        if(n_pos->validarPosicao()) // TODO: é necessário fazer o gerenciamento de memória dessa função
                        {
                                int ocupada = conjunto->ocupadaPor(n_pos);

                                if(ocupada != cor)
                                {
                                        auto n_mov = new Movimento(n_pos);

                                        if(ocupada == Conjunto::VAZIA) n_mov->definirNatureza(Movimento::DESLOCAMENTO);
                                        else n_mov->definirNatureza(Movimento::CAPTURA);

                                        movimentos.emplace_back(n_mov);

                                        destruir_n_pos = false;
                                }
                        }

                        if(destruir_n_pos) delete n_pos;

                        incremento.rotacionarEm90();
                }

                incremento = Posicao(2, -1);
        }
}

Cavalo::Cavalo(int cor, Posicao *posicao): IPeca(cor, posicao)
{
}

Cavalo::Cavalo(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto)
{
}
