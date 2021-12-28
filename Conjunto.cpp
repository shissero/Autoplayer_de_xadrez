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
#include"Torre.h"



using namespace std;

vector<Peca *> Conjunto::Brancas, Conjunto::Pretas;

Peca *Conjunto::enPassant = 0;

bool Conjunto::statusEnPassant = true;



/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************/
	
Conjunto::Conjunto(){

	for(int i = 1; i < 9; i++){
		Conjunto::Brancas.push_back(new Peao(Posicao(i, 2), BRANCO));
	}
    		
				//Brancas.push_back(new Torre(Posicao(1, 1), BRANCO));
			//	Brancas.push_back(new Torre(Posicao(8, 1), BRANCO));
    		/*
				Brancas.push_back(Cavalo(2, 1, Peca.BRANCO));
				Brancas.push_back(Cavalo(7, 1 Peca.BRANCO));
		
				Brancas.push_back(Bispo(3, 1, Peca.BRANCO));
				Brancas.push_back(Bispo(6, 1, Peca.BRANCO));
		
				Brancas.push_back(Dama(4, 1, Peca.BRANCO));
		
				Brancas.push_back(Rei(5, 1, Peca.BRANCO));*/
			
	for(int i = 1; i < 9; i++){
    		Conjunto::Pretas.push_back(new Peao(Posicao(i, 7), PRETO));
    	}
			//	Pretas.push_back(new Torre(Posicao(1, 8), PRETO));
			//	Pretas.push_back(new Torre(Posicao(8, 8), PRETO));
    		
				/*Pretas.push_back(Cavalo(2, 8, Peca.PRETO));
				Pretas.push_back(Cavalo(7, 8, Peca.PRETO));
		
				Pretas.push_back(Bispo(3, 8, Peca.PRETO));
				Pretas.push_back(Bispo(6, 8, Peca.PRETO));
		
				Pretas.push_back(Dama(4, 8, Peca.PRETO));
		
				Pretas.push_back(Rei(5, 8, Peca.PRETO));*/
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

void Conjunto::definirStatusEnPassant(bool status){
	
	Conjunto::statusEnPassant = status;
}

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

void Conjunto::destruirEnPassant(){

	Conjunto::destruir(enPassant -> obterPosicao(), enPassant -> obterCor());
	
	enPassant = 0;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::estaVazia(Posicao casa){
	for(Peca *a : Conjunto::Brancas) if(a->obterPosicao() == casa) return false;
	for(Peca *a : Conjunto::Pretas) if(a->obterPosicao() == casa) return false;
	
	return true;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::inimigaOcupa(int cor, Posicao posicao){

	vector<Peca *> *aux = cor == BRANCO ? &Conjunto::Pretas : &Conjunto::Brancas;
	
	for(Peca* a : *aux) if(a->obterPosicao() == posicao) return true;
	
	return false;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::jogar(int cor){

	vector<Peca *> pecasJogaveis, aux = cor == BRANCO ? Conjunto::Brancas : Conjunto::Pretas;
	
	for(Peca *a : aux) pecasJogaveis.push_back(a);

	if(Conjunto::obterStatusEnPassant()) Conjunto::limparEnPassant();

	while(pecasJogaveis.size()){
	
		int i = Aleatoria::aleatoria(pecasJogaveis.size());
	
		int natureza = pecasJogaveis[i] -> mover();
		
		if(natureza == -1) pecasJogaveis.erase(pecasJogaveis.begin() + i);
		else break;
	}
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::limparEnPassant(){ Conjunto::enPassant == 0;}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::listarTodasAsPecas(){
	for(Peca *a : Brancas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;
	for(Peca *a : Pretas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;
	
	exit(356);
}

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

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

Peca *Conjunto::obterEnPassant(){ return Conjunto::enPassant; }

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

bool Conjunto::obterStatusEnPassant(){

	return Conjunto::statusEnPassant;
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

bool Conjunto::valeEnPassant(Posicao posicao, int cor){

	if(!Conjunto::enPassant) return false;
	else{
		
		Posicao aux = Posicao( posicao.coluna, posicao.linha + cor);
		
		if(Conjunto::enPassant -> obterPosicao() == aux && Conjunto::enPassant -> obterCor() == cor) return true;
		else return false;
	}
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/
