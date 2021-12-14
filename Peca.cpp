#include<iostream>
#include<vector>
#include<string>

#include"Conjunto.h"
#include"Peca.h"

using namespace std;

Peca::Peca(Posicao pos, int color)
	: posicao (pos), cor (color)
	{}
	
/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void Peca::gerarMovimentos(vector<Movimento *> *movimentos){}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void Peca::gerarMovimentosCardeais(vector<Posicao *> *movimentos){

	Posicao *aux;

	// Gerar movimentos no sentido decrescente das linhas
	if(this -> posicao.linha > 1){
	
		for(int i = this -> posicao.linha - 1; i > 0; i--) {
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(aux);
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(aux);
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das linhas
	if(this -> posicao.linha < 8 ){
	
		for(int i = this -> posicao.linha + 1; i < 9; i++){
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(aux);
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(aux);
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido decrescente das colunas
	if(this -> posicao.coluna > 1){
	
		for(int i = this -> posicao.coluna - 1; i > 0; i--){
		
			
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(aux);
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(aux);
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das colunas
	if(this -> posicao.coluna < 8){
	
		for(int i = this -> posicao.coluna + 1; i < 9; i++){
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(aux);
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(aux);
				
				break;
			}
			
		}
		
	}
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

bool Peca::mover(){
	
	if( (Conjunto::obterEnPassant() != 0)
		&& (this -> obterCor() == Conjunto::obterEnPassant() -> cor) ) Conjunto::limparEnPassant();
	return false;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void Peca::mudarPosicao(Posicao destino){
	
	this->posicao = destino;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

string Peca::obterClasse(){ return ""; }

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

int Peca::obterCor(){
	return this->cor;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

string Peca::obterCorComoString(){
	return this->cor == BRANCO ? "branco" : "preto";
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/
		
Posicao Peca::obterPosicao(){
	return this->posicao;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/
