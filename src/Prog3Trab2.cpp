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


using namespace std;

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//leitura de arquivo
	ifstream in("test.txt");
	string linha;
	double numero;
	getline(in, linha); //linha lixo
	while (getline(in, linha, ';')){
		//Seq. (i);N�m.;Candidato;Partido/Coliga��o;Vota��o;% V�lidos
		//coloca��o
		cout << linha;
		cout << " ";

		//numero
		getline(in, linha, ';');
		//convers�o de string para double
		istringstream (linha) >> numero;
		cout << numero;
		cout << " ";

		//nome
		getline(in, linha, ';');
		cout << linha;
		cout << " ";


		//Partido/Coliga��o
		getline(in, linha, ';');
		cout << linha;
		cout << " ";

		//votos
		getline(in, linha, ';');
		//convers�o de string para double
		istringstream (linha) >> numero;
		cout << numero;

		cout << " ";

		//validos
		getline(in, linha, '\n');
		cout << linha;

		cout << endl;


	}
	in.close();

	return 0;
}
