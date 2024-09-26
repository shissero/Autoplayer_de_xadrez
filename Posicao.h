#ifndef POSICAO_H_
#define POSICAO_H_


#include<array>

using namespace std;

class Posicao {

	public:
		
		int coluna;
		int linha;

		Posicao(int, int);

		bool operator==(const Posicao&);
	
		string toString();
};

#endif
