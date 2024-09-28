/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef TORRE_H_
#define TORRE_H_

#include"Peca.h"
#include"Posicao.h"

class Torre : public Peca {

	public:

		Torre(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
	
	private:

		bool primeiroMovimento = true;
};

#endif
