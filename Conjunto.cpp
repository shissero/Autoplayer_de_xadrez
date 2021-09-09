#include<vector>
#include"Peca.h"
#include"Peao.h"

/*
#include"Torre.h"
#include"Cavalo.h"
#include"Bispo.h"
#include"Dama.h"
#include"Rei.h"
#include"Aleatoria.h"*/

using std::vector

class Conjunto {

	public:
	
		const int FIMDEJOGO = 789;
		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

		static void build(){
			if(Brancas == NULL){

				for(int i = 1; i < 9; i++){
					Brancas.insert(Peao(i, 2, Peca.BRANCO);
				}
    		
				/*Brancas.insert(Torre(1, 1, Peca.BRANCO));
				Brancas.insert(Torre(8, 1, Peca.BRANCO));
    		
				Brancas.insert(Cavalo(2, 1, Peca.BRANCO));
				Brancas.insert(Cavalo(7, 1 Peca.BRANCO));
		
				Brancas.insert(Bispo(3, 1, Peca.BRANCO));
				Brancas.insert(Bispo(6, 1, Peca.BRANCO));
		
				Brancas.insert(Dama(4, 1, Peca.BRANCO));
		
				Brancas.insert(Rei(5, 1, Peca.BRANCO));*/
			}
			
			if(Pretas == NULL){
			
				for(int i = 1; i < 9; i++){
					Pretas.insert(Peao(i, 7, Peca.PRETO));
				}
    		
				/*Pretas.insert(Torre(1, 8, Peca.PRETO));
				Pretas.insert(Torre(8, 8, Peca.PRETO));
    		
				Pretas.insert(Cavalo(2, 8, Peca.PRETO));
				Pretas.insert(Cavalo(7, 8, Peca.PRETO));
		
				Pretas.insert(Bispo(3, 8, Peca.PRETO));
				Pretas.insert(Bispo(6, 8, Peca.PRETO));
		
				Pretas.insert(Dama(4, 8, Peca.PRETO));
		
				Pretas.insert(Rei(5, 8, Peca.PRETO));*/
			}
		}
		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/
		
		void destruaBranca(int casa){
			for(int i = 0
		}
		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

    
		void jogar(){
    	
    			Peca movendo;
    		
    			while(this[Aleatoria.aleatoria(conjunto.length)].mover(movendo)){}
    		}
    		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

    		
    		
    	private:
    	
    		vector<Peca> Brancas, Pretas;
    		
    		Conjunto(){}
    	
    	
};
