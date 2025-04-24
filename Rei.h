/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef REI_H_
#define REI_H_


#include"IPeca.h"

class Rei : public IPeca {
public:
	Rei(int cor, Posicao *posicao);

	~Rei() override = default;

	void gerarMovimentos(std::vector<Movimento> &) override;

private:
    bool primeiroMovimento = true;


    //void adicionarRoques();
};

#endif
