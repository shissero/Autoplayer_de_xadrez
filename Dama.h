/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/
#ifndef DAMA_H_
#define DAMA_H_


#include"Peca.h"

class Dama : public Peca {

	public:

		Dama(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
};

#endif
