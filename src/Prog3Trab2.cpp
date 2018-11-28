//============================================================================
// Name        : Prog3Trab2.cpp
// Author      : Lucas Mendonça Emery Cade
//				 Lucas Moraes Soares de Souza
// Description : Trabalho 2 de Programação 3, do semestre 2018/2
//				 Implementar o sistema de impressão dos dados da eleição
//				 Conforme as especificações, em C++
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <locale>
using namespace std;

// Classes
#include "Candidato.h"
#include "Partido.h"
#include "Coligacao.h"
#include "Eleicao.h"

// Entrada e Saída
#include "Entrada.h"
Entrada entrada;
#include "Saida.h"
Saida saida;

int main(int argc, char *argv[]) {

	// Define o arquivo de entrada
	ifstream in(argv[1]);

	// Locale
	setlocale (LC_ALL,"pt_BR.UTF-8");

	// Cria uma estrutura Eleicao
	Eleicao e = Eleicao();

	// Le o arquivo de entrada e preenche as informações da eleião
	entrada.leEntrada(in, e);

	// Preenche as listas de partidos e coligações e calcula o número de vagas
	e.partidoColigacaoVagas();

	saida.imprimeEleicao(e);

	// Fecha o arquivo de entrada
	in.close();

	return 0;
}
