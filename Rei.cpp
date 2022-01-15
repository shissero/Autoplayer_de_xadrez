/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 14/01/2021

*/

#include"Conjunto.h"
#include"Peca.h"
#include"Rei.h"

Rei::Rei(Posicao posicao, int cor) : Peca(posicao, cor) {}
		
void Rei::gerarMovimentos(vector<Movimento *> *movimentos){

	this -> Peca::gerarMovimentosCardeais(movimentos, 1);
	this -> Peca::gerarMovimentosColaterais(movimentos, 1);
	
	/*for(int i = 0; i < movimentos -> size(); i++){
	
		if(Conjunto::atacadaPor( ((*movimentos)[i]) -> obterDestino, -this -> cor)) movimentos -> erase(movimentos -> begin + i);
	}*/
}
		
int Rei::mover(){

	int natureza = this -> Peca::mover();
	
	if(natureza != -1){
	
		this -> primeiroMovimento = false;
		
		Conjunto::definirStatusEnPassant(true);
	}
	
	return natureza;
}
		
string Rei::obterClasse(){

	return "Rei";
}
