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
    	
    	static void destruir(Posicao, int);
    	
    	static bool estaVazia(Posicao);
    	
    	static bool inimigaOcupa(int, Posicao);
    	
    	void jogarBranca();
    	
    	void jogarPreta();
    	
    	static void limparEnPassant();
    	
    	static void listarTodasAsPecas();
    	
    	static void promover(Peao, Posicao);
    	
    	static Peca *obterEnPassant();
    	
    	static bool valeEnPassant(Posicao);
	
	private:
	
	static vector<Peca *> Brancas, Pretas;
	static Peca *enPassant;
    
};

#endif
