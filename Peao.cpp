#include<vector>
#include<iostream>
#include<string>

#include"Conjunto.h"
#include"Peao.h"
#include"Peca.h"
#include"Posicao.h"
#include"Aleatoria.h"


Peao::Peao(Posicao posicao, int cor) : Peca(posicao, cor) {}
		
bool Peao::mover(){

	this -> Peca::mover();

	vector<Posicao *> movimentos;
	
	this->gerarMovimentos(movimentos);
	
	if(!movimentos.size()) return false;
	else{
	
		Posicao origem = this -> casa;
		Posicao destino = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		

		if(origem.coluna != destino.coluna) Conjunto::capturar(destino, this->cor);
		
		if(origem.linha == destino.linha - 2) Conjunto::definirEnPassant(this);
			
		if(destino.linha == 8 || destino.linha == 1){
			
			Conjunto::promover(*this, destino);
		}
		else{
			
			this->mudarPosicao(destino);
		}
	}
	
	return true;
}

void Peao::gerarMovimentos(vector<Posicao *> &vetor){

	if(this->cor == BRANCO){
	
		// Testa se o peão branco pode avançar duas casas
		if(this->casa.linha == 2
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))
			&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 2))){

			vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha + 2));
		}
		
		// Testa se o peão branco pode avançar uma casa
		if(this->casa.linha < 8
				&& Conjunto::estaVazia(Posicao(this->casa.coluna, this->casa.linha + 1))){
				
				vetor.push_back(new Posicao(this->casa.coluna, this->casa.linha + 1));
		}
		
			
		if(this->casa.coluna > 1
			&& ( Conjunto::pretaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha + 1))
				|| Conjunto::valeEnPassant(Posicao(this->casa.coluna - 1, this->casa.linha + 1)) )){
					
			vetor.push_back(new Posicao(this->casa.coluna - 1, this->casa.linha + 1));
		}
				
		if(this->casa.coluna < 8
			&& ( Conjunto::pretaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha + 1))
			 	|| Conjunto::valeEnPassant(Posicao(this->casa.coluna + 1, this->casa.linha + 1)) )){
					
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
			&& ( Conjunto::brancaOcupa(Posicao(this->casa.coluna - 1, this->casa.linha - 1))
				|| Conjunto::valeEnPassant(Posicao(this->casa.coluna - 1, this->casa.linha - 1)) )){
					
			vetor.push_back(new Posicao(this->casa.coluna - 1, this->casa.linha - 1));
		}
				
		if(this->casa.coluna < 8
			&& ( Conjunto::brancaOcupa(Posicao(this->casa.coluna + 1, this->casa.linha - 1))
				|| Conjunto::valeEnPassant(Posicao(this->casa.coluna - 1, this->casa.linha + 1)) )){
					
			vetor.push_back(new Posicao(this->casa.coluna + 1, this->casa.linha - 1));
		}
	}
}

std::string Peao::obterClasse(){
	return "Peao";
}
