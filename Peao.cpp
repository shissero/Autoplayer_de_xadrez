#include<vector>
#include<Conjunto.h>
#include"Peao.h"
#include"Peca.h"
#include"Posicao.h"


Peao::Peao(Posicao posicao, int cor) : Peca(posicao, cor) {}
		
void Peao::mover(){
	vector<Posicao> movimentos;
			
	if(Peca::cor == BRANCO){
		if(this->casa.linha == 2
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 2))){
					
			movimentos.push_back(Posicao(this->casa.coluna, this->casa.linha + 2));
		}
		
		if(this->casa.linha < 8
				&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))){

				movimentos.push_back(Posicao(this->casa.coluna, this->casa.linha + 1));
			}
				
		if(this->casa.coluna > 1
			&& Conjunto::pretaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha + 1))){
					
			movimentos.push_back(Posicao(this->casa.coluna - 1, this->casa.linha + 1));
		}
				
		if(this->casa.coluna < 8
			&& Conjunto::pretaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha + 1))){
					
			movimentos.push_back(Posicao(this->casa.coluna + 1, this->casa.linha + 1));
		}
	}
	else{
		if(this->casa.linha == 7
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 1))
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 2))){
					
			movimentos.push_back(Posicao(this->casa.coluna, this->casa.linha - 2));
		}
		
		if(this->casa.linha > 1
				&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 1))){

				movimentos.push_back(Posicao(this->casa.coluna, this->casa.linha - 1));
		}
				
		if(this->casa.coluna > 1
			&& Conjunto::brancaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha - 1))){
					
			movimentos.push_back(Posicao(this->casa.coluna - 1, this->casa.linha - 1));
		}
				
		if(this->casa.coluna < 8
			&& Conjunto::brancaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha - 1))){
					
			movimentos.push_back(Posicao(this->casa.coluna + 1, this->casa.linha - 1));
		}
	}
}
