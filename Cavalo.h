/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#ifndef CAVALO_H_
#define CAVALO_H_

#include<string>

#include"Peca.h"

class Cavalo : public Peca {

	public:

		Cavalo(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();

};

#endif
