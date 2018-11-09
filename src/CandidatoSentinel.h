/*
 * CandidatoSentinel.h
 *
 *  Created on: 9 de nov de 2018
 *      Author: regata
 */

#ifndef CANDIDATOSENTINEL_H_
#define CANDIDATOSENTINEL_H_

#include "Candidato.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CandidatoSentinel {
friend class Candidato;
private:
	Candidato* first;
	Candidato* last;
	int vagas;

public:
	CandidatoSentinel();
	virtual ~CandidatoSentinel();

	//
	void addCandidato(Candidato*& novo);
	
	//ordenações
	int getVagas() const;
};

#endif /* CANDIDATOSENTINEL_H_ */
