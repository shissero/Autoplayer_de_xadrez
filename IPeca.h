/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef PECA_H_
#define PECA_H_

#include"Movimento.h"
#include"Posicao.h"

#include<vector>

class Tabuleiro;

class IPeca
{
public:
        IPeca() = default;

        IPeca(int cor, Posicao *);

        IPeca(int cor, Posicao *, Tabuleiro *);

        virtual ~IPeca();

        static constexpr int BRANCO = 1;
        static constexpr int PRETO = -1;

        template<typename T> requires std::derived_from<T, IPeca>
        static T *criarPeca(int, Posicao *);

        virtual void gerarMovimentos(std::vector<Movimento *> &) = 0;

        virtual void gerarCasasAtacadas(std::vector<Movimento *> &) = 0;

        int obterCor() const;

        const Posicao *obterPosicao() const;

    void definirPosicao(Posicao*, bool);

        void definirTabuleiro(Tabuleiro *);

    /*
     * Checa se as duas tem o mesmo tipo
     */
	//virtual bool eIgual(const IPeca&) const;

    template<typename T, typename B>/* requires requires
    {
        std::same_as<T, B> &&
            std::derived_from<T, IPeca> &&
                std::derived_from<B, IPeca>;
    }*/
    static bool eIgual(const T &peca1, const B &peca2);

protected:
    int cor = 0;
    Posicao *posicao = nullptr;
    Tabuleiro *tabuleiro = nullptr;

        void gerarMovimentosCardeais(std::vector<Movimento *> &, bool, bool ataque) const;

        void gerarMovimentosColaterais(std::vector<Movimento *> &, bool, bool ataque) const;

        void gerarMovs(std::vector<Movimento *> &, bool, bool, bool ataque) const; // TODO: essa função precisa de um nome melhor
};

template<typename T> requires std::derived_from<T, IPeca>
T * IPeca::criarPeca(int cor, Posicao *pos) {

    return new T(cor, pos);
}

#endif
