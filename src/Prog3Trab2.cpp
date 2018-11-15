//============================================================================
// Name        : Prog3Trab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <locale>
using namespace std;

//classes
#include "Candidato.h"
#include "Partido.h"
#include "Coligacao.h"
#include "Eleicao.h"


int main() {
	//leitura de arquivo
	ifstream in("test.txt");

	Eleicao* e = new Eleicao(in);

	e->setVagas();
	string saida = "Número de vagas: " + std::to_string(e->getVagas()) + "\n\n";
	cout << saida;

	cout << e->criaEleitos();
	cout << e->criaMaisVotados();
	cout << e->criaEleitosMajoritaria();
	cout << e->criaBeneficiados();

	cout << e->votacaoColigacao();
	cout << e->votacaoPartidos();

	cout << e->totalNominais();

	in.close();

	int i;
	while(1) {
		i = 0;
	}

	return 0;
}
