#ifndef PECA_H_
#define PECA_H_
#include<vector>
#include"Posicao.h"

#define BRANCO 0
#define PRETO 1

class Peca {

	public:
		Peca(Posicao, int);

		virtual bool mover();
		
		Posicao obterPosicao();
		
	protected:
	
		int cor;
		Posicao casa;
		virtual void gerarMovimentos(vector<Posicao *>);
		void mudarPosicao(Posicao);
};

#endif
