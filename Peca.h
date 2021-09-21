#ifndef PECA_H_
#define PECA_H_
#include<array>
#include"Posicao.h"

#define BRANCO 0
#define PRETO 1

class Peca {

	public:
		Peca(Posicao, int);

		virtual void mover();
		
		Posicao obterPosicao();
		
	protected:
	
	int cor;
	Posicao casa;
};

#endif
