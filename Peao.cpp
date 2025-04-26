/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Peao.h"

#include"IPeca.h"
#include"Movimento.h"

#include<vector>


Peao::Peao(int cor, Posicao *posicao) : IPeca(cor, posicao)
{
}

Peao::Peao(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto)
{
}

Peao::Peao(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto) {
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

void Peao::gerarMovimentos(std::vector<Movimento *> &movimentos)
{
        Posicao incremento_front = Posicao(0, cor);


        Posicao *n_pos = *posicao + incremento_front;

        if(n_pos -> validarPosicao())
        {
                movimentos.emplace_back(new Movimento(Movimento::NEUTRO, n_pos));


                n_pos = *n_pos + incremento_front;

                if(n_pos -> validarPosicao())
                {
                        movimentos.emplace_back(new Movimento(Movimento::NEUTRO, n_pos));
                }
        }


   /*     n_pos = Posicao(this->posicao.coluna - 1, this->posicao.linha + this->cor);

        if(this->posicao.coluna > 1)
        {
                if(Conjunto::inimigaOcupa(this->cor, n_pos))
                {
                        vetor->push_back(new Movimento(n_pos, CAPTURA));
                }
                else if(Conjunto::valeEnPassant(n_pos, -(this->cor)))
                {
                        vetor->push_back(new Movimento(n_pos, EN_PASSANT_ATIVA));
                }
        }


        n_pos = Posicao(this->posicao.coluna + 1, this->posicao.linha + this->cor);

        if(this->posicao.coluna<8)
        {
                if(Conjunto::inimigaOcupa(this->cor, n_pos))
                {
                        vetor->push_back(new Movimento(n_pos, CAPTURA));
                }
                else if(Conjunto::valeEnPassant(n_pos, -(this->cor)))
                {
                        vetor->push_back(new Movimento(n_pos, EN_PASSANT_ATIVA));
                }
        }*/
}

bool Peao::obterPrimeiroMovimento() const
{
        return primeiroMovimento;
}

void Peao::definirPrimeiroMovimento(bool valor)
{
        primeiroMovimento = valor;
}
