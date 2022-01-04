/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#include<ctime>
#include<stdlib.h>

#include"Aleatoria.h"

int Aleatoria::aleatoria(int range){

	srand((unsigned)clock());
		
	return rand()%range;
}
