/*

	Autor: Cícero Augusto Alcântara de Sousa

*/
#include"Tabuleiro.h"


/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************/

Tabuleiro::~Tabuleiro()
{

	delete aliadas;
	delete adversarias;
}

Tabuleiro *Tabuleiro::criarTabuleiroCompleto(){

	auto tabuleiro = new Tabuleiro();

	tabuleiro -> aliadas = Time::criarTimeCompleto(IPeca::BRANCO, tabuleiro);

	tabuleiro -> adversarias = Time::criarTimeCompleto(IPeca::PRETO, tabuleiro);

	return tabuleiro;
}

void Tabuleiro::definirAliadas(Time *ali)
{
	ali->definirTabuleiro(this);

	aliadas = ali;
}

void Tabuleiro::definirAdversarias(Time *adv)
{
	adv->definirTabuleiro(this);

	adversarias = adv;
}

int Tabuleiro::ocupadaPor(Posicao *posicao) const
{
	if(aliadas -> ocupada(posicao)) return aliadas->obterCor();
	if(adversarias -> ocupada(posicao)) return adversarias->obterCor();

	return 0;
}

void Tabuleiro::executarMovimento(Movimento *movimento)
{
	tocada->definirPosicao(movimento->obterDestino(), true); // Mudamos a posição da peça

	tocada = nullptr; // O movimento foi feito, então não há mais peça tocada

	if(movimento->obterNatureza() == Movimento::CAPTURA) adversarias->destruir(movimento->obterDestino());
}

void Tabuleiro::passarVez()
{
	Time *aux = aliadas;

	aliadas = adversarias;
	adversarias = aux;
}

Peao *Tabuleiro::obterEnPassant() const
{
	return enPassant;
}

void Tabuleiro::definirEnPassant(Peao *en_passant)
{
	enPassant = en_passant;
}

bool Tabuleiro::obterStatusEnPassant() const
{
	return statusEnPassant;
}

void Tabuleiro::definirStatusEnPassant(bool status_en_passant)
{
	statusEnPassant = status_en_passant;
}

bool Tabuleiro::obterEmXeque() const
{
	return emXeque;
}

void Tabuleiro::definirEmXeque(bool em_xeque)
{
	emXeque = em_xeque;
}

IPeca *Tabuleiro::obterPecaTocada() const
{
	return tocada;
}

void Tabuleiro::definirTocada(IPeca *tocada)
{
	this->tocada = tocada;
}

void Tabuleiro::definirTocada(Posicao *toc)
{
	tocada = aliadas->obterPeca(toc);
}

IPeca * Tabuleiro::obterPeca(int, int)
{

}

