#include<vector>
#include<iostream>
#include"Conjunto.h"
#include"Peao.h"
#include"Peca.h"
#include"Posicao.h"
#include"Aleatoria.h"


Peao::Peao(Posicao posicao, int cor) : Peca(posicao, cor) {}
		
bool Peao::mover(){

	vector<Posicao *> movimentos;
	
	this->gerarMovimentos(movimentos);
	
	if(!movimentos.size()) return false;
	else{
		Posicao destino = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		if(destino.coluna != this->casa.coluna){
			Conjunto::destruir(destino, this->cor);
		}
		
		this->mudarPosicao(destino);
	}
	
	return true;
}

void Peao::gerarMovimentos(vector<Posicao *> &vetor){
	if(this->cor == BRANCO){
		if(this->casa.linha == 2
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 2))){

			vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha + 2));
		}
		
		if(this->casa.linha < 8
				&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))){
				
				vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha + 1));
			}
				
		if(this->casa.coluna > 1
			&& Conjunto::pretaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha + 1))){
					
			vetor.push_back(new Posicao(this->casa.coluna - 1, this->casa.linha + 1));
		}
				
		if(this->casa.coluna < 8
			&& Conjunto::pretaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha + 1))){
					
			vetor.push_back(new Posicao(this->casa.coluna + 1, this->casa.linha + 1));
		}
	}
	else{
		if(this->casa.linha == 7
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 1))
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 2))){
					
			vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha - 2));
		}
		
		if(this->casa.linha > 1
				&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha - 1))){

				vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha - 1));
		}
				
		if(this->casa.coluna > 1
			&& Conjunto::brancaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha - 1))){
					
			vetor.push_back(new Posicao(this->casa.coluna - 1, this->casa.linha - 1));
		}
				
		if(this->casa.coluna < 8
			&& Conjunto::brancaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha - 1))){
					
			vetor.push_back(new Posicao(this->casa.coluna + 1, this->casa.linha - 1));
		}
	}
}
