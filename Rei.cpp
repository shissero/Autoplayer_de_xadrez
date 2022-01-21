/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 21/01/2021

*/
#include<iostream>
#include <stdexcept>

#include"Aleatoria.h"
#include"Conjunto.h"
#include"Log.h"
#include"Peca.h"
#include"Rei.h"

using namespace std;

Rei::Rei(Posicao posicao, int cor) : Peca(posicao, cor) {}

void filtrarMovimentos(vector<Movimento *> *movimentos, int adversaria){

	for(int i = 0; i < movimentos -> size(); i++){
	
		Posicao pos = (*movimentos)[i] -> obterDestino();
		
		if(Conjunto::atacadaPor(pos, adversaria)){
		
			delete (*movimentos)[i];
			movimentos -> erase(movimentos -> begin() + i);
		}
	}
}
		
void Rei::gerarMovimentos(vector<Movimento *> *movimentos){

	this -> Peca::gerarMovimentosCardeais(movimentos, 1);
	this -> Peca::gerarMovimentosColaterais(movimentos, 1);
}
		
int Rei::mover(){

	Log::escrever("\t" + this -> emString() + "\n\n");
	
	vector<Movimento *> movimentos;
	
	this -> gerarMovimentos( &movimentos );
	
	filtrarMovimentos(&movimentos, -this -> cor);
	
	if(!movimentos.size()) return -1;
	else{
	
		
		
		Log::escrever("\tMovimentos possíveis:\n");
		
		for(int i = 0; i < movimentos.size(); i++) Log::escrever("\t\t" + movimentos[i] -> emString() + "\n");
		
		Log::escrever("\n");
	
		Posicao origem = this -> posicao;
		
		Movimento mov = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		Log::escrever("\t\t\t" + mov.emString() + "\n");
		
		this -> mudarPosicao(mov.obterDestino());
		
		if(mov.obterNatureza() == CAPTURA) Conjunto::destruir(this -> posicao, -(this -> cor));
		
		return mov.obterNatureza();
	}
}
		
string Rei::obterClasse(){

	return "Rei";
}
