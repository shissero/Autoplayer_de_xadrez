#include<vector>
#include"Peca"
#include"Peao.h"
#include"Torre.h"
#include"Cavalo.h"
#include"Bispo.h"
#include"Dama.h"
#include"Rei.h"

using std::vector

class Conjunto {
    vector<Peca> Conjunto;
    
    Conjunto(const int COR):
    	if(COR == Peca.BRANCO){
    		// Inicialize as peças brancas
    		
    		
    		for(int i = 1; i < 9; i++){
    			Conjunto.insert(Peao(Posicao(i, 2), COR);
    		}
    		
    		Conjunto.insert(Torre(Posicao(1, 1), COR);
    		Conjunto.insert(Torre(Posicao(8, 1), COR);
    		
		Conjunto.insert(Cavalo(Posicao(2, 1), COR);
		Conjunto.insert(Cavalo(Posicao(7, 1), COR);
		
		Conjunto.insert(Bispo(Posicao(3, 1), COR);
		Conjunto.insert(Bispo(Posicao(6, 1), COR);
		
		Conjunto.insert(Dama(Posicao(4, 1), COR);
		
		Conjunto.insert(Rei(Posicao(5, 1), COR);
    	}
    	else{
    		// Inicialize as peças pretas
    		
    		
    		for(int i = 1; i < 9; i++){
    			Conjunto.insert(Peao(Posicao(i, 7), COR);
    		}
    		
    		Conjunto.insert(Torre(Posicao(1, 8), COR);
    		Conjunto.insert(Torre(Posicao(8, 8), COR);
    		
		Conjunto.insert(Cavalo(Posicao(2, 8), COR);
		Conjunto.insert(Cavalo(Posicao(7, 8), COR);
		
		Conjunto.insert(Bispo(Posicao(3, 8), COR);
		Conjunto.insert(Bispo(Posicao(6, 8), COR);
		
		Conjunto.insert(Dama(Posicao(4, 8), COR);
		
		Conjunto.insert(Rei(Posicao(5, 8), COR);
    	}
};
