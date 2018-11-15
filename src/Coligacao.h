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
#include <list>
using namespace std;

#include "Candidato.h"
#include "Partido.h"

class Coligacao {
private:
	string nome;
	int votos;
	int eleitos;
	list<Partido*> partidos;
	list<Candidato*> candidatos;

public:
	int getEleitos() const;
	void setEleitos(int eleitos);

	const string& getNome() const;
	void setNome(const string& nome);

	int getVotos() const;
	void setVotos(int votos);

	string printColigacao();

	void adicionaPartido(Partido* p);
	void adicionaCandidato(Candidato* c);

	Coligacao(string& n);
	virtual ~Coligacao();
};

#endif /* COLIGACAO_H_ */
