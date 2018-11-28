/*
 * Coligacao.h
 *
 *  Created on: 2018/11/11
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
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
};

#endif /* COLIGACAO_H_ */
