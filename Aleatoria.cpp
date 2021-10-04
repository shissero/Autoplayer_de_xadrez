#include<stdlib.h>
#include<ctime>
#include"Aleatoria.h"

int Aleatoria::aleatoria(int range){
	srand((unsigned)clock());
		
	return rand()%range;
}
