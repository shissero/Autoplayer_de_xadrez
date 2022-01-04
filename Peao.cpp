/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#include<cmath>
#include<iostream>
#include<string>
#include<vector>

#include"Aleatoria.h"
#include"Conjunto.h"
#include"Movimento.h"
#include"Peao.h"
#include"Peca.h"

using namespace std;


Peao::Peao(Posicao posicao, int cor) : Peca(posicao, cor) {}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

void Peao::gerarMovimentos(vector<Movimento *> *vetor){

	Posicao pos = Posicao(this -> posicao.coluna, this -> posicao.linha + this -> cor);

	if( (1 < this->posicao.linha && this->posicao.linha < 8) && Conjunto::estaVazia(pos)){
				
		vetor -> push_back(new Movimento(pos, NEUTRO));
		
		
		pos = Posicao(this->posicao.coluna, this->posicao.linha + 2*(this -> cor));
				
		if(this -> primeiroMovimento && Conjunto::estaVazia(pos)){
			
			vetor -> push_back(new Movimento(pos, EN_PASSANT_PASSIVA));
		}
	}

	
	pos = Posicao(this->posicao.coluna - 1, this->posicao.linha + this -> cor);

	if(this->posicao.coluna > 1){
	
		if(Conjunto::inimigaOcupa(this -> cor, pos)){
					
			vetor -> push_back(new Movimento(pos, CAPTURA));
		}
		else if(Conjunto::valeEnPassant(pos, -(this -> cor))){
		
			vetor -> push_back(new Movimento(pos, EN_PASSANT_ATIVA));
		}
	}


	pos = Posicao(this->posicao.coluna + 1, this->posicao.linha + this -> cor);
				
	if(this->posicao.coluna < 8){
	
		if(Conjunto::inimigaOcupa(this -> cor, pos)){
					
			vetor -> push_back(new Movimento(pos, CAPTURA));
		}
		else if(Conjunto::valeEnPassant(pos, -(this -> cor))){
			
			vetor -> push_back(new Movimento(pos, EN_PASSANT_ATIVA));
		}
	}
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

		
int Peao::mover(){

	int natureza = this -> Peca::mover();


	if(natureza != -1){
		
		this -> primeiroMovimento = false;
		
		Conjunto::definirStatusEnPassant(true);
		
		switch(natureza){
		
			case EN_PASSANT_PASSIVA:
				Conjunto::definirEnPassant(this);
				Conjunto::definirStatusEnPassant(false);
				break;
				
			case EN_PASSANT_ATIVA:
				Conjunto::destruirEnPassant();
				
		}
	}
	
	return natureza;
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/


string Peao::obterClasse(){
	return "Peao";
}
