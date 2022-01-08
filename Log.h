/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 07/01/2021

*/

#ifndef LOG_H_
#define LOG_H_

#include<fstream>

using namespace std;

class Log{

	private:
	
		Log();
		
		static Log *log;
		
		static fstream arquivoLog;
		
	public:
	
		Log(Log &log) = delete;
		
		static void escrever(string);
		
		static void fechar();
		
		void operator=(const Log &) = delete;
		
		static Log *obterInstancia();
};

#endif
