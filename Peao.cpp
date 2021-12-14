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

string Peao::emString(){

	string str = "Peao ";
	
	return str + ( this -> cor == PRETO ? "preto" : "branco");
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/



void Peao::gerarMovimentos(vector<Movimento *> *vetor){

	Posicao pos = Posicao(this -> posicao.coluna, this -> posicao.linha + this -> cor);

	if(this->posicao.linha < 8 && Conjunto::estaVazia(pos)){
				
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

		
bool Peao::mover(){

	int cor1 = this -> cor, cor2;

	this -> Peca::mover();

	vector<Movimento *> movimentos;
	
	this->gerarMovimentos( &movimentos );
	
	if(!movimentos.size()) return false;
	else{
	
		Posicao origem = this -> posicao;
		
		Movimento mov = *movimentos[Aleatoria::aleatoria(movimentos.size())];
		
		this -> primeiroMovimento = false;
		
		this -> mudarPosicao(mov.obterDestino());
		
		switch(mov.obterNatureza()){
		
			case CAPTURA:
				Conjunto::destruir(mov.obterDestino(), -(this -> obterCor()));
				break;
				
			case EN_PASSANT_PASSIVA:
				Conjunto::definirEnPassant(this);
				break;
				
			case EN_PASSANT_ATIVA:
				Conjunto::destruirEnPassant();
				
		}
		
		cout << this -> emString() << " vai de " << origem.emString() << " para " << mov.obterDestino().emString() << endl;
	}
	
	return true;
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/


string Peao::obterClasse(){
	return "Peao";
}
