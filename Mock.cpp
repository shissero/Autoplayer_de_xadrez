//
// Created by cicero on 25/04/25.
//

#include "Mock.h"

#include "Log.h"
#include "Tabuleiro.h"
#include "Time.h"


Cavalo *Mock::CB1 = nullptr;
Cavalo Mock::CB2 = Cavalo(IPeca::BRANCO, new Posicao(6, 5));
Bispo *Mock::iBB1 = nullptr;
Bispo *Mock::BB2 = nullptr;

Peao *Mock::PP1 = nullptr;
Torre *Mock::TP1 = nullptr;
Dama Mock::DP1 = Dama(IPeca::PRETO, new Posicao(5, 5));
Rei Mock::RP1 = Rei(IPeca::PRETO, new Posicao(0, 6));

Time *Mock::BRANCAS = nullptr;
Time *Mock::PRETAS = nullptr;
Tabuleiro *Mock::TAB = nullptr;

void altTabBispoAli();
void altTabTorreAdv();


Tabuleiro *Mock::obterTabuleiro()
{
        if(TAB != nullptr) return TAB;

        obterBrancas();
        obterPretas();

        TAB = new Tabuleiro();

        TAB->definirAliadas(BRANCAS);
        TAB->definirAdversarias(PRETAS);

        return TAB;
}

void Mock::obterTabTestMovsBispo()
{

        //Instanciando as peças necessárias ao teste
        BB2 = new Bispo(IPeca::BRANCO, new Posicao(3, 3));
        CB1 = new Cavalo(IPeca::BRANCO, new Posicao(5, 3));
        PP1 = new Peao(IPeca::PRETO, new Posicao(2, 6));


        // Instanciando o time de aliadas
        BRANCAS = new Time(IPeca::BRANCO);

        // Adicione as peças ao time
        BRANCAS->adicionarBispo(BB2);
        BRANCAS->adicionarCavalo(CB1);

        // Instancie as adversárias
        PRETAS = new Time(IPeca::PRETO);

        // Adicione peças
        PRETAS->adicionarPeao(PP1);

        TAB = new Tabuleiro();

        TAB->definirAliadas(BRANCAS);
        TAB->definirAdversarias(PRETAS);
}

void Mock::obterTabTestMovsTorre()
{

        //Instanciando as peças necessárias ao teste
        TP1 = new Torre(IPeca::PRETO, new Posicao(3, 3));
        PP1 = new Peao(IPeca::PRETO, new Posicao(2, 6));

        CB1 = new Cavalo(IPeca::BRANCO, new Posicao(5, 4));


        // Instanciando o time de aliadas
        BRANCAS = new Time(IPeca::BRANCO);

        // Adicione as peças ao time
        BRANCAS->adicionarCavalo(CB1);

        // Instancie as adversárias
        PRETAS = new Time(IPeca::PRETO);

        // Adicione peças
        PRETAS->adicionarPeao(PP1);
        PRETAS->adicionarTorre(TP1);

        TAB = new Tabuleiro();

        TAB->definirAliadas(PRETAS);
        TAB->definirAdversarias(BRANCAS);
}

void Mock::finalizarMock()
{
        delete TAB; // NOTA DE ESTUDO: não é necessário testar se o ponteiro é nulo antes de chamar delete, nada acontece quando se tenta deletar nulptr
}

Time *Mock::obterBrancas()
{
        if(BRANCAS != nullptr) return BRANCAS;

        BRANCAS = new Time(IPeca::BRANCO);

        BRANCAS->adicionarBispo(iBB1);
        BRANCAS->adicionarBispo(BB2);

        BRANCAS->adicionarCavalo(CB1);
        BRANCAS->adicionarCavalo(&CB2);

        return BRANCAS;
}

Time * Mock::obterPretas()
{
        if(PRETAS != nullptr) return PRETAS;

        PRETAS = new Time(IPeca::PRETO);

        PRETAS->adicionarPeao(PP1);
        PRETAS->adicionarDama(&DP1);

        return PRETAS;
}

void Mock::initMock()
{
        obterTabuleiro();
}

void Mock::testarMovimentosBispo()
{
        obterTabTestMovsBispo();

        std::vector<Movimento *> movimentos;

        BB2->gerarMovimentos(movimentos);

        movimentos.clear();

        altTabBispoAli();

        BB2->gerarCasasAtacadas(movimentos);

        return;
}

void Mock::testarMovimentosTorre()
{
        obterTabTestMovsTorre();

        std::vector<Movimento *> movimentos;

        TP1->gerarMovimentos(movimentos);

        movimentos.clear();

        altTabTorreAdv();

        TP1->gerarCasasAtacadas(movimentos);

        return;
}

void Mock::testarMovimentosDama()
{
        std::vector<Movimento *> movimentos;

        DP1.gerarMovimentos(movimentos);

        bool result = false;

        for(Movimento *m : movimentos) if(m->obterNatureza() != Movimento::DESLOCAMENTO) result = true;

        return;
}

void Mock::testarMovimentosCavalo()
{
        std::vector<Movimento *> movimentos;

        CB1->gerarMovimentos(movimentos);

        return;
}

void Mock::testarMovimentosPeao()
{
        std::vector<Movimento *> movimentos;

        PP1->gerarMovimentos(movimentos);

        movimentos.clear();

        PP1->definirPrimeiroMovimento(false);

        PP1->gerarMovimentos(movimentos);

        return;
}

void Mock::testarMovimentosRei()
{
        std::vector<Movimento *> movimentos;

        RP1.gerarMovimentos(movimentos);

        movimentos.clear();
}

void Mock::testarTimeOcupada()
{
        auto pos_vazia = Posicao(1, 7);
        auto pos_ali = Posicao(4, 4);
        auto pos_adv = Posicao(5, 0);

        Tabuleiro *con = TAB;

        int resultado1 = TAB->ocupadaPor(&pos_vazia);
        int resultado2 = TAB->ocupadaPor(&pos_ali);
        int resultado3 = TAB->ocupadaPor(&pos_adv);

        return;
}


void altTabBispoAli()
{
        Mock::CB1->definirPosicao(new Posicao(5, 5), true);
}

void altTabTorreAdv()
{
        Mock::CB1->definirPosicao(new Posicao(5, 3), true);
}
