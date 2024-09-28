/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 05/01/2021

*/

#ifndef MOVIMENTO_H_
#define MOVIMENTO_H_

#include"Posicao.h"

#define NEUTRO 0
#define CAPTURA 1
#define EN_PASSANT_PASSIVA 2
#define EN_PASSANT_ATIVA 3
#define ROQUE 4


class Movimento{
		
	public:
	
		Movimento(Posicao, int);
		
		string emString();
		
		Posicao obterDestino();
		
		int obterNatureza();
		
		string obterNaturezaComoString();

	private:
	
		Posicao destino;
		int natureza;
};

#endif
