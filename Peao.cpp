/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#include"Peao.h"
#include"IPeca.h"
#include"Movimento.h"

#include<vector>


Peao::Peao(int cor, Posicao *posicao) : IPeca(cor, posicao) {}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

void Peao::gerarMovimentos(std::vector<Movimento> &movimentos){
/*
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
	}*/
}

bool Peao::obterPrimeiroMovimento() const {

	return primeiroMovimento;
}

void Peao::definirPrimeiroMovimento(bool valor) {

	primeiroMovimento = valor;
}
