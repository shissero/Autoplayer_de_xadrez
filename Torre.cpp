#include<vector>

#include"Peca.h"
#include"Torre.h"

Torre::Torre(Posicao posicao, int cor) : Peca(posicao, cor) {}

void Torre::gerarMovimentos(vector<Movimento *> *){}
		
int Torre::mover(){}
		
string Torre::obterClasse(){}
