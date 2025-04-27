//
// Created by cicero on 23/04/25.
//

#include "Time.h"

#include "ExcecaoPecaExcedente.h"
#include "ExcecaoPecaIntrusa.h"

Time::Time(int cor) : cor(cor), linhaPeca(3.5f - cor * (3.5f))
{
}

Time *Time::criarTimeCompleto(int cor, Tabuleiro *tabuleiro)
{
        Time *novo = new Time(cor);

        novo->adicionarBisposPadrao(tabuleiro);
        novo->adicionarPeoesPadrao(tabuleiro);
        novo->adicionarTorresPadrao(tabuleiro);
        novo->adicionarCavalosPadrao(tabuleiro);
        novo->damas.emplace_back(new Dama(cor, new Posicao(3, novo->linhaPeca), tabuleiro));
        novo->rei = new Rei(cor, new Posicao(4, novo->linhaPeca), tabuleiro);

        return novo;
}

void Time::adicionarPeao(Peao *peao)
{
        if(peao->obterCor() != cor) throw ExcecaoPecaIntrusa(*peao);

        if(peoes.size() >= 2) throw ExcecaoPecaExcedente();

        peoes.emplace_back(peao);
        todasPecas.emplace_back(peao);
}

void Time::adicionarBispo(Bispo *bispo)
{
        if(bispo->obterCor() != cor) throw ExcecaoPecaIntrusa(*bispo);

        if(bispos.size() >= 2) throw ExcecaoPecaExcedente();

        bispos.emplace_back(bispo);
        todasPecas.emplace_back(bispo);
}

void Time::adicionarCavalo(Cavalo *cavalo)
{
        if(cavalo->obterCor() != cor) throw ExcecaoPecaIntrusa(*cavalo);

        if(cavalos.size() >= 2) throw ExcecaoPecaExcedente();

        cavalos.emplace_back(cavalo);
        todasPecas.emplace_back(cavalo);
}

void Time::adicionarDama(Dama *dama)
{
        damas.emplace_back(dama);
        todasPecas.emplace_back(dama);
}

int Time::obterCor() const
{
        return cor;
}

void Time::definirTabuleiro(Tabuleiro *tabuleiro)
{
        for(IPeca *p : todasPecas) p->definirTabuleiro(tabuleiro);
}

bool Time::ocupada(Posicao *pos) const
{

        for(IPeca *p : todasPecas)
        {
                if( *(p -> obterPosicao()) == pos ) return true;
        }

        return false;
}

void Time::adicionarBisposPadrao(Tabuleiro *tabuleiro)
{
        bispos.emplace_back(new Bispo(cor, new Posicao(2, linhaPeca), tabuleiro));
        bispos.emplace_back(new Bispo(cor, new Posicao(5, linhaPeca), tabuleiro));
}

void Time::adicionarPeoesPadrao(Tabuleiro *tabuleiro)
{
        for(int i = 0; i < 8; i++) peoes.emplace_back(new Peao(cor, new Posicao(i, linhaPeca + cor), tabuleiro));
}

void Time::adicionarTorresPadrao(Tabuleiro *tabuleiro)
{
        torres.emplace_back(new Torre(cor, new Posicao(0, linhaPeca), tabuleiro));
        torres.emplace_back(new Torre(cor, new Posicao(7, linhaPeca), tabuleiro));
}

void Time::adicionarCavalosPadrao(Tabuleiro *tabuleiro)
{
        cavalos.emplace_back(new Cavalo(cor, new Posicao(1, linhaPeca), tabuleiro));
        cavalos.emplace_back(new Cavalo(cor, new Posicao(6, linhaPeca), tabuleiro));
}
