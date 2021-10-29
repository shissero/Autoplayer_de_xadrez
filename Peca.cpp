#include<iostream>
#include<vector>
#include<string>

#include"Conjunto.h"
#include"Peca.h"
#include"Posicao.h"


Peca::Peca(Posicao pos, int color)
	: casa (pos), cor (color)
	{}

bool Peca::mover(){
	
	if( (Conjunto::obterEnPassant() != 0)
		&& (this -> obterCor() == Conjunto::obterEnPassant() -> cor) ) Conjunto::limparEnPassant();
	return false;
}

void Peca::gerarMovimentos(vector<Posicao *> movimentos){}
		
Posicao Peca::obterPosicao(){
	return this->casa;
}

int Peca::obterCor(){
	return this->cor;
}

std::string Peca::obterCorComoString(){
	return this->cor == BRANCO ? "branco" : "preto";
}

void Peca::mudarPosicao(Posicao destino){

	std::cout << this->casa.toString() << " para " << destino.toString() << "\n";	
	
	this->casa = destino;
}

std::string Peca::obterClasse(){}
