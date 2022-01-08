/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#include"Peca.h"

class Bispo : public Peca{

	public:
	
		Bispo(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
};
