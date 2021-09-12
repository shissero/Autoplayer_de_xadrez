#include<array>
#include<string>
#include"Posicao.h"



Posicao::Posicao(int coluna, int linha)
	: casa {coluna, linha}
{}
	
string Posicao::toString(){
	string str = "";
	return str + to_string(Posicao::casa[0]) + ", " + to_string(Posicao::casa[1]) + "\n";
}
