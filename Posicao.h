/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef POSICAO_H_
#define POSICAO_H_


#include<array>
#include<string>

using namespace std;

class Posicao {

	public:
		
		int coluna;
		int linha;

		Posicao(int, int);
		
		Posicao *copiar();

		bool operator==(const Posicao&);
	
		string emString();
};

#endif
