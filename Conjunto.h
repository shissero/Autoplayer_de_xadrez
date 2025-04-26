/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include"IPeca.h"
#include "Mock.h"
#include"Peao.h"
#include"Rei.h"
#include "Time.h"

class Conjunto
{
        friend Mock;
public:
        Conjunto() = default;

        static Conjunto *criarConjuntoCompleto();

        void definirAliadas(Time*);

        void definirAdversarias(Time*);

        int ocupadaPor(Posicao *) const;

        bool atacadaPor(Posicao, int);

        void capturar(Posicao, int);

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

        bool xeque(IPeca *);

        static constexpr int VAZIA = 0;

private:
        Peao *enPassant = nullptr;
        bool statusEnPassant = false;
        bool emXeque = false;

        Time *aliadas = nullptr;
        Time *adversarias = nullptr;
};

#endif
