#include<iostream>
#include<vector>
#include<string>

#include"Conjunto.h"
#include"Peca.h"

using namespace std;

Peca::Peca(Posicao pos, int color)
	: posicao (pos), cor (color)
	{}

bool Peca::mover(){
	
	if( (Conjunto::obterEnPassant() != 0)
		&& (this -> obterCor() == Conjunto::obterEnPassant() -> cor) ) Conjunto::limparEnPassant();
	return false;
}

void Peca::gerarMovimentos(vector<Posicao *> *movimentos){}

void Peca::gerarMovimentosCardeais(Peca peca, vector<Posicao *> *movimentos){

	// Gerar movimentos no sentido decrescente das linhas
	if(peca.posicao.linha > 1){
	
		for(int i = peca.posicao.linha - 1; i > 0; i--) {
		
			Peca *aux = Conjunto::estaVazia( Posicao(peca.posicao.coluna, i) );
			
			if( aux != 0 && aux -> cor == peca.cor ) break;
			else movimentos -> push_back( new Posicao(peca.posicao.coluna, i) );
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das linhas
	if(peca.posicao.linha < 8 ){
	
		for(int i = peca.posicao.linha + 1; i < 9; i++){
		
			Peca *aux = Conjunto::estaVazia( Posicao(peca.posicao.coluna, i) );
			
			if( aux != 0 && aux -> cor == peca.cor ) break;
			else movimentos -> push_back( new Posicao(peca.posicao.coluna, i) );
			
		}
		
	}
	
	// Gerar movimentos no sentido decrescente das colunas
	if(peca.posicao.coluna > 1){
	
		for(int i = peca.posicao.coluna - 1; i > 0; i--){
		
			
		
			Peca *aux = Conjunto::estaVazia( Posicao(peca.posicao.coluna, i) );
			
			if( aux != 0 && aux -> cor == peca.cor ) break;
			else movimentos -> push_back( new Posicao(i, peca.posicao.linha) );
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das colunas
	if(peca.posicao.coluna < 8){
	
		for(int i = peca.posicao.coluna + 1; i < 9; i++){
		
			Peca *aux = Conjunto::estaVazia( Posicao(peca.posicao.coluna, i) );
			
			if( aux != 0 && aux -> cor == peca.cor ) break;
			else movimentos -> push_back( new Posicao(i, peca.posicao.linha) );
			
		}
		
	}
}
		
Posicao Peca::obterPosicao(){
	return this->posicao;
}

int Peca::obterCor(){
	return this->cor;
}

string Peca::obterCorComoString(){
	return this->cor == BRANCO ? "branco" : "preto";
}

void Peca::mudarPosicao(Posicao destino){

	cout << this->posicao.toString() << " para " << destino.toString() << "\n";	
	
	this->posicao = destino;
}

string Peca::obterClasse(){ return 0; }
