#include"Peca.h"
#include"Dama.h"
#include<iostream>
#include<string>

Dama::Dama(Posicao posicao, int cor) : Peca(posicao, cor) {}

std::string Dama::obterClasse(){
	return "Dama";
}
