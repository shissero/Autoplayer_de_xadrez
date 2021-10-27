#include"Peca.h"
#include"Bispo.h"
#include<iostream>
#include<string>

Bispo::Bispo(Posicao posicao, int cor) : Peca(posicao, cor) {}

std::string Bispo::obterClasse(){
	return "Bispo";
}
