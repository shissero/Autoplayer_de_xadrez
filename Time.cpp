//
// Created by cicero on 23/04/25.
//

#include "Time.h"

#include "ExcecaoPecaExcedente.h"
#include "ExcecaoPecaIntrusa.h"

Time::Time(int cor) : cor(cor), linhaPeca(3.5f - cor * (3.5f))
{
}

Time *Time::criarTimeCompleto(int cor, Conjunto *conjunto)
{
        Time *novo = new Time(cor);

        novo->adicionarBisposPadrao(conjunto);
        novo->adicionarPeoesPadrao(conjunto);
        novo->adicionarTorresPadrao(conjunto);
        novo->adicionarCavalosPadrao(conjunto);
        novo->damas.emplace_back(new Dama(cor, new Posicao(3, novo->linhaPeca), conjunto));
        novo->rei = new Rei(cor, new Posicao(4, novo->linhaPeca), conjunto);

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

void Time::definirConjunto(Conjunto *conjunto)
{
        for(IPeca *p : todasPecas) p->definirConjunto(conjunto);
}

bool Time::ocupada(Posicao *pos) const
{

        for(IPeca *p : todasPecas)
        {
                if( *(p -> obterPosicao()) == pos ) return true;
        }

        return false;
}

void Time::adicionarBisposPadrao(Conjunto *conjunto)
{
        bispos.emplace_back(new Bispo(cor, new Posicao(2, linhaPeca), conjunto));
        bispos.emplace_back(new Bispo(cor, new Posicao(5, linhaPeca), conjunto));
}

void Time::adicionarPeoesPadrao(Conjunto *conjunto)
{
        for(int i = 0; i < 8; i++) peoes.emplace_back(new Peao(cor, new Posicao(i, linhaPeca + cor), conjunto));
}

void Time::adicionarTorresPadrao(Conjunto *conjunto)
{
        torres.emplace_back(new Torre(cor, new Posicao(0, linhaPeca), conjunto));
        torres.emplace_back(new Torre(cor, new Posicao(7, linhaPeca), conjunto));
}

void Time::adicionarCavalosPadrao(Conjunto *conjunto)
{
        cavalos.emplace_back(new Cavalo(cor, new Posicao(1, linhaPeca), conjunto));
        cavalos.emplace_back(new Cavalo(cor, new Posicao(6, linhaPeca), conjunto));
}
