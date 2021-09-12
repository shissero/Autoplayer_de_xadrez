#include"Peca.h"
#include"Posicao.h"

Peca::Peca(Posicao pos, int color)
	: posicao(pos), cor(color)
	{}
		
int Peca::PRETO = 1;
int Peca::BRANCO = 0;

bool Peca::mover(Peca peca){}
		
Posicao Peca::getPosicao(){
	return Peca::posicao;
}
