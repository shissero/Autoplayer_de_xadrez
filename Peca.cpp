#include<array>

class Peca {

	public:
		Peca(Posicao posicao, int cor){
			this.cor = cor;
			this.posicao = posicao;
		}

		virtual bool mover(Peca peca);
		
	private:
	
	int cor;
	Posicao posicao;
};
