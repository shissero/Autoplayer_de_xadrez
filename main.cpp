#include"Peca.h"
#include"Conjunto.h"

int main(){
    Conjunto Brancas = Conjunto(BRANCO), Pretas = Conjunto(PRETO);
    
    while(true){
    	Brancas.jogar();
    	Pretas.jogar();
    }    
};
