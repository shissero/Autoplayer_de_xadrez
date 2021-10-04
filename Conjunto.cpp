#include<vector>
#include<iostream>
#include"Aleatoria.h"
#include"Peca.h"
#include"Peao.h"
#include"Posicao.h"
#include"Conjunto.h"

/*
#include"Torre.h"
#include"Cavalo.h"
#include"Bispo.h"
#include"Dama.h"
#include"Rei.h"
#include"Aleatoria.h"*/

using namespace std;

vector<Peca*> Conjunto::Brancas, Conjunto::Pretas;
	
Conjunto::Conjunto(){

	for(int i = 1; i < 9; i++){
		Conjunto::Brancas.push_back(new Peao(Posicao(i, 2), BRANCO));
	}
    		
				/*Brancas.insert(Torre(1, 1, Peca.BRANCO));
				Brancas.insert(Torre(8, 1, Peca.BRANCO));
    		
				Brancas.insert(Cavalo(2, 1, Peca.BRANCO));
				Brancas.insert(Cavalo(7, 1 Peca.BRANCO));
		
				Brancas.insert(Bispo(3, 1, Peca.BRANCO));
				Brancas.insert(Bispo(6, 1, Peca.BRANCO));
		
				Brancas.insert(Dama(4, 1, Peca.BRANCO));
		
				Brancas.insert(Rei(5, 1, Peca.BRANCO));*/
			
	for(int i = 1; i < 9; i++){
    		Conjunto::Pretas.push_back(new Peao(Posicao(i, 7), PRETO));
    	}
				/*Pretas.insert(Torre(1, 8, Peca.PRETO));
				Pretas.insert(Torre(8, 8, Peca.PRETO));
    		
				Pretas.insert(Cavalo(2, 8, Peca.PRETO));
				Pretas.insert(Cavalo(7, 8, Peca.PRETO));
		
				Pretas.insert(Bispo(3, 8, Peca.PRETO));
				Pretas.insert(Bispo(6, 8, Peca.PRETO));
		
				Pretas.insert(Dama(4, 8, Peca.PRETO));
		
				Pretas.insert(Rei(5, 8, Peca.PRETO));*/
}
		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::estaVazia(Posicao casa){
	for(Peca* a : Conjunto::Brancas) if(a->obterPosicao() == casa) return false;
	for(Peca* a : Conjunto::Pretas) if(a->obterPosicao() == casa) return false;
	
	return true;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::pretaOcupa(Posicao posicao){
	for(Peca* a : Conjunto::Pretas) if(a->obterPosicao() == posicao) return true;
	
	return false;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::brancaOcupa(Posicao posicao){
	for(Peca* a : Conjunto::Brancas) if(a->obterPosicao() == posicao) return true;
	
	return false;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::destruir(Posicao posicao, int cor){
	vector<Peca *> aux;
	int i = 0;
	
	aux = cor==BRANCO? Brancas : Pretas;
	
	for(Peca *p : aux){
		if((*p).obterPosicao() == posicao){
			delete p;
			aux.erase(aux.begin() + i);
			return;
		}
		i++;
	}
	
	return;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::jogarBranca(){
	while(!Conjunto::Brancas[Aleatoria::aleatoria(Brancas.size())]->mover()){}
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::jogarPreta(){
	while(!Conjunto::Pretas[Aleatoria::aleatoria(Pretas.size())]->mover()){}
}
