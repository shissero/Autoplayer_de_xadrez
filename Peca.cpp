/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#include<iostream>
#include<vector>
#include<string>

#include"Aleatoria.h"
#include"Conjunto.h"
#include"Log.h"
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
			
			if(Conjunto::estaVazia(*aux)){
			
				Movimento *mov = new Movimento(*aux, NEUTRO);
				
				movimentos -> push_back(mov);
			}
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)){
				
					Movimento *mov = new Movimento(*aux, CAPTURA);
				
					movimentos -> push_back(mov);
				}
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das linhas
	if(this -> posicao.linha < 8 ){
	
		for(int i = this -> posicao.linha + 1; i < 9; i++){
		
			aux = new Posicao(this -> posicao.coluna, i);
			
			if(Conjunto::estaVazia(*aux)){
			
				Movimento *mov = new Movimento(*aux, NEUTRO);
				
				movimentos -> push_back(mov);
			}
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)){
				
					Movimento *mov = new Movimento(*aux, CAPTURA);
				
					movimentos -> push_back(mov);
				}
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido decrescente das colunas
	if(this -> posicao.coluna > 1){
	
		for(int i = this -> posicao.coluna - 1; i > 0; i--){

			aux = new Posicao(i, this -> posicao.linha);
			
			if(Conjunto::estaVazia(*aux)){
			
				Movimento *mov = new Movimento(*aux, NEUTRO);
				
				movimentos -> push_back(mov);
			}
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)){
				
					Movimento *mov = new Movimento(*aux, CAPTURA);
				
					movimentos -> push_back(mov);
				}
				
				break;
			}
			
		}
		
	}
	
	// Gerar movimentos no sentido crescente das colunas
	if(this -> posicao.coluna < 8){
	
		for(int i = this -> posicao.coluna + 1; i < 9; i++){
		
			aux = new Posicao(i, this -> posicao.linha);
			
			if(Conjunto::estaVazia(*aux)){
			
				Movimento *mov = new Movimento(*aux, NEUTRO);
				
				movimentos -> push_back(mov);
			}
			else{
				if(Conjunto::inimigaOcupa(this -> cor, *aux)){
				
					Movimento *mov = new Movimento(*aux, CAPTURA);
					movimentos -> push_back(mov);
				}
				
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
	
	if(!movimentos.size()) return -1;
	else{
	
		Log::escrever("\t" + this -> emString() + "\n\n");
		
		Log::escrever("\tMovimentos possíveis:\n");
		
		for(int i = 0; i < movimentos.size(); i++) Log::escrever("\t\t" + movimentos[i] -> emString() + "\n");
		
		Log::escrever("\n");
	
		Posicao origem = this -> posicao;
		
		Movimento mov = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		Log::escrever("\t\t\t" + mov.emString() + "\n");
		
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
