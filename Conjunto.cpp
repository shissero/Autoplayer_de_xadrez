#include<iostream>
#include<stdlib.h>
#include<vector>

#include"Aleatoria.h"
#include"Bispo.h"
#include"Cavalo.h"
#include"Conjunto.h"
#include"Dama.h"
#include"Peao.h"
#include"Peca.h"
#include"Posicao.h"
#include"Torre.h"



using namespace std;

vector<Peca *> Conjunto::Brancas, Conjunto::Pretas;

Peca *Conjunto::enPassant = 0;
	
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

void Conjunto::capturar(Posicao posicao, int cor){
	
	vector<Peca *> *aux = cor==BRANCO ? &Pretas : &Brancas;
	
	for(Peca *a : *aux){
		if(a -> obterPosicao() == posicao) destruir(posicao, a -> obterCor());
	}
	
	return;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::definirEnPassant(Peao *peao){ Conjunto::enPassant = peao; }

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::destruir(Posicao posicao, int cor){

	vector<Peca *> *aux = cor == BRANCO ? &Brancas : &Pretas;
	
	int i = 0;
	
	for(Peca *p : *aux){
		if(p -> obterPosicao() == posicao){
			delete p;
			aux->erase(aux->begin() + i);
			return;
		}
		i++;
	}
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

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::limparEnPassant(){ Conjunto::enPassant == 0;}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

Peca *Conjunto::obterEnPassant(){ return Conjunto::enPassant; }

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::promover(Peao peao, Posicao promovido){

	vector<Peca *> *aux = peao.obterCor() == BRANCO ? &Brancas : &Pretas;
	
	destruir(peao.obterPosicao(), peao.obterCor());
	
	switch(Aleatoria::aleatoria(4)){
	
		case 0:
			aux->push_back(new Torre(promovido, peao.obterCor()));
			
			break;
			
		case 1:
			aux->push_back(new Cavalo(promovido, peao.obterCor()));
			break;
			
		case 2:
			aux->push_back(new Bispo(promovido, peao.obterCor()));
			break;
			
		case 3:
			aux->push_back(new Dama(promovido, peao.obterCor()));
			break;
	}
	
	listarTodasAsPecas();
	
	std::cout << "\n";
	
	listarTodasAsPecas();
}

/******************************************************************************************
*******************************************************************************************
******************************************************************************************/

bool Conjunto::valeEnPassant(Posicao posicao){

	if(!Conjunto::enPassant) return false;
	else return posicao == Conjunto::enPassant -> obterPosicao();
}

/******************************************************************************************
*******************************************************************************************
******************************************************************************************/

void Conjunto::listarTodasAsPecas(){
	for(Peca *a : Brancas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().toString() << std::endl;
	for(Peca *a : Pretas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().toString() << std::endl;
	
	exit(356);
}
