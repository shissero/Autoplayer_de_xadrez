/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef PECA_H_
#define PECA_H_

#include"Movimento.h"
#include"Posicao.h"

#include<vector>

class Conjunto;

class IPeca
{
public:
        IPeca() = default;

        IPeca(int cor, Posicao *);

        IPeca(int cor, Posicao *, Conjunto *);

        virtual ~IPeca() = default;

        static constexpr int BRANCO = 1;
        static constexpr int PRETO = -1;

        template<typename T> requires std::derived_from<T, IPeca>
        static T *criarPeca(int, Posicao *);

        virtual void gerarMovimentos(std::vector<Movimento *> &) = 0;

        int obterCor() const;

        const Posicao *obterPosicao() const;

        void definirConjunto(Conjunto *);

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
    Conjunto *conjunto = nullptr;

        void gerarMovimentosCardeais(std::vector<Movimento *> &, bool) const;

        void gerarMovimentosColaterais(std::vector<Movimento *> &, bool) const;

        void gerarMovs(std::vector<Movimento *> &, bool, bool) const; // TODO: essa função precisa de um nome melhor
};

template<typename T> requires std::derived_from<T, IPeca>
T * IPeca::criarPeca(int cor, Posicao *pos) {

    return new T(cor, pos);
}

#endif
