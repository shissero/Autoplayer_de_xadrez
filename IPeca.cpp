/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2028

*/

#include"Conjunto.h"

#include"IPeca.h"

#include<vector>



//IPeca::IPeca() : cor(0), posicao(nullptr), conjunto(nullptr) {}

IPeca::IPeca(int cor, Posicao *posicao, Conjunto *conjunto): cor(cor),
                                                                   posicao(posicao),
                                                                   conjunto(conjunto){
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosCardeais(std::vector<Movimento> &movimentos, bool reiChamou){
/*
	Posicao aux;

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
			
			if(reiChamou){
			
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
			
			if(reiChamou){
			
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
			
			if(reiChamou){
			
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
			
			if(reiChamou){
			
				break;
			}
			
		}
		
	}*/
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

void IPeca::gerarMovimentosColaterais(std::vector<Movimento> &movimentos, bool reiChamou){
/*
	// Gerar movimentos na direção Nordeste
	if(this -> posicao.coluna < 8 && this -> posicao.linha < 8){
	
		for(int i = this -> posicao.coluna + 1, j = this -> posicao.linha + 1; i < 9 && j < 9; i++, j++){
		
			Posicao pos = Posicao(i, j);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else{
			
				if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
				break;
			}
			
			if(reiChamou){
			
				break;
			}
		}
	}
	
	// Gerar movimentos na direção Noroeste
	if(this -> posicao.coluna > 1 && this -> posicao.linha < 8){
	
		for(int i = this -> posicao.coluna - 1, j = this -> posicao.linha + 1; i > 0 && j < 9; i--, j++){
		
			Posicao pos = Posicao(i, j);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else{
			
				if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
				break;
			}
			
			if(reiChamou){
			
				break;
			}
		}
	}
	
	// Gerar movimentos na direção Sudoeste
	if(this -> posicao.coluna > 1 && this -> posicao.linha > 1){
	
		for(int i = this -> posicao.coluna - 1, j = this -> posicao.linha - 1; i > 0 && j > 0; i--, j--){
		
			Posicao pos = Posicao(i, j);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else{
			
				if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
				break;
			}
			
			if(reiChamou){
			
				break;
			}
		}
	}
	
	// Gerar movimentos na direção Sudeste
	if(this -> posicao.coluna < 8 && this -> posicao.linha > 1){
	
		for(int i = this -> posicao.coluna + 1, j = this -> posicao.linha - 1; i < 9 && j > 0; i++, j--){
		
			Posicao pos = Posicao(i, j);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else{
			
				if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
				break;
			}
			
			if(reiChamou){
			
				break;
			}
		}
	}*/
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

IPeca::IPeca(int cor, Posicao *posicao): cor(cor),
                                         posicao(posicao),
                                         conjunto(nullptr){
}

int IPeca::obterCor() const {

	return cor;
}

/**********************************************************************************************************
***********************************************************************************************************
**********************************************************************************************************/

const Posicao *IPeca::obterPosicao() const {

	return posicao;
}
