#include<array>
#include<string>
#include"Posicao.h"



Posicao::Posicao(int coluna, int linha)
	: coluna (coluna), linha (linha)
{}

bool Posicao::operator==(const Posicao& posicao){
	return this->coluna == posicao.coluna && this->linha == posicao.linha ? true : false;
}

string Posicao::toString(){
	string str = "";
	return str + to_string(this->coluna) + ", " + to_string(this->linha) + "\n";
}
