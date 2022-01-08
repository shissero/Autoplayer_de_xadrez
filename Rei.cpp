/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#include"Conjunto.h"
#include"Peca.h"
#include"Rei.h"

Rei::Rei(Posicao posicao, int cor) : Peca(posicao, cor) {}
		
void Rei::gerarMovimentos(vector<Movimento *> *movimentos){

	if(this -> posicao.linha > 1){
	
		Posicao pos = Posicao(this -> posicao.coluna, this -> posicao.linha - 1);
		
		if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
		else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		
		if(this -> posicao.coluna > 1){
		
			pos = Posicao(this -> posicao.coluna - 1, this -> posicao.linha - 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
		
		if(this -> posicao.coluna < 8){
		
			pos = Posicao(this -> posicao.coluna + 1, this -> posicao.linha - 1);
			
			if(Conjunto::estaVazia(pos)) movimentos -> push_back(new Movimento(pos, NEUTRO));
			else if(Conjunto::inimigaOcupa(this -> cor, pos)) movimentos -> push_back(new Movimento(pos, CAPTURA));
		}
	}
}
		
int Rei::mover(){

	int natureza = this -> Peca::mover();
	
	if(natureza != -1){
	
		this -> primeiroMovimento = false;
		
		Conjunto::definirStatusEnPassant(true);
	}
	
	return natureza;
}
		
string Rei::obterClasse(){

	return "Rei";
}
