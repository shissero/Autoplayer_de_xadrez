#ifndef POSICAO_H_
#define POSICAO_H_


#include<array>

using namespace std;

class Posicao {

	public:

		Posicao(int, int);

		int casa[2];
	
		string toString();
};

#endif
