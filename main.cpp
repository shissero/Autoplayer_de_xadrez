#include<iostream>


#include"Conjunto.h"

int main(){
    Conjunto conjunto = Conjunto();
    
    for(int i = 0; i < 1; i++){
    
    	std::cout << i + 1 << endl;
    
    	conjunto.jogar(BRANCO);
    	
    	conjunto.jogar(PRETO);
    }
}
