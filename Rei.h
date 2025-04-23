/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef REI_H_
#define REI_H_


#include"IPeca.h"

class Rei : public IPeca {

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
