#include<array>

class Peca {

	public:

		const int BRANCA = 0, PRETA = 1;
	
	
		Peca(array posicao, cor){
			this.cor = cor;
			this.posicao = posicao;
		}

		virtual void movimento();
		
	private:
	
	int cor;
	array posicao;
};
