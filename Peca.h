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
		
		int obterCor();
		
		virtual void gerarMovimentos(vector<Posicao *> *);
		
		void gerarMovimentosCardeais(Peca, vector<Posicao *> *);
		
		string obterCorComoString();
		
		virtual string obterClasse();
		
		Posicao obterPosicao();

		virtual bool mover();
		
		void mudarPosicao(Posicao);
		
	protected:
	
	int cor;
	Posicao posicao;
};

#endif
