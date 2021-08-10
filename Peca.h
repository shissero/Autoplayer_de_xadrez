#ifndef PECA_H_
#define PECA_H_
#include<array>

#define BRANCO 0
#define PRETO 1

class Peca {

	public:
		Peca(array posicao, int cor);

		virtual void movimento();
		
	private:
	
	int cor;
	array posicao;
};

#endif
