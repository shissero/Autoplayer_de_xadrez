#ifndef PECA_H_
#define PECA_H_
#include<array>

#define BRANCO 0
#define PRETO 1

class Peca {

	public:
		Peca(Posicao posicao, int cor);

		virtual bool mover(Peca peca);
		
	private:
	
	int cor;
	Posicao posicao;
};

#endif
