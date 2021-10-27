#include<iostream>
#include<string>

#include"Peca.h"
#include"Cavalo.h"


Cavalo::Cavalo(Posicao posicao, int cor) : Peca(posicao, cor){}

std::string Cavalo::obterClasse(){
	return "Cavalo";
}
