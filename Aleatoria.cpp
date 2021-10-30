#include<ctime>
#include<stdlib.h>

#include"Aleatoria.h"

int Aleatoria::aleatoria(int range){
	srand((unsigned)clock());
		
	return rand()%range;
}
