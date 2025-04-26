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
                                                             conjunto(conjunto)
{
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosCardeais(std::vector<Movimento *> &movimentos, bool reiChamou) const
{
        this->gerarMovs(movimentos, reiChamou, false);
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosColaterais(std::vector<Movimento *> &movimentos, bool reiChamou) const
{
        this->gerarMovs(movimentos, reiChamou, true);
}

void IPeca::gerarMovs(std::vector<Movimento *> &movimentos, bool reiChamou, bool discriminante) const
{
        Posicao incr_auxiliar = discriminante ? Posicao(1, 1) : Posicao(1, 0);


        for(int i = 0; i < 4; ++i)
        {
                Posicao incremento = incr_auxiliar;

                while(true)
                {
                        Posicao *n_pos = *posicao + incremento;
                        bool destruir_n_pos = true;

                        if(n_pos->validarPosicao())
                        {
                                int ocupada = conjunto->ocupadaPor(n_pos);

                                if(ocupada != cor) // Se há uma peça da mesma cor nesta posição, o movimento não deve ser gerado
                                {
                                        auto n_mov = new Movimento(n_pos);

                                        if(ocupada == cor) n_mov->definirNatureza(Movimento::NEUTRO);
                                        movimentos.emplace_back(n_mov);

                                        destruir_n_pos = false; // se o movimento é gerado, ele não deve ser destruído
                                }
                        }

                        if(destruir_n_pos)
                        {
                                delete n_pos;
                                break; // se o último movimento deve ser destruído, quer dizer que não há mais movimentos possíveis nessa direção
                        }

                        if(reiChamou) break;

                        incremento += incr_auxiliar;
                }

                incr_auxiliar.rotacionarEm90();
        }
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

IPeca::IPeca(int cor, Posicao *posicao): cor(cor),
                                         posicao(posicao)
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

void IPeca::definirConjunto(Conjunto *con)
{
        conjunto = con;
}
