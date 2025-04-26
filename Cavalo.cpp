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

                        if(n_pos->validarPosicao())
                        {
                                auto n_mov = new Movimento(n_pos);

                                /*if(this -> estaVazia(n_pos))*/
                                n_mov->definirNatureza(Movimento::NEUTRO);
                                movimentos.emplace_back(n_mov);
                                /*else
                                {
                                        if(Conjunto::inimigaOcupa(this->cor, n_pos)) movimentos->push_back(new Movimento(n_pos, CAPTURA));
                                        break;
                                }

                                /*if(reiChamou)
                                {
                                        break;
                                }*/
                        }
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
