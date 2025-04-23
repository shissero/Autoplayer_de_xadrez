/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/


#include "Posicao.h"
#include "PosicaoInvalida.h"

#include <iostream>

int main(){

	Posicao posicao = Posicao(1, 2);

	Posicao posicao2 = Posicao(0, 0);

	try{

		Posicao posicao3 = posicao + posicao2;

	}
	catch (PosicaoInvalida &e) {

		std::cerr << e.what() << std::endl;
	}

	return 0;
}
