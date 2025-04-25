/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2028

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

void IPeca::gerarMovimentosCardeais(std::vector<Movimento *> &movimentos, bool reiChamou)
{
        /*
                Posicao aux;

                // Gerar movimentos no sentido decrescente das linhas
                if(this -> posicao.linha > 1){

                        for(int i = this -> posicao.linha - 1; i > 0; i--) {

                                aux = new Posicao(this -> posicao.coluna, i);

                                if(Conjunto::estaVazia(*aux)){

                                        Movimento *mov = new Movimento(*aux, NEUTRO);

                                        movimentos -> push_back(mov);
                                }
                                else{
                                        if(Conjunto::inimigaOcupa(this -> cor, *aux)){

                                                Movimento *mov = new Movimento(*aux, CAPTURA);

                                                movimentos -> push_back(mov);
                                        }

                                        break;
                                }

                                if(reiChamou){

                                        break;
                                }

                        }

                }

                // Gerar movimentos no sentido crescente das linhas
                if(this -> posicao.linha < 8 ){

                        for(int i = this -> posicao.linha + 1; i < 9; i++){

                                aux = new Posicao(this -> posicao.coluna, i);

                                if(Conjunto::estaVazia(*aux)){

                                        Movimento *mov = new Movimento(*aux, NEUTRO);

                                        movimentos -> push_back(mov);
                                }
                                else{
                                        if(Conjunto::inimigaOcupa(this -> cor, *aux)){

                                                Movimento *mov = new Movimento(*aux, CAPTURA);

                                                movimentos -> push_back(mov);
                                        }

                                        break;
                                }

                                if(reiChamou){

                                        break;
                                }

                        }

                }

                // Gerar movimentos no sentido decrescente das colunas
                if(this -> posicao.coluna > 1){

                        for(int i = this -> posicao.coluna - 1; i > 0; i--){

                                aux = new Posicao(i, this -> posicao.linha);

                                if(Conjunto::estaVazia(*aux)){

                                        Movimento *mov = new Movimento(*aux, NEUTRO);

                                        movimentos -> push_back(mov);
                                }
                                else{
                                        if(Conjunto::inimigaOcupa(this -> cor, *aux)){

                                                Movimento *mov = new Movimento(*aux, CAPTURA);

                                                movimentos -> push_back(mov);
                                        }

                                        break;
                                }

                                if(reiChamou){

                                        break;
                                }

                        }

                }

                // Gerar movimentos no sentido crescente das colunas
                if(this -> posicao.coluna < 8){

                        for(int i = this -> posicao.coluna + 1; i < 9; i++){

                                aux = new Posicao(i, this -> posicao.linha);

                                if(Conjunto::estaVazia(*aux)){

                                        Movimento *mov = new Movimento(*aux, NEUTRO);

                                        movimentos -> push_back(mov);
                                }
                                else{
                                        if(Conjunto::inimigaOcupa(this -> cor, *aux)){

                                                Movimento *mov = new Movimento(*aux, CAPTURA);
                                                movimentos -> push_back(mov);
                                        }

                                        break;
                                }

                                if(reiChamou){

                                        break;
                                }

                        }

                }*/
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosColaterais(std::vector<Movimento*> &movimentos, bool reiChamou) const
{
        Posicao incr_auxiliar = Posicao(1, 1);


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
