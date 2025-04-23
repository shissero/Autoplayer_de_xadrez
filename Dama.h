/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/
#ifndef DAMA_H_
#define DAMA_H_


#include"IPeca.h"

class Dama : public IPeca {

	public:

		Dama(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
};

#endif
