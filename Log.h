/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 05/01/2021

*/

#include<fstream>

using namespace std;

class Log{

	private:
	
		Log();
		
		static Log log;
		
		fstream arquivoLog;
		
	public:
	
		Log(Log &log) = delete;
		
		void operator=(const Log &) = delete;
		
		static Log *obterInstancia();
}
