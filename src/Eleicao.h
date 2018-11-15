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
	Eleicao(ifstream&);
	virtual ~Eleicao();
	const list<Candidato*>& getCandidatos() const;
	void setCandidatos(const list<Candidato*>&);
	const list<Coligacao*>& getColigacoes() const;
	void setColigacoes(const list<Coligacao*>&);
	const list<Partido*>& getPartidos() const;
	void setPartidos(const list<Partido*>&);

	void adicionaPartido(Candidato*, string);
	void adicionaColigacao(Candidato*, string);
	void adicionaPartidoColigacao(Candidato*, string);
};

#endif /* ELEICAO_H_ */
