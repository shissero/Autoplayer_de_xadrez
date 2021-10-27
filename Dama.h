#ifndef DAMA_H_
#define DAMA_H_

#include<string>

#include"Peca.h"

class Dama : public Peca {

	public:
		Dama(Posicao, int);
		
		std::string obterClasse();
};

#endif
