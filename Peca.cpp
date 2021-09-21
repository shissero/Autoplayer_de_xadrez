#include"Peca.h"
#include"Posicao.h"
#include<iostream>

Peca::Peca(Posicao pos, int color)
	: casa (pos), cor (color)
	{}

void Peca::mover(){ std::cout << "Works"; }
		
Posicao Peca::obterPosicao(){
	return Peca::casa;
}
