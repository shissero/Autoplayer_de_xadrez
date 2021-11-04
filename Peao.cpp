#include<iostream>
#include<string>
#include<vector>

#include"Aleatoria.h"
#include"Conjunto.h"
#include"Peao.h"
#include"Peca.h"

using namespace std;


Peao::Peao(Posicao posicao, int cor) : Peca(posicao, cor) {}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

void Peao::gerarMovimentos(vector<Posicao *> *vetor){

	if(this->cor == BRANCO){
		

		if(this->posicao.linha < 8
				&& Conjunto::estaVazia(Posicao(this->posicao.coluna, this->posicao.linha + 1))){
				
				vetor -> push_back(new Posicao(this->posicao.coluna, this->posicao.linha + 1));
				
				if(this->posicao.linha == 2
					&& Conjunto::estaVazia(Posicao(this->posicao.coluna, this->posicao.linha + 2)))
				{
					vetor -> push_back(new Posicao(this->posicao.coluna, this->posicao.linha + 2));
				}
		}
		
			
		if(this->posicao.coluna > 1
			&& ( Conjunto::inimigaOcupa(this -> cor, Posicao(this->posicao.coluna - 1, this->posicao.linha + 1))
				|| Conjunto::valeEnPassant(Posicao(this->posicao.coluna - 1, this->posicao.linha + 1)) )){
					
			vetor -> push_back(new Posicao(this->posicao.coluna - 1, this->posicao.linha + 1));
		}
				
		if(this->posicao.coluna < 8
			&& ( Conjunto::inimigaOcupa(this -> cor, Posicao(this->posicao.coluna + 1, this->posicao.linha + 1))
			 	|| Conjunto::valeEnPassant(Posicao(this->posicao.coluna + 1, this->posicao.linha + 1)) )){
					
			vetor -> push_back(new Posicao(this->posicao.coluna + 1, this->posicao.linha + 1));
		}
	}
	else{
		if(this->posicao.linha > 1
				&& Conjunto::estaVazia(Posicao(this->posicao.coluna, this->posicao.linha + 1))){
				
				vetor -> push_back(new Posicao(this->posicao.coluna, this->posicao.linha + 1));
				
				if(this->posicao.linha == 7
					&& Conjunto::estaVazia(Posicao(this->posicao.coluna, this->posicao.linha + 2)))
				{
					vetor -> push_back(new Posicao(this->posicao.coluna, this->posicao.linha + 2));
				}
		}
				
		if(this->posicao.coluna > 1
			&& ( Conjunto::inimigaOcupa(this -> cor, Posicao(this->posicao.coluna - 1, this->posicao.linha - 1))
				|| Conjunto::valeEnPassant(Posicao(this->posicao.coluna - 1, this->posicao.linha - 1)) )){
					
			vetor -> push_back(new Posicao(this->posicao.coluna - 1, this->posicao.linha - 1));
		}
				
		if(this->posicao.coluna < 8
			&& ( Conjunto::inimigaOcupa(this -> cor, Posicao(this->posicao.coluna + 1, this->posicao.linha - 1))
				|| Conjunto::valeEnPassant(Posicao(this->posicao.coluna - 1, this->posicao.linha + 1)) )){
					
			vetor -> push_back(new Posicao(this->posicao.coluna + 1, this->posicao.linha - 1));
		}
	}
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

		
bool Peao::mover(){

	this -> Peca::mover();

	vector<Posicao *> movimentos;
	
	this->gerarMovimentos( &movimentos );
	
	if(!movimentos.size()) return false;
	else{
	
		Posicao origem = this -> posicao;
		Posicao destino = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		

		if(origem.coluna != destino.coluna) Conjunto::capturar(destino, this->cor);
		
		if(origem.linha == destino.linha - 2) Conjunto::definirEnPassant(this);
			
		if(destino.linha == 8 || destino.linha == 1){
			
			Conjunto::promover(*this, destino);
		}
		else{
			
			this -> mudarPosicao(destino);
		}
	}
	
	return true;
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/


string Peao::obterClasse(){
	return "Peao";
}
