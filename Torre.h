#ifndef TORRE_H_
#define TORRE_H_

#include<string>

#include"Peca.h"

class Torre : public Peca {

	public:
		Torre(Posicao, int);
		
		std::string obterClasse();

};

#endif
