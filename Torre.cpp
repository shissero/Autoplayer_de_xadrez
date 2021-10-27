#include<vector>
#include"Torre.h"
#include<iostream>
#include<string>


Torre::Torre(Posicao posicao, int cor) : Peca(posicao, cor) {}

std::string Torre::obterClasse(){
	return "Torre";
}

/*		virtual bool mover(){
			vector<Posicao> movimentos;
			Posicao mover_para = this.posicao;
			
			/* Gerar coluna no sentido crescente das linhas *
			
			mover_para.linha++;
			
			while(posicao.linha < 7){
				movimentos.insert(mover_para);
				mover_para.linha++;
			}
			
			/* Gerar coluna no sentido decrescente das linhas *
			
			mover_para = this.posicao;
			
			mover_para.linha--;
			
			while(posicao.linha > 0){
				movimentos.insert(mover_para);
				mover_para.linha--;
			}
			
			/* Gerar linha no sentido crescente das colunas *
			
			mover_para = this.posicao;
			
			mover_para.coluna++;
			
			while(posicao.coluna < 7){
				movimentos.insert(mover_para);
				mover_para.coluna++;
			}
			
			/* Gerar linha no sentido decrescente das colunas 
			
			mover_para = this.posicao;
			
			mover_para.coluna--;
			
			while(posicao.coluna < 0){
				movimentos.insert(mover_para);
				mover_para.coluna--;
			}
		};
		*/
