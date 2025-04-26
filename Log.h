/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 08/01/2021

*/

#ifndef LOG_H
#define LOG_H

#include<fstream>


/**
 * Esta classe é usada para logging - mensagens contendo informação sobre a execução do programa
 */
class Log {

public:

	// Excluindo métodos para instanciar a classe já que esta é estática
	Log(Log &) = delete;

	Log(Log const&) = delete;

	void operator=(const Log &) = delete;
	// Fim da exclusão dos métodos

	/**
	 * initLog executa tudo que é necessário para o logging. Deve ser chamada o mais cedo possível
	 */
	static void initLog();

	/**
	 * finishLog encerra o logging. Deve ser chamada o mais tarde possível
	 */
	static void finishLog();

	/*
	 * As funções de log abaixo não são automáticas. O programador que deve chamá-las quando achar necessário
	 * Os arquivos de log são salvos na pasta logs
	 */

	/**
	 * info grava logs puramente informativos
	 * @param str : a mensagem que deve ser gravada
	 */
	static void info(const std::string &str);

	/**
	 * debug grava logs para fins de depuração
	 * @param str a mensagem que deve ser gravada
	 */
	static void debug(const std::string &str);

	/**
	 * warning grava logs com avisos sobre situações potencialmente perigosas
	 * @param str a mensagem que deve ser gravada
	 */
	static void warning(const std::string &str);

	/**
	 * error grava logs sobre erros no programa que não o impedem de continuar rodando
	 * @param str a mensagem que deve ser gravada
	 */
	static void error(const std::string &str);

	/**
	 * fatal grava logs sobre erros que impedem o programa de continuar executando
	 * @param str a mensagem que deve ser gravada
	 */
	static void fatal(const std::string &str);

private:

	Log();

	/**
	 * Referêcia usada para acessar o arquivo de log
	 */
	static std::fstream logFile;

	/**
	 * Esta variável contém o caminho para a pasta onde os arquivos de log serão salvos
	 */
	static std::string logsHome;

	/**
	 *
	 * @return Um nome para arquivo de log
	 */
	static std::string getLogFileName();

	/**
	 *  Escreve a string recebida num arquivo de log
	 */
	static void write(const std::string &);
};

#endif /* LOG_H */
