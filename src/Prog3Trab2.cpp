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

//bibliotecas extras
#include <sstream>
#include <locale>

//classes
#include "Candidato.h"
#include "CandidatoSentinel.h"

using namespace std;

Candidato* retornaCandidato(std::ifstream& in, string linha){
	Candidato c = Candidato();
	double numero;
	//Seq. (i);N�m.;Candidato;Partido/Coliga��o;Vota��o;% V�lidos Formata��o do texto

	//coloca��o,  aprimeira linha j� � pega pelo loop
	//cout << linha;
	c.setColocacao(linha);
	//cout << " ";

	//numero
	getline(in, linha, ';');
	//convers�o de string para double
	istringstream (linha) >> numero;
	//cout << numero;
	//cout << " ";
	c.setNum(numero);

	//nome
	getline(in, linha, ';');
	//cout << linha;
	//cout << " ";
	c.setNome(linha);


	//Partido/Coliga��o
	getline(in, linha, ';');
	//cout << linha;
	//cout << " ";

	//votos
	getline(in, linha, ';');
	//convers�o de string para double
	istringstream (linha) >> numero;
	//cout << numero;
	//cout << " ";
	c.setVotos(numero);

	//validos
	getline(in, linha, '\n');
	//cout << linha;

	c.printCandidato();
	Candidato* k = &c;
	return k;

}

int main() {
	//leitura de arquivo
	ifstream in("test.txt");
	string linha;

	getline(in, linha); //linha lixo

	//sentinela
	CandidatoSentinel sentinel = CandidatoSentinel();


	//loop q ira ler o texto
	//o getline pode pegar os elementos at� o delimitador ';'
	while (getline(in, linha, ';')){
		//cout << "algo2";
		Candidato* k = retornaCandidato(in,linha);
		sentinel.addCandidato(k);
	}

	//cout << sentinel.getVagas() << endl;

	in.close();

	return 0;
}
