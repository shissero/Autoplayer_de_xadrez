/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include"IPeca.h"
#include "Mock.h"
#include"Peao.h"
#include"Rei.h"
#include "Time.h"

class Tabuleiro
{
        friend Mock;
public:
        Tabuleiro() = default;

        Tabuleiro(const Tabuleiro &);

        ~Tabuleiro();

        // Getters e setters

        Peao *obterEnPassant() const;

        bool obterStatusEnPassant() const;

        bool obterEmXeque() const;

        IPeca *obterPecaTocada() const;

        //Time *& aliadas1();

        //Time *& adversarias1();

        void definirAliadas(Time*);

        void definirAdversarias(Time*);

        void definirEnPassant(Peao *en_passant);

        void definirStatusEnPassant(bool status_en_passant);

        void definirEmXeque(bool em_xeque);

        void definirTocada(IPeca *tocada);

        void definirTocada(Posicao *);

        IPeca *obterPeca(int, int);

        Movimento *buscarMovimentoTocada(Posicao*);

        void gerarMovimentosTocada();

        static Tabuleiro *criarTabuleiroCompleto();


        int ocupadaPor(Posicao *) const;

        bool atacadaPor(Posicao, int);

        void executarMovimento(Movimento*);

        void executarMovimento(Posicao *, Movimento*);

        void passarVez();

        int calcularXeque();

        /*void capturar(Posicao, int);

        void definirEnPassant(Peao *);

        void definirStatusEnPassant(bool);

        void destruir(IPeca *);

        void destruir(Posicao, int);

        void destruirEnPassant();

        bool estaVazia(Posicao);

        bool inimigaOcupa(int, Posicao);

        void jogar(int);

        void limparEnPassant() const;

        void listarTodasAsPecas();

        IPeca *promover(Peao *);

        Peao *obterEnPassant() const;

        Rei obterRei(int);

        bool obterStatusEnPassant() const;

        bool valeEnPassant(Posicao, int);

        bool xeque(IPeca *);*/

        static constexpr int VAZIA = 0;

private:
        Peao *enPassant = nullptr;
        bool statusEnPassant = false;
        bool emXeque = false;
        IPeca *tocada = nullptr;
        std::vector<Movimento *> movimentosTocada;

        Time *aliadas = nullptr;
        Time *adversarias = nullptr;
};

#endif
