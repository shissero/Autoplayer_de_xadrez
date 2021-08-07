#include"Posicao.h"

class Peca {

	public:

		const int BRANCA = 0, PRETA = 1;
	
	
		Peca(Posicao posicao, cor);

		virtual void movimento();
		
	private:
	
	int cor;
	Posicao posicao;
};
