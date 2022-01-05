/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 05/01/2021

*/

#include<iostream>
#include<vector>
#include<string>

#include"Aleatoria.h"
#include"Conjunto.h"
#include"Peca.h"

using namespace std;

Peca::Peca(Posicao pos, int color)
	: posicao (pos), cor (color)
	{}
	
/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

string Peca::emString(){

	string str = this -> obterClasse();
	
	return str + " " + this -> obterCorComoString()+ " " + this -> obterPosicao().emString();
}

void Peca::gerarMovimentos(vector<Movimento *> *movimentos){}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void Peca::gerarMovimentosCardeais(vector<Movimento *> *movimentos){

	Posicao *aux;

	// Gerar movimentos no sentido decrescente das linhas
	if(this -> posicao.linha > 1){
	
		for(int i = this -> posicao.linha - 1; i > 0; i--) {
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(new Movimento(*aux, NEUTRO));
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(new Movimento(*aux, CAPTURA));
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das linhas
	if(this -> posicao.linha < 8 ){
	
		for(int i = this -> posicao.linha + 1; i < 9; i++){
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(new Movimento(*aux, NEUTRO));
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(new Movimento(*aux, CAPTURA));
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido decrescente das colunas
	if(this -> posicao.coluna > 1){
	
		for(int i = this -> posicao.coluna - 1; i > 0; i--){

			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(new Movimento(*aux, NEUTRO));
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(new Movimento(*aux, CAPTURA));
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das colunas
	if(this -> posicao.coluna < 8){
	
		for(int i = this -> posicao.coluna + 1; i < 9; i++){
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)) movimentos -> push_back(new Movimento(*aux, NEUTRO));
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)) movimentos -> push_back(new Movimento(*aux, CAPTURA));
				
				break;
			}
			
		}
		
	}
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

int Peca::mover(){
	
	vector<Movimento *> movimentos;
	
	this -> gerarMovimentos( &movimentos );
	
	for(Movimento *mov : movimentos) cout << mov -> emString() << "\n" << endl;
	
	if(!movimentos.size()) return -1;
	else{
	
		Posicao origem = this -> posicao;
		
		Movimento mov = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		this -> mudarPosicao(mov.obterDestino());
		
		if(mov.obterNatureza() == CAPTURA) Conjunto::destruir(this -> posicao, -(this -> cor));
		
		cout << this -> emString() << " vai de " << origem.emString() << " para " << mov.obterDestino().emString() << endl;
		
		return mov.obterNatureza();
	}
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void Peca::mostrarMovimentos(){

	vector<Movimento *> movimentos;
	
	this -> gerarMovimentos(&movimentos);
	
	for(Movimento *mov : movimentos) cout << mov -> obterDestino().emString() << " " << mov -> obterNaturezaComoString() << endl;
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
