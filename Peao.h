#ifndef PEAO_H_
#define PEAO_H_

#include<array>
#include"Posicao.h"
#include"Peca.h"

class Peao : public Peca {
	public:
	
		Peao(Posicao, int);
		void mover();
};

#endif
