#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include<vector>
#include"Peca.h"
#include"Peao.h"

using namespace std;

class Conjunto {

	public:
    		
    	Conjunto();
    	
    	static bool estaVazia(Posicao);
    	
    	static bool pretaOcupa(Posicao);
    	
    	static bool brancaOcupa(Posicao);
    	
    	static void mover1();
    	
    	static void destruir(Posicao, int);
    	
    	void jogarBranca();
    	
    	void jogarPreta();
	
	private:
	
	static vector<Peca*> Brancas, Pretas;
    
};

#endif
