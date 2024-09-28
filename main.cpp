/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 28/09/2024

*/

#include<iostream>

#include"Conjunto.h"
#include"Log.h"

int main(){

    Conjunto conjunto = Conjunto();
    
    int p = 1;
    
   for(int i = 0; i < 200; i++){
    
    	conjunto.jogar(p);
    	
    	p *= -1;
    }
}
