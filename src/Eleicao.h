/*
 * Eleicao.h
 *
 *  Created on: 2018/11/15
 *      Author: USER
 */

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

#ifndef ELEICAO_H_
#define ELEICAO_H_

class Eleicao {
private:
	list<Candidato*> candidatos;
	list<Partido*> partidos;
	list<Coligacao*> coligacoes;

	list<Candidato*> eleitos;
	list<Candidato*> maisVotados;
	list<Candidato*> eleitosMajoritaria;
	list<Candidato*> beneficiados;
public:
	Eleicao();
	virtual ~Eleicao();
	const list<Candidato*>& getCandidatos() const;
	void setCandidatos(const list<Candidato*>& candidatos);
	const list<Coligacao*>& getColigacoes() const;
	void setColigacoes(const list<Coligacao*>& coligacoes);
	const list<Partido*>& getPartidos() const;
	void setPartidos(const list<Partido*>& partidos);
};

#endif /* ELEICAO_H_ */
