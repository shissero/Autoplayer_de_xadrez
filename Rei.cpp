/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Rei.h"

#include"Conjunto.h"
#include"IPeca.h"

/*
void filtrarMovimentos(vector<Movimento *> *movimentos, int adversaria){

	for(int i = 0; i < movimentos -> size(); i++){
	
		Posicao pos = (*movimentos)[i] -> obterDestino();
		
		if(Conjunto::atacadaPor(pos, adversaria)){
		
			delete (*movimentos)[i];
			movimentos -> erase(movimentos -> begin() + i);
		}
	}
}

/************************************************************************************************************
/************************************************************************************************************
/***********************************************************************************************************/
/*
void Rei::adicionarRoques(){

	
}
*/
/************************************************************************************************************
/************************************************************************************************************
/***********************************************************************************************************/
		
void Rei::gerarMovimentos(std::vector<Movimento *> &){

	//this -> IPeca::gerarMovimentosCardeais(movimentos, 1);
	//this -> IPeca::gerarMovimentosColaterais(movimentos, 1);
}

Rei::Rei(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Rei::Rei(int cor, Posicao *posicao, Conjunto *conjunto): IPeca(cor, posicao, conjunto) {
}
