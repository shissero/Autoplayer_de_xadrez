//
// Created by cicero on 23/04/25.
//

#include "Time.h"

#include "ExcecaoPecaExcedente.h"
#include "ExcecaoPecaIntrusa.h"

Time::Time(int cor) : cor(cor), linhaPeca(3.5f - cor * (3.5f))
{
}

Time::Time(const Time &time)
{
        cor = time.cor;
        linhaPeca = time.linhaPeca;

        for(Peao *p : time.peoes) this->adicionarPeao(new Peao(*p));
        for(Torre *t : time.torres) this->adicionarTorre(new Torre(*t));
        for(Bispo *b : time.bispos) this->adicionarBispo(new Bispo(*b));
        for(Cavalo *c : time.cavalos) this->adicionarCavalo(new Cavalo(*c));
        for(Dama *d : time.damas) this->adicionarDama(new Dama(*d));
        this->adicionarRei(new Rei(*(time.rei)));
}

Time::~Time()
{
    for(IPeca *p : todasPecas) delete p;
}

Time *Time::criarTimeCompleto(int cor, Tabuleiro *tabuleiro)
{
        Time *novo = new Time(cor);

        novo->adicionarBisposPadrao(tabuleiro);
        novo->adicionarPeoesPadrao(tabuleiro);
        novo->adicionarTorresPadrao(tabuleiro);
        novo->adicionarCavalosPadrao(tabuleiro);
        novo->adicionarDama(new Dama(cor, new Posicao(3, novo->linhaPeca), tabuleiro));
        novo->adicionarRei(new Rei(cor, new Posicao(4, novo->linhaPeca), tabuleiro));

        return novo;
}

void Time::adicionarPeao(Peao *peao)
{
        if(peao->obterCor() != cor) throw ExcecaoPecaIntrusa(*peao);

        if(peoes.size() >= 2) throw ExcecaoPecaExcedente();

        peoes.emplace_back(peao);
        todasPecas.emplace_back(peao);
}

void Time::adicionarTorre(Torre *torre)
{
        torres.emplace_back(torre);
        todasPecas.emplace_back(torre);
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

void Time::adicionarRei(Rei *n_rei)
{
        rei = n_rei;
        todasPecas.emplace_back(n_rei);
}

void Time::destruir(Posicao *pos)
{
        for(size_t i = 0; i < todasPecas.size(); ++i)
        {
                if(*(todasPecas[i]->obterPosicao()) == pos)
                {
                        delete todasPecas[i];
                        todasPecas.erase(todasPecas.begin() + i);
                        return;
                }
        }
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

        for(IPeca *p : todasPecas) // TODO: quando tiver mais tempo, veja como implementar essa e outras funçoes usando any_fo
        {
                if( *(p -> obterPosicao()) == pos ) return true;
        }

        return false;
}

bool Time::atacada(const Posicao *posicao) const
{
        bool retorno = false;

        for(size_t i = 0; (i < todasPecas.size()) && (retorno == false); ++i)
        {
                std::vector<Movimento*> movimentos;

                todasPecas[i] -> gerarMovimentos(movimentos);

                for(Movimento *m : movimentos)
                {
                        if(m->obterDestino() == posicao) retorno = true;
                        delete m;
                }
        }

        return retorno;
}

const Posicao *Time::obterPosicaoRei() const
{
        return rei->obterPosicao();
}

IPeca * Time::obterPeca(const Posicao *posicao) const
{
        for(IPeca *p : todasPecas)
        {
                if( *(p->obterPosicao()) == posicao) return p;
        }

        return nullptr;
}

void Time::adicionarBisposPadrao(Tabuleiro *tabuleiro)
{
        bispos.emplace_back(new Bispo(cor, new Posicao(2, linhaPeca), tabuleiro));
        bispos.emplace_back(new Bispo(cor, new Posicao(5, linhaPeca), tabuleiro));

        todasPecas.insert(todasPecas.end(), bispos.begin(), bispos.end());
}

void Time::adicionarPeoesPadrao(Tabuleiro *tabuleiro)
{
        for(int i = 0; i < 8; i++) peoes.emplace_back(new Peao(cor, new Posicao(i, linhaPeca + cor), tabuleiro));

        todasPecas.insert(todasPecas.end(), peoes.begin(), peoes.end());
}

void Time::adicionarTorresPadrao(Tabuleiro *tabuleiro)
{
        torres.emplace_back(new Torre(cor, new Posicao(0, linhaPeca), tabuleiro));
        torres.emplace_back(new Torre(cor, new Posicao(7, linhaPeca), tabuleiro));

        todasPecas.insert(todasPecas.end(), torres.begin(), torres.end());
}

void Time::adicionarCavalosPadrao(Tabuleiro *tabuleiro)
{
        cavalos.emplace_back(new Cavalo(cor, new Posicao(1, linhaPeca), tabuleiro));
        cavalos.emplace_back(new Cavalo(cor, new Posicao(6, linhaPeca), tabuleiro));

        todasPecas.insert(todasPecas.end(), cavalos.begin(), cavalos.end());
}
