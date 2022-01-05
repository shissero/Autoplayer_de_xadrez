/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 04/01/2021

*/

#include<iostream>

#include"Conjunto.h"

int main(){

    Conjunto conjunto = Conjunto();
    
   /* int p = 1;
    
    int k;
    
    for(Peca *a : conjunto.Brancas){
    
    	a -> mostrarMovimentos();
    	
    	cout << endl;
    }*/
    
    
    
    for(int i = 0; i < 50; i++){
    
    	conjunto.jogar(p);
    	
    	p *= -1;
    	
    	cin >> k;
    }
}
