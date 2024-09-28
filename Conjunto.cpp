/*

	Autor: Cícero Augusto Alcântara de Sousa

	Última edição: 28/09/2024

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

bool Conjunto::emXeque = false;



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
		if(a -> obterPosicao() == posicao) destruir(a);
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

void Conjunto::destruir(Peca *peca){

	vector<Peca *> *aux = peca -> obterCor() == BRANCO ? &Brancas : &Pretas;
	
	for(int i = 0; i < aux -> size(); i++){
	
		if((*aux)[i] == peca){
		
			delete peca;
			
			aux -> erase(aux -> begin() + i);
			
			return;
		}
	}
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::destruir(Posicao pos, int cor){

	vector<Peca *> *aux = cor == PRETO ? &Pretas : &Brancas;
	
	for(int i = 0; i < aux -> size(); i++){
	
		if((*aux)[i] -> obterPosicao() == pos){
		
			delete (*aux)[i];
			
			aux -> erase(aux -> begin() + i);
			
			return;
		}
	}
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/


void Conjunto::destruirEnPassant(){

	Conjunto::destruir(enPassant);
	
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
		
			Peca *aux = pecasJogaveis[i];
		
			if(aux -> obterClasse() == "Peao" && dynamic_cast<Peao *>(aux) -> valePromocao()){
			
				Log::escrever("Peao promovido ");
			
				aux = Conjunto::promover(dynamic_cast<Peao *>(aux));
				
				Log::escrever(aux -> emString() + "\n\n");
			}
			
			emXeque = Conjunto::xeque(aux);
			
			if(emXeque) Log::escrever("EM XEQUE\n\n");
			else Log::escrever("NO XEQUE\n\n");
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

Peca *Conjunto::promover(Peao *peao){

	vector<Peca *> *aux = peao -> obterCor() == BRANCO ? &Brancas : &Pretas;
	
	switch(Aleatoria::aleatoria(4)){
	
		case 0:
			aux->push_back(new Torre(peao -> obterPosicao(), peao -> obterCor()));
			
			break;
			
		case 1:
			aux->push_back(new Cavalo(peao -> obterPosicao(), peao -> obterCor()));
			break;
			
		case 2:
			aux->push_back(new Bispo(peao -> obterPosicao(), peao -> obterCor()));
			break;
			
		case 3:
			aux->push_back(new Dama(peao -> obterPosicao(), peao -> obterCor()));
			break;
	}
	
	Conjunto::destruir(peao);
	
	return (*aux)[aux -> size() - 1];
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

Peca *Conjunto::obterEnPassant(){ return Conjunto::enPassant; }

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

Rei Conjunto::obterRei(int cor){

	vector<Peca *> aux = cor == PRETO ? Pretas : Brancas;
	
	for(Peca *p : aux) if(p -> obterClasse() == "Rei") return *(dynamic_cast<Rei *>(p));
}

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

bool Conjunto::xeque(Peca *peca){

	Log::escrever("Xeque peca recebeu ");
	Log::escrever(peca -> emString() + "\n\n");

	return peca -> movimentoEPossivel(obterRei(-peca -> obterCor()).obterPosicao());
}
