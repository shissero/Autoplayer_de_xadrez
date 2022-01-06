/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 05/01/2021

*/

#include<fstream>

#include"Log.h"

using namespace std;

Log Log::log = 0;

Log::Log(){

	do{
		arquivoLog.open("log", ios::out);
	}while(!arquivoLog);
}

void Log::escrever(string str){

	Log::obterInstancia().arquivoLog << str;
}

Log *Log::obterInstancia(){

	if(!Log::log) Log::log = new Log::Log();
	
	return Log::log;
}
