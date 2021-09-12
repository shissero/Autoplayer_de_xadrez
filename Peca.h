#ifndef PECA_H_
#define PECA_H_
#include<array>
#include"Posicao.h"

class Peca {

	public:
		Peca(Posicao, int);

		virtual bool mover(Peca);
		
		static int PRETO;
		static int BRANCO;
		
		Posicao getPosicao();
		
	private:
	
	int cor;
	Posicao posicao;
};

#endif
