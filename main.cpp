/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/


#include "AdministradorDeJogo.h"
#include "Aplicacao.h"

int main(){

	Aplicacao::iniciar();

	auto admi = AdministradorDeJogo();

	admi.instanciarTabuleiro();

	auto pos = Posicao(4, 1);
	auto pos1 = Posicao(4, 3);

	auto pos2 = Posicao(0, 6);
	auto pos3 = Posicao(0, 5);

	auto pos4 = Posicao(0, 6);
	auto pos5 = Posicao(1, 4);

	auto pos6 = Posicao(3, 6);
	auto pos7 = Posicao(3, 5);

	admi.selecionarCasa(&pos);
	admi.selecionarCasa(&pos1);

	admi.selecionarCasa(&pos2);
	admi.selecionarCasa(&pos3);

	admi.selecionarCasa(&pos4);
	admi.selecionarCasa(&pos5);

	admi.selecionarCasa(&pos6);
	admi.selecionarCasa(&pos7);

	Aplicacao::finalizar();

	return 0;
}
