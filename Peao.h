#ifndef PEAO_H_
#define PEAO_H_

#include<array>
#include<string>

#include"Peca.h"

using namespace std;

class Peao : public Peca {
	public:
	
		Peao(Posicao, int);
		
		
		void gerarMovimentos(vector<Posicao *> *);
		
		bool mover();
		
		string obterClasse();
		

};

#endif
