/*
 * CandidatoSentinel.cpp
 *
 *  Created on: 9 de nov de 2018
 *      Author: regata
 */

#include "CandidatoSentinel.h"

CandidatoSentinel::CandidatoSentinel() {
	// TODO Auto-generated constructor stub
	first = 0;
	last = 0;
	vagas = 0;
}

int CandidatoSentinel::getVagas() const {
	cout << "algo";
	return vagas;
}

void CandidatoSentinel::addCandidato(Candidato*& novo) {

//	string test = novo->getColocacao();
//	cout << test << endl;
//	if(test[0] == '*'){
//		this->vagas++;
//	}
	if(this->first == 0){
		this->first = this->last = novo;
	}
	else{
		this->last->setNext(novo);
		this->last = novo;
	}
}


CandidatoSentinel::~CandidatoSentinel() {
	// TODO Auto-generated destructor stub
}

