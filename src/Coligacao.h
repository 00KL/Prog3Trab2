/*
 * Coligacao.h
 *
 *  Created on: 11 de nov de 2018
 *      Author: regata
 */

#ifndef COLIGACAO_H_
#define COLIGACAO_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Coligacao {
private:
	string nome;
	int votos;
	int eleitos;

public:
	Coligacao(string& n);

	// Getters e Setters
	int getEleitos() const;
	void setEleitos(int eleitos);
	const string& getNome() const;
	void setNome(const string& nome);
	int getVotos() const;
	void setVotos(int votos);

	// Retorna a string reeferente ao modelo de impressão das informações de uma coligação
	string printColigacao();
};

#endif /* COLIGACAO_H_ */
