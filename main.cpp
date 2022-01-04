/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#include<iostream>

#include"Conjunto.h"

int main(){

    Conjunto conjunto = Conjunto();
    
    for(int i = 0; i < 10; i++){
    
    	std::cout << i + 1 << endl;
    
    	conjunto.jogar(BRANCO);
    	
    	conjunto.jogar(PRETO);
    }
}
