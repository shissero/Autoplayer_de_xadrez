#include"Peca.h"
#include"Posicao.h"
#include<iostream>
#include<vector>

Peca::Peca(Posicao pos, int color)
	: casa (pos), cor (color)
	{}

bool Peca::mover(){return false;}

void Peca::gerarMovimentos(vector<Posicao *> movimentos){}
		
Posicao Peca::obterPosicao(){
	return Peca::casa;
}

void Peca::mudarPosicao(Posicao destino){

	std::cout << this->casa.toString() << " para " << destino.toString();	
	
	this->casa = destino;
}
