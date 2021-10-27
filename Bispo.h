#ifndef BISPO_H_
#define BISPO_H_

#include<string>

#include"Peca.h"

class Bispo : public Peca {

	public:
		Bispo(Posicao, int);
		
		std::string obterClasse();
};

#endif
