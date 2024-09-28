/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef CAVALO_H_
#define CAVALO_H_

#include<string>

#include"Peca.h"

class Cavalo : Peca {

	public:

		Cavalo(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();

};

#endif
