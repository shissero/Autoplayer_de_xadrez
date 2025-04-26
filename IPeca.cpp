/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"IPeca.h"

#include"Conjunto.h"
#include "PosicaoInvalida.h"

#include<vector>



//IPeca::IPeca() : cor(0), posicao(nullptr), conjunto(nullptr) {}

IPeca::IPeca(int cor, Posicao *posicao, Conjunto *conjunto): cor(cor),
                                                                   posicao(posicao),
                                                                   conjunto(conjunto){
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosCardeais(std::vector<Movimento *> &movimentos, bool reiChamou) const
{
        this -> gerarMovs(movimentos, reiChamou, false);
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosColaterais(std::vector<Movimento*> &movimentos, bool reiChamou) const
{
        this -> gerarMovs(movimentos, reiChamou, true);
}

void IPeca::gerarMovs(std::vector<Movimento *> &movimentos, bool reiChamou, bool discriminante) const
{
        Posicao incr_auxiliar = discriminante ? Posicao(1, 1) : Posicao(1, 0);


        for(int i = 0; i < 4; ++i)
        {
                Posicao incremento = incr_auxiliar;

                while(true)
                {
                        try
                        {
                                Posicao *n_pos = *posicao + incremento;

                                if( !(n_pos -> validarPosicao()) ) throw PosicaoInvalida(*n_pos);

                                auto n_mov = new Movimento(n_pos);

                                /*if(this -> estaVazia(n_pos))*/ n_mov ->definirNatureza(Movimento::NEUTRO); movimentos.emplace_back(n_mov);
                                /*else
                                {
                                        if(Conjunto::inimigaOcupa(this->cor, n_pos)) movimentos->push_back(new Movimento(n_pos, CAPTURA));
                                        break;
                                }

                                /*if(reiChamou)
                                {
                                        break;
                                }*/
                                incremento += incr_auxiliar;
                        }
                        catch(PosicaoInvalida &e)
                        {
                                break;
                        }
                }

                incr_auxiliar.rotacionarEm90();
        }
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

IPeca::IPeca(int cor, Posicao *posicao): cor(cor),
                                         posicao(posicao),
                                         conjunto(nullptr)
{
}

int IPeca::obterCor() const
{
        return cor;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

const Posicao *IPeca::obterPosicao() const
{
        return posicao;
}
