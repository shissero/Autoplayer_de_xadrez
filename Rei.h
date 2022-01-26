/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 25/01/2021

*/

#ifndef REI_H_
#define REI_H_


#include"Peca.h"

class Rei : public Peca {

	public:

		Rei(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
	
	private:

		bool primeiroMovimento = true;
		
		
		void adicionarRoques();
};

#endif
