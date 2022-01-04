/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include<vector>

#include"Peca.h"
#include"Peao.h"

using namespace std;

class Conjunto {

	public:
    		
    		Conjunto();
    	
    		static void capturar(Posicao, int);
    	
    		static void definirEnPassant(Peao *);
    	
    		static void definirStatusEnPassant(bool);
    	
    		static void destruir(Posicao, int);
    	
    		static void destruirEnPassant();
    	
    		static bool estaVazia(Posicao);
    	
    		static bool inimigaOcupa(int, Posicao);
    	
    		void jogar(int);
    	
    		static void limparEnPassant();
    	
    		static void listarTodasAsPecas();
    	
    		static void promover(Peao, Posicao);
    	
    		static Peca *obterEnPassant();
    	
    		static bool obterStatusEnPassant();
    	
    		static bool valeEnPassant(Posicao, int);
	
	private:
	
		static vector<Peca *> Brancas, Pretas;
		static Peca *enPassant;
		static bool statusEnPassant;
    
};

#endif