Movimento * Tabuleiro::buscarMovimentoTocada(Posicao *posicao)
{
	Movimento *resultado = nullptr;
	std::vector<Movimento*> movimentos;

	tocada->gerarMovimentos(movimentos);

	for(Movimento *m : movimentos)
	{
		if(*(m->obterDestino()) == posicao) resultado = m;
		else delete m;
	}

	return resultado;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Tabuleiro::atacadaPor(Posicao pos, int cor){

	vector<IPeca *> aux = cor == PRETO ? Tabuleiro::Pretas : Tabuleiro::Brancas;

	for(IPeca *p : aux) if(p -> movimentoEPossivel(pos)) return true;

	return false;
}

/*********************************************************************************************
**********************************************************************************************
**********************************************************************************************

void Tabuleiro::capturar(Posicao posicao, int cor){

	vector<IPeca *> *aux = cor==BRANCO ? &Pretas : &Brancas;

	for(IPeca *a : *aux){
		if(a -> obterPosicao() == posicao) destruir(a);
	}

	return;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************/

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Tabuleiro::destruir(IPeca *peca){

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

void Tabuleiro::destruir(Posicao pos, int cor){

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


void Tabuleiro::destruirEnPassant(){

	Tabuleiro::destruir(enPassant);

	enPassant = 0;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Tabuleiro::estaVazia(Posicao casa){
	for(IPeca *a : Tabuleiro::Brancas) if(a->obterPosicao() == casa) return false;
	for(IPeca *a : Tabuleiro::Pretas) if(a->obterPosicao() == casa) return false;

	return true;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

bool Tabuleiro::inimigaOcupa(int cor, Posicao posicao){

	vector<IPeca *> *aux = cor == BRANCO ? &Tabuleiro::Pretas : &Tabuleiro::Brancas;

	for(IPeca* a : *aux) if(a->obterPosicao() == posicao) return true;

	return false;
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Tabuleiro::jogar(int cor){

	if(cor == BRANCO){

		Log::escrever("Vez das brancas\n\n");
	}
	else{

		Log::escrever("Vez das pretas\n\n");
	}

	Log::escrever("Tabuleiro:\n\n");

	for(int i = 0; i < Tabuleiro::Brancas.size(); i++){

		Log::escrever(Tabuleiro::Brancas[i] -> emString() + "\n");
	}

	for(int i = 0; i < Tabuleiro::Pretas.size(); i++){

		Log::escrever(Tabuleiro::Pretas[i] -> emString() + "\n");
	}

	Log::escrever("\n");



	vector<IPeca *> pecasJogaveis = cor == BRANCO ? Tabuleiro::Brancas : Tabuleiro::Pretas;

	if(Tabuleiro::obterStatusEnPassant()) Tabuleiro::limparEnPassant();

	while(pecasJogaveis.size()){

		int i = Aleatoria::aleatoria(pecasJogaveis.size());

		int natureza = pecasJogaveis[i] -> mover();

		if(natureza == -1) pecasJogaveis.erase(pecasJogaveis.begin() + i);
		else{

			IPeca *aux = pecasJogaveis[i];

			if(aux -> obterClasse() == "Peao" && dynamic_cast<Peao *>(aux) -> valePromocao()){

				Log::escrever("Peao promovido ");

				aux = Tabuleiro::promover(dynamic_cast<Peao *>(aux));

				Log::escrever(aux -> emString() + "\n\n");
			}

			emXeque = Tabuleiro::xeque(aux);

			if(emXeque) Log::escrever("EM XEQUE\n\n");
			else Log::escrever("NO XEQUE\n\n");
			break;
		}
	}

	Log::escrever("\n\n\n\n");
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Tabuleiro::limparEnPassant() const { enPassant == nullptr;}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

void Tabuleiro::listarTodasAsPecas(){
	for(IPeca *a : Brancas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;
	for(IPeca *a : Pretas) std::cout << a->obterClasse() << " " << a->obterCorComoString() << " " << a->obterPosicao().emString() << std::endl;

	exit(356);
}

/*********************************************************************************************
**********************************************************************************************
*********************************************************************************************

IPeca *Tabuleiro::promover(Peao *peao){

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

	Tabuleiro::destruir(peao);

	return (*aux)[aux -> size() - 1];
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

Peao *Tabuleiro::obterEnPassant() const { return enPassant; }

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

Rei Tabuleiro::obterRei(int cor){

	vector<IPeca *> aux = cor == PRETO ? Pretas : Brancas;

	for(IPeca *p : aux) if(p -> obterClasse() == "Rei") return *(dynamic_cast<Rei *>(p));
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

bool Tabuleiro::obterStatusEnPassant() const {

	return statusEnPassant;
}

/**********************************************************************************************************************
***********************************************************************************************************************
**********************************************************************************************************************

bool Tabuleiro::valeEnPassant(Posicao posicao, int cor){

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

bool Tabuleiro::xeque(IPeca *peca){

	Log::escrever("Xeque peca recebeu ");
	Log::escrever(peca -> emString() + "\n\n");

	return peca -> movimentoEPossivel(obterRei(-peca -> obterCor()).obterPosicao());
}
*/
