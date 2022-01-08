/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 07/01/2021

*/

#include<chrono>
#include<fstream>
#include<iostream>

#include"Log.h"

using namespace std;

Log *Log::log = 0;

fstream Log::arquivoLog;

string obterTimeStamp();

Log::Log(){

	string nomeLog = obterTimeStamp() + ".log";
	
	Log::arquivoLog.open(nomeLog, ios::out);
}

void Log::escrever(string str){

	Log::obterInstancia() -> arquivoLog << str;
}

void Log::fechar(){

	if(Log::arquivoLog) Log::arquivoLog.close();
}

Log *Log::obterInstancia(){

	if(!Log::log) Log::log = new Log;
	
	return Log::log;
}


string obterTimeStamp(){

	time_t now = time(0);
	
	return ctime(&now);
}
