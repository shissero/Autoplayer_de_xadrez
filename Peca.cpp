#include<array>

class Peca {

	public:
		Peca(array posicao, int cor){
			this.cor = cor;
			this.posicao = posicao;
		}

		virtual void movimento();
		
	private:
	
	int cor;
	array posicao;
};
