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
	auto pos2 = Posicao(3, 6);
	auto pos3 = Posicao(3, 4);

	admi.selecionarCasa(&pos);
	admi.selecionarCasa(&pos1);
	admi.selecionarCasa(&pos2);
	admi.selecionarCasa(&pos3);
	admi.selecionarCasa(&pos1);
	admi.selecionarCasa(&pos3);

	Aplicacao::finalizar();

	return 0;
}
