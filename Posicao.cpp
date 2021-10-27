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
	str.push_back(static_cast<char>(this->coluna + 96));
	
	return str + ", " + to_string(this->linha);
}
