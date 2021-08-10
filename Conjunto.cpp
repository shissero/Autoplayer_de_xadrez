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
    
    Conjunto(int COR):
    	if(COR == BRANCO){
    		// Inicialize as peças brancas
    		
    		
    		for(int i = 1; i < 9; i++){
    			Conjunto.insert(Peao(i, 2, COR);
    		}
    		
    		Conjunto.insert(Torre(1, 1, COR));
    		Conjunto.insert(Torre(8, 1, COR));
    		
		Conjunto.insert(Cavalo(2, 1, COR));
		Conjunto.insert(Cavalo(7, 1 COR));
		
		Conjunto.insert(Bispo(3, 1, COR));
		Conjunto.insert(Bispo(6, 1, COR));
		
		Conjunto.insert(Dama(4, 1, COR));
		
		Conjunto.insert(Rei(5, 1, COR));
    	}
    	else{
    		// Inicialize as peças pretas
    		
    		
    		for(int i = 1; i < 9; i++){
    			Conjunto.insert(Peao(i, 7, COR));
    		}
    		
    		Conjunto.insert(Torre(1, 8, COR));
    		Conjunto.insert(Torre(8, 8, COR));
    		
		Conjunto.insert(Cavalo(2, 8, COR));
		Conjunto.insert(Cavalo(7, 8, COR));
		
		Conjunto.insert(Bispo(3, 8, COR));
		Conjunto.insert(Bispo(6, 8, COR));
		
		Conjunto.insert(Dama(4, 8, COR));
		
		Conjunto.insert(Rei(5, 8, COR));
    	}
};
