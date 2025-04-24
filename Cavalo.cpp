/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#include"Cavalo.h"
#include"Conjunto.h"
#include"IPeca.h"
#include"Posicao.h"

/*******************************************************************************************************
********************************************************************************************************
*******************************************************************************************************/

void Cavalo::gerarMovimentos(std::vector<Movimento>&){
	/*
	// Movimentos na direção crescente das linhas
	if(this -> posicao.linha < 7){
	
		if(this -> posicao.coluna > 1){
		
			Posicao pos = Posicao(this -> posicao.coluna - 1, this -> posicao.linha + 2);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
		
		if(this -> posicao.coluna < 8){
		
			Posicao pos = Posicao(this -> posicao.coluna + 1, this -> posicao.linha + 2);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
	}
	
	// Movimentos na direção decrescente das linhas
	if(this -> posicao.linha > 2){
	
		if(this -> posicao.coluna > 1){
		
			Posicao pos = Posicao(this -> posicao.coluna - 1, this -> posicao.linha - 2);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
		
		if(this -> posicao.coluna < 8){
		
			Posicao pos = Posicao(this -> posicao.coluna + 1, this -> posicao.linha - 2);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
	}
	
	// Movimentos na direção crescente das colunas
	if(this -> posicao.coluna < 7){
	
		if(this -> posicao.linha > 1){
		
			Posicao pos = Posicao(this -> posicao.coluna + 2, this -> posicao.linha - 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
		
		if(this -> posicao.linha < 8){
		
			Posicao pos = Posicao(this -> posicao.coluna + 2, this -> posicao.linha + 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
	}
	
	// Movimentos na direção decrescente das colunas
	if(this -> posicao.coluna > 2){
	
		if(this -> posicao.linha > 1){
		
			Posicao pos = Posicao(this -> posicao.coluna - 2, this -> posicao.linha - 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
		
		if(this -> posicao.linha < 8){
		
			Posicao pos = Posicao(this -> posicao.coluna - 2, this -> posicao.linha + 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
	}*/
}

Cavalo::Cavalo(int cor, Posicao *posicao): IPeca(cor, posicao) {
}
