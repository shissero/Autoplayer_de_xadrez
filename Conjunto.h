/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 25/01/2021

*/

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include<vector>

#include"Peca.h"
#include"Peao.h"
#include"Rei.h"

using namespace std;

class Conjunto {

	public:
	
	static vector<Peca *> Brancas, Pretas;
    		
    		Conjunto();
    		
    		static bool atacadaPor(Posicao, int);
    	
    		static void capturar(Posicao, int);
    	
    		static void definirEnPassant(Peao *);
    	
    		static void definirStatusEnPassant(bool);
    	
    		static void destruir(Peca *);
    		
    		static void destruir(Posicao, int);
    	
    		static void destruirEnPassant();
    	
    		static bool estaVazia(Posicao);
    	
    		static bool inimigaOcupa(int, Posicao);
    	
    		void jogar(int);
    	
    		static void limparEnPassant();
    	
    		static void listarTodasAsPecas();
    	
    		static Peca *promover(Peao *);
    	
    		static Peca *obterEnPassant();
    		
    		static Rei obterRei(int);
    	
    		static bool obterStatusEnPassant();
    	
    		static bool valeEnPassant(Posicao, int);
    		
    		static bool xeque(Peca *);
	
	private:
	
		
		static Peca *enPassant;
		static bool statusEnPassant;
		static bool emXeque;
    
};

#endif
