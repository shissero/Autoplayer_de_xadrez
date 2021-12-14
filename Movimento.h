#ifndef MOVIMENTO_H_
#define MOVIMENTO_H_

#include"Posicao.h"

#define NEUTRO 0
#define CAPTURA 1
#define EN_PASSANT_PASSIVA 2
#define EN_PASSANT_ATIVA 3
#define ROQUE 4


class Movimento{

	private:
	
		Posicao destino;
		int natureza;
		
	public:
	
		Movimento(Posicao, int);
		
		Posicao obterDestino();
		
		int obterNatureza();
};

#endif
