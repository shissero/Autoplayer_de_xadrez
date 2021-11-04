#ifndef PECA_H_
#define PECA_H_

#include<array>
#include<string>
#include<vector>

#include"Posicao.h"

#define BRANCO 0
#define PRETO 1

using namespace std;

class Peca {

	public:
		Peca(Posicao, int);
		
		virtual void gerarMovimentos(vector<Posicao *> *);
		
		void gerarMovimentosCardeais(vector<Posicao *> *);

		virtual bool mover();
		
		void mudarPosicao(Posicao);
		
		virtual string obterClasse();
		
		int obterCor();
		
		string obterCorComoString();
		
		Posicao obterPosicao();
		
	protected:
	
	int cor;
	Posicao posicao;
};

#endif
