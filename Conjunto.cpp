/*

	Autor: Cícero Augusto Alcântara de Sousa

*/
#include"Conjunto.h"


/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************/
	
Conjunto *Conjunto::criarConjuntoCompleto(){

	auto conjunto = new Conjunto();

	conjunto -> aliadas = Time::criarTimeCompleto(IPeca::BRANCO, conjunto);

	conjunto -> adversarias = Time::criarTimeCompleto(IPeca::PRETO, conjunto);

	return conjunto;
}

void Conjunto::definirAliadas(Time *ali)
{
	ali->definirConjunto(this);

	aliadas = ali;
}

void Conjunto::definirAdversarias(Time *adv)
{
	adv->definirConjunto(this);

	adversarias = adv;
}

int Conjunto::ocupadaPor(Posicao *posicao) const
{
	if(aliadas -> ocupada(posicao)) return aliadas->obterCor();
	if(adversarias -> ocupada(posicao)) return adversarias->obterCor();

	return 0;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Conjunto::atacadaPor(Posicao pos, int cor){

	vector<IPeca *> aux = cor == PRETO ? Conjunto::Pretas : Conjunto::Brancas;
	
	for(IPeca *p : aux) if(p -> movimentoEPossivel(pos)) return true;
	
	return false;
}

/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************

void Conjunto::capturar(Posicao posicao, int cor){
	
	vector<IPeca *> *aux = cor==BRANCO ? &Pretas : &Brancas;
	
	for(IPeca *a : *aux){
		if(a -> obterPosicao() == posicao) destruir(a);
	}
	
	return;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::definirEnPassant(Peao *peao){ enPassant = peao; }

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

void Conjunto::definirStatusEnPassant(bool status){

	statusEnPassant = status;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Conjunto::destruir(IPeca *peca){

	vector<IPeca *> *aux = peca -> obterCor() == BRANCO ? &Brancas : &Pretas;

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
*********************************************************************************************

void Conjunto::destruir(Posicao pos, int cor){

	vector<IPeca *> *aux = cor == PRETO ? &Pretas : &Brancas;

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
*********************************************************************************************


void Conjunto::destruirEnPassant(){

	Conjunto::destruir(enPassant);

	enPassant = 0;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Conjunto::estaVazia(Posicao casa){
	for(IPeca *a : Conjunto::Brancas) if(a->obterPosicao() == casa) return false;
	for(IPeca *a : Conjunto::Pretas) if(a->obterPosicao() == casa) return false;

	return true;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Conjunto::inimigaOcupa(int cor, Posicao posicao){

	vector<IPeca *> *aux = cor == BRANCO ? &Conjunto::Pretas : &Conjunto::Brancas;

	for(IPeca* a : *aux) if(a->obterPosicao() == posicao) return true;

	return false;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

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



	vector<IPeca *> pecasJogaveis = cor == BRANCO ? Conjunto::Brancas : Conjunto::Pretas;

	if(Conjunto::obterStatusEnPassant()) Conjunto::limparEnPassant();

	while(pecasJogaveis.size()){

		int i = Aleatoria::aleatoria(pecasJogaveis.size());

		int natureza = pecasJogaveis[i] -> mover();

		if(natureza == -1) pecasJogaveis.erase(pecasJogaveis.begin() + i);
		else{

			IPeca *aux = pecasJogaveis[i];

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

void Conjunto::limparEnPassant() const { enPassant == nullptr;}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Conjunto::listarTodasAsPecas(){
	for(IPeca *a : Brancas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;
	for(IPeca *a : Pretas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;

	exit(356);
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

IPeca *Conjunto::promover(Peao *peao){

	vector<IPeca *> *aux = peao -> obterCor() == BRANCO ? &Brancas : &Pretas;

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

Peao *Conjunto::obterEnPassant() const { return enPassant; }

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

Rei Conjunto::obterRei(int cor){

	vector<IPeca *> aux = cor == PRETO ? Pretas : Brancas;

	for(IPeca *p : aux) if(p -> obterClasse() == "Rei") return *(dynamic_cast<Rei *>(p));
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************/

bool Conjunto::obterStatusEnPassant() const {

	return statusEnPassant;
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

bool Conjunto::valeEnPassant(Posicao posicao, int cor){

	if(!enPassant) return false;
	else{

		Posicao aux = Posicao( posicao.coluna, posicao.linha + cor);

		if(enPassant -> obterPosicao() == aux && enPassant -> obterCor() == cor) return true;
		else return false;
	}
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

bool Conjunto::xeque(IPeca *peca){

	Log::escrever("Xeque peca recebeu ");
	Log::escrever(peca -> emString() + "\n\n");

	return peca -> movimentoEPossivel(obterRei(-peca -> obterCor()).obterPosicao());
}
*/
