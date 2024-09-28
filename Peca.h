/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef PECA_H_
#define PECA_H_

#include<array>
#include<string>
#include<vector>

#include"Movimento.h"
#include"Posicao.h"

#define BRANCO 1
#define PRETO -1

using namespace std;

class Peca {

	public:
		Peca(Posicao, int);
		
		string emString();
		
		virtual void gerarMovimentos(vector<Movimento *> *);
		
		void gerarMovimentosCardeais(vector<Movimento *> *, int);
		
		void gerarMovimentosColaterais(vector<Movimento *> *, int);

		virtual int mover();
		
		void mostrarMovimentos();
		
		bool movimentoEPossivel(Posicao);
		
		void mudarPosicao(Posicao);
		
		virtual string obterClasse();
		
		int obterCor();
		
		string obterCorComoString();
		
		Posicao obterPosicao();
		
	protected:
	
	const int cor;
	Posicao posicao;
};

#endif
