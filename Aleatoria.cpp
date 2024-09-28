/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#include<ctime>
#include<stdlib.h>

#include"Aleatoria.h"

int Aleatoria::aleatoria(int range){

	srand((unsigned)clock());
		
		return rand()%range;
	}
}
