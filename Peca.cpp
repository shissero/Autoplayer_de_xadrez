#include"Peca.h"
#include"Posicao.h"
#include<iostream>
#include<vector>
#include<string>

Peca::Peca(Posicao pos, int color)
	: casa (pos), cor (color)
	{}

bool Peca::mover(){return false;}

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
