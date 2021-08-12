#include<vector>
#include"Peca"
#include"Peao.h"
#include"Torre.h"
#include"Cavalo.h"
#include"Bispo.h"
#include"Dama.h"
#include"Rei.h"
#include"Aleatoria.h"

using std::vector

class Conjunto {
    vector<Peca> conjunto;
    
    Conjunto(int COR):
    	if(COR == BRANCO){
    		// Inicialize as peças brancas
    		
    		
    		for(int i = 1; i < 9; i++){
    			conjunto.insert(Peao(i, 2, COR);
    		}
    		
    		conjunto.insert(Torre(1, 1, COR));
    		conjunto.insert(Torre(8, 1, COR));
    		
		conjunto.insert(Cavalo(2, 1, COR));
		conjunto.insert(Cavalo(7, 1 COR));
		
		conjunto.insert(Bispo(3, 1, COR));
		conjunto.insert(Bispo(6, 1, COR));
		
		conjunto.insert(Dama(4, 1, COR));
		
		conjunto.insert(Rei(5, 1, COR));
    	}
    	else{
    		// Inicialize as peças pretas
    		
    		
    		for(int i = 1; i < 9; i++){
    			conjunto.insert(Peao(i, 7, COR));
    		}
    		
    		conjunto.insert(Torre(1, 8, COR));
    		conjunto.insert(Torre(8, 8, COR));
    		
		conjunto.insert(Cavalo(2, 8, COR));
		conjunto.insert(Cavalo(7, 8, COR));
		
		conjunto.insert(Bispo(3, 8, COR));
		conjunto.insert(Bispo(6, 8, COR));
		
		conjunto.insert(Dama(4, 8, COR));
		
		conjunto.insert(Rei(5, 8, COR));
    	}
    	
    	void jogar(){
    	
    		Peca movendo;
    		
    		while(conjunto[Aleatoria.aleatoria(conjunto.length)].mover(movendo)){}
    	}
};
