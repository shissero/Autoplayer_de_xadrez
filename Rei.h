/*

	Autor: Cícero Augusto Alcântara de Sousa

*/

#ifndef REI_H_
#define REI_H_

#include"IPeca.h"

class Rei : public IPeca {
public:
	Rei(int cor, Posicao *posicao);

	Rei(int cor, Posicao *posicao, Tabuleiro *tabuleiro);

	~Rei() override = default;

	void gerarMovimentos(std::vector<Movimento *> &) override;

	void gerarCasasAtacadas(std::vector<Movimento *> &) override;

private:
    bool primeiroMovimento = true;


    //void adicionarRoques();
};

#endif
