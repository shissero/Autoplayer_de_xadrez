#ifndef PEAO_H_
#define PEAO_H_

#include<array>
#include<string>

#include"Posicao.h"
#include"Peca.h"

class Peao : public Peca {
	public:
	
		Peao(Posicao, int);
		bool mover();
		
		std::string obterClasse();
	private:
	
		void gerarMovimentos(vector<Posicao *> &);
};

#endif
