/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 25/01/2021

*/

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include"IPeca.h"
#include"Peao.h"
#include"Rei.h"
#include "Time.h"

#include<vector>

using namespace std;

class Conjunto
{
public:
        Conjunto() = default;

        static Conjunto *criarConjuntoCompleto();

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

private:
        Peao *enPassant = nullptr;
        bool statusEnPassant = false;
        bool emXeque = false;

        Time *aliadas = nullptr;
        Time *adversarias = nullptr;
};

#endif
