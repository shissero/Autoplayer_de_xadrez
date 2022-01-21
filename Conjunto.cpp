/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 21/01/2021

*/

#include<iostream>
#include<stdlib.h>
#include<vector>

#include"Aleatoria.h"
#include"Bispo.h"
#include"Cavalo.h"
#include"Conjunto.h"
#include"Dama.h"
#include"Log.h"
#include"Peao.h"
#include"Peca.h"
#include"Rei.h"
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
    		
	Brancas.push_back(new Torre(Posicao(1, 1), BRANCO));
	Brancas.push_back(new Torre(Posicao(8, 1), BRANCO));
    		
	Brancas.push_back(new Cavalo(Posicao(2, 1), BRANCO));
	Brancas.push_back(new Cavalo(Posicao(7, 1), BRANCO));
		
	Brancas.push_back(new Bispo(Posicao(3, 1), BRANCO));
	Brancas.push_back(new Bispo(Posicao(6, 1), BRANCO));
		
	Brancas.push_back(new Dama(Posicao(4, 1), BRANCO));
		
	Brancas.push_back(new Rei(Posicao(5, 1), BRANCO));
			
	for(int i = 1; i < 9; i++){
    		Conjunto::Pretas.push_back(new Peao(Posicao(i, 7), PRETO));
    	}
	
	Pretas.push_back(new Torre(Posicao(1, 8), PRETO));
	Pretas.push_back(new Torre(Posicao(8, 8), PRETO));
    		
	Pretas.push_back(new Cavalo(Posicao(2, 8), PRETO));
	Pretas.push_back(new Cavalo(Posicao(7, 8), PRETO));
		
	Pretas.push_back(new Bispo(Posicao(3, 8), PRETO));
	Pretas.push_back(new Bispo(Posicao(6, 8), PRETO));

	Pretas.push_back(new Dama(Posicao(4, 8), PRETO));
		
	Pretas.push_back(new Rei(Posicao(5, 8), PRETO));
}
		
/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

bool Conjunto::atacadaPor(Posicao pos, int cor){

	vector<Peca *> aux = cor == PRETO ? Conjunto::Pretas : Conjunto::Brancas;
	
	for(Peca *p : aux) if(p -> movimentoEPossivel(pos)) return true;
	
	return false;
}

/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************/

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

	if(cor == BRANCO){
	
		Log::escrever("Vez das brancas\n\n");
	}
	else{
	
		Log::escrever("Vez das pretas\n\n");
	}
	
	Log::escrever("Tabuleiro:\n\n");
	
	for(int i = 0; i < Conjunto::Brancas.size(); i++){
		
		Log::escrever(Conjunto::Brancas[i] -> emString() + "\n");
	}
	
	for(int i = 0; i < Conjunto::Pretas.size(); i++){
		
		Log::escrever(Conjunto::Pretas[i] -> emString() + "\n");
	}
	
	Log::escrever("\n");
	
	

	vector<Peca *> pecasJogaveis = cor == BRANCO ? Conjunto::Brancas : Conjunto::Pretas;

	if(Conjunto::obterStatusEnPassant()) Conjunto::limparEnPassant();

	while(pecasJogaveis.size()){
	
		int i = Aleatoria::aleatoria(pecasJogaveis.size());
	
		int natureza = pecasJogaveis[i] -> mover();
		
		if(natureza == -1) pecasJogaveis.erase(pecasJogaveis.begin() + i);
		else{
		
			if(pecasJogaveis[i] -> obterClasse() == "Peao" && pecasJogaveis[i] -> valePromocao()){
			
				Log("\tVale Promoção");
			}
			break;
		}
	}
	
	Log::escrever("\n\n\n\n");
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
