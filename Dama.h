/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

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
