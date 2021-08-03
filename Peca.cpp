#include"Posicao.h"

class Peca {
	int cor;
	Posicao posicao_atual;
	Posicao posicao_destino;

	virtual void movimento();
};
