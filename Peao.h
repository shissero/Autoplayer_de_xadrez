/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#ifndef PEAO_H_
#define PEAO_H_

#include<array>
#include<string>

#include"Movimento.h"
#include"Peca.h"

using namespace std;

class Peao : public Peca {

	public:
	
		Peao(Posicao, int);
		
		void gerarMovimentos(vector<Movimento *> *);
		
		int mover();
		
		string obterClasse();
		
	private:
	
		bool primeiroMovimento = true;	

};

#endif
