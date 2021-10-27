#ifndef CAVALO_H_
#define CAVALO_H_

#include<string>

#include"Peca.h"

class Cavalo : public Peca {

	public:
		Cavalo(Posicao, int);
		
		std::string obterClasse();

};

#endif
