#include<array>

class Peca {

	public:
		Peca(array posicao, int cor){
			this.cor = cor;
			this.posicao = posicao;
		}

		virtual bool mover(Peca peca);
		
	private:
	
	int cor;
	array posicao;
};
