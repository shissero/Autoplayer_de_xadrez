/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Cavalo.h"

#include"Tabuleiro.h"
#include"IPeca.h"
#include"Posicao.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/

void Cavalo::gerarMovimentosCavalo(std::vector<Movimento *> &movimentos, bool ataque)
{
        Posicao incremento = Posicao(2, 1);


        for(int i = 0; i < 2; ++i)
        {
                for(int j = 0; j < 4; ++j)
                {
                        Posicao *n_pos = *posicao + incremento;
                        bool destruir_n_pos = true;

                        if(n_pos->validarPosicao())
                        {
                                int ocupada = tabuleiro->ocupadaPor(n_pos);

                                // Se a casa está ocupada por uma aliada
                                // e a funçnção está gerando movimentos
                                // de ataque, a posição é incluída.
                                if(ocupada == cor && ataque)
                                {
                                        auto n_mov = new Movimento(n_pos);

                                        n_mov->definirNatureza(Movimento::DESLOCAMENTO);

                                        movimentos.emplace_back(n_mov);

                                        destruir_n_pos = false;
                                }
                                else if(ocupada != cor)
                                {
                                        auto n_mov = new Movimento(n_pos);

                                        if(ocupada == Tabuleiro::VAZIA) n_mov->definirNatureza(Movimento::DESLOCAMENTO);
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

void Cavalo::gerarMovimentos(std::vector<Movimento *> &movimentos)
{
        this->gerarMovimentosCavalo(movimentos, false);
}

void Cavalo::gerarCasasAtacadas(std::vector<Movimento *> &movimentos)
{
        this->gerarMovimentosCavalo(movimentos, true);
}

Cavalo::Cavalo(int cor, Posicao *posicao): IPeca(cor, posicao)
{
}

Cavalo::Cavalo(int cor, Posicao *posicao, Tabuleiro *tabuleiro): IPeca(cor, posicao, tabuleiro)
{
}
