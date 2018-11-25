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


int main(int argc, char *argv[]) {

	// Define o arquivo de entrada
	ifstream in(argv[1]);

	// Locale
	setlocale (LC_ALL,"pt_BR.UTF-8");

	// Cria uma estrutura Eleicao a partir da entrada "in"
	Eleicao* e = new Eleicao(in);

	// Define o número de vagas e imprime
	e->setVagas();
	string saida = "Número de vagas: " + std::to_string(e->getVagas()) + "\n\n";
	cout << saida;

	// Cria as strings referentes às listas de candidatos e imprime
	cout << e->criaEleitos();
	cout << e->criaMaisVotados();
	cout << e->criaEleitosMajoritaria();
	cout << e->criaBeneficiados();

	// Cria as strings referentes aos partidos e coligações e imprime
	cout << e->votacaoColigacao();
	cout << e->votacaoPartidos();

	// Define o número total de votos e imprime
	cout << e->totalNominais();

	// Fecha o arquivo de entrada
	in.close();

	return 0;
}
