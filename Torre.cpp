#include<vector>

class Torre {

	public:
		Peca(Posicao posicao, int cor){
			this.cor = cor;
			this.posicao = posicao;
		}

		virtual bool mover(){
			vector<Posicao> movimentos;
			Posicao mover_para = this.posicao;
			
			/* Gerar coluna no sentido crescente das linhas */
			
			mover_para.linha++;
			
			while(posicao.linha < 7){
				movimentos.insert(mover_para);
				mover_para.linha++;
			}
			
			/* Gerar coluna no sentido decrescente das linhas */
			
			mover_para = this.posicao;
			
			mover_para.linha--;
			
			while(posicao.linha > 0){
				movimentos.insert(mover_para);
				mover_para.linha--;
			}
			
			/* Gerar linha no sentido crescente das colunas */
			
			mover_para = this.posicao;
			
			mover_para.coluna++;
			
			while(posicao.coluna < 7){
				movimentos.insert(mover_para);
				mover_para.coluna++;
			}
			
			/* Gerar linha no sentido decrescente das colunas */
			
			mover_para = this.posicao;
			
			mover_para.coluna--;
			
			while(posicao.coluna < 0){
				movimentos.insert(mover_para);
				mover_para.coluna--;
			}
		};
		
	private:
	
	int cor;
	array posicao;
};
