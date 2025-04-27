/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"IPeca.h"

#include"Tabuleiro.h"
#include "PosicaoInvalida.h"

#include<vector>


//IPeca::IPeca() : cor(0), posicao(nullptr), tabuleiro(nullptr) {}

IPeca::IPeca(int cor, Posicao *posicao, Tabuleiro *tabuleiro): cor(cor),
                                                             posicao(posicao),
                                                             tabuleiro(tabuleiro)
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
                bool continuar = true;

                while(continuar)
                {
                        Posicao *n_pos = *posicao + incremento;
                        bool destruir_n_pos = true;


                        if(n_pos->validarPosicao())
                        {
                                int ocupada = tabuleiro->ocupadaPor(n_pos);

                                if(ocupada != cor) // O movimento só é gerado se não houver uma peça de mesma naquela posição
                                {
                                        auto n_mov = new Movimento(n_pos);

                                        // Decide se o movimento é de deslocamento ou captura
                                        if(ocupada == Tabuleiro::VAZIA) n_mov->definirNatureza(Movimento::DESLOCAMENTO);
                                        else
                                        {
                                                n_mov->definirNatureza(Movimento::CAPTURA);
                                                continuar = false; // um movimento de captura é o último numa determinada direção
                                        }

                                        movimentos.emplace_back(n_mov);

                                        destruir_n_pos = false; // se o movimento é gerado, ele não deve ser destruído
                                }
                        }

                        if(destruir_n_pos)
                        {
                                delete n_pos;
                                // se a última posição deve ser destruída, quer dizer que,
                                // ou é inválida, ou tem uma aliada naquela posicao. Nos dois
                                // casos, não há mais movimentos possíveis nessa direção
                                break;
                        }

                        if(reiChamou) break;

                        incremento += incr_auxiliar;
                }

                // Após gerar todos os movimentos possíveis numa direção,
                // giramos o incremento em 90º para gerar os movimentos
                // na próxima direção.
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

void IPeca::gerarCasasAtacadas(std::vector<Movimento *> &movimentos) {

        this -> gerarMovimentos(movimentos);
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

void IPeca::definirTabuleiro(Tabuleiro *con)
{
        tabuleiro = con;
}
