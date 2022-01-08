/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

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
	
		Log(Log &) = delete;
		
		Log(Log const&) = delete;
		
		static void escrever(string);
		
		static void fechar();
		
		static Log *obterInstancia();
		
		void operator=(const Log &) = delete;
};

#endif
