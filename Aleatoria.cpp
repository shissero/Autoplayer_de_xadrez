#include<stdlib.h>
#include<ctime>

class Aleatoria {
	static int aleatoria(int range){
		srand((unsigned)clock());
		
		return rand()%range;
	}
}
