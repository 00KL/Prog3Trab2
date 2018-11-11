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
	double votos;
	int eleitos;

public:
	int getEleitos() const;
	void setEleitos(int eleitos);
	const string& getNome() const;
	void setNome(const string& nome);
	double getVotos() const;
	void setVotos(double votos);

	void printColigacao();

	Coligacao(string& n);
	virtual ~Coligacao();
};

#endif /* COLIGACAO_H_ */
