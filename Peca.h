#include<array>

class Peca {

	public:

		const int BRANCA = 0, PRETA = 1;
	
	
		Peca(array posicao, cor);

		virtual void movimento();
		
	private:
	
	int cor;
	array posicao;
};
