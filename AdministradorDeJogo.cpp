//
// Created by cicero on 23/04/25.
//

#include "AdministradorDeJogo.h"

void AdministradorDeJogo::instanciarTabuleiro()
{
        this->tabPrincipal = Tabuleiro::criarTabuleiroCompleto();
}

void AdministradorDeJogo::selecionarCasa(Posicao *selecao)
{
        if(tabPrincipal->obterPecaTocada() == nullptr)
        {
                tabPrincipal->definirTocada(selecao);
        }
        else
        {
                Movimento *aux = tabPrincipal->buscarMovimentoTocada(selecao);

                if(aux != nullptr)
                {
                        tabPrincipal->executarMovimento(aux);
                        tabPrincipal->passarVez();
                }
                else
                {
                        //tocarPeca(coluna, linha);
                }
        }
}
