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
    	
    	static bool estaVazia(Posicao);
    	
    	static bool pretaOcupa(Posicao);
    	
    	static bool brancaOcupa(Posicao);
    	
    	static void destruir(Posicao, int);
    	
    	void jogarBranca();
    	
    	void jogarPreta();
    	
    	static void limparEnPassant();
    	
    	static Peca *obterEnPassant();
    	
    	static void promover(Peao, Posicao);
    	
    	static bool valeEnPassant(Posicao);
    	
    	static void listarTodasAsPecas();
	
	private:
	
	static vector<Peca *> Brancas, Pretas;
	static Peca *enPassant;
    
};

#endif
