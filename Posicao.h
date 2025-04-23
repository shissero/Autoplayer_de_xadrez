/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#ifndef POSICAO_H_
#define POSICAO_H_

class Posicao {

public:

	Posicao() = default;

	Posicao(int, int);

	int coluna() const; // Esse métdodo é um getter
	int linha() const; // Esse métdodo é um getter

	void coluna(int); // Esse métdodo é um setter
	void linha(int); // Esse métdodo é um setter

	bool operator==(const Posicao&) const;

	Posicao operator+(const Posicao&) const;

private:

	int coordinates[2]{};

	static constexpr int COLUNA = 0;
	static constexpr int LINHA = 1;
};

#endif
