/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#include"Rei.h"

#include"Tabuleiro.h"
#include"IPeca.h"

/*
void filtrarMovimentos(vector<Movimento *> *movimentos, int adversaria){

	for(int i = 0; i < movimentos -> size(); i++){
	
		Posicao pos = (*movimentos)[i] -> obterDestino();
		
		if(Tabuleiro::atacadaPor(pos, adversaria)){
		
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
		
void Rei::gerarMovimentos(std::vector<Movimento *> &movimentos){

	this -> IPeca::gerarMovimentosCardeais(movimentos, true, false);
	this -> IPeca::gerarMovimentosColaterais(movimentos, true, false);
}

void Rei::gerarCasasAtacadas(std::vector<Movimento *> &movimentos)
{ // TODO: esses movimentos também precisam ser filtrados, porque o rei não pode fazer um movimento de ataque que o coloque em xeque.
	// No entanto, esse mecanismo pode ser mais complexo de resolver
	this -> IPeca::gerarMovimentosCardeais(movimentos, true, true);
	this -> IPeca::gerarMovimentosColaterais(movimentos, true, true);
}

Rei::Rei(int cor, Posicao *posicao): IPeca(cor, posicao) {
}

Rei::Rei(int cor, Posicao *posicao, Tabuleiro *tabuleiro
): IPeca(cor, posicao, tabuleiro) {
}
