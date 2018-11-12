/*
 * Candidato.h
 *
 *  Created on: 9 de nov de 2018
 *      Author: regata
 */

#ifndef CANDIDATO_H_
#define CANDIDATO_H_

#include <iostream>
#include <fstream>
#include <string>

#include "Partido.h"
#include "Coligacao.h"
using namespace std;

class Candidato {

private:
	//atributos
	char situacao;
	double num;
	std::string nome;
	Partido* partido;
	Coligacao* coligacao;
	double votos;
	Candidato* next;

public:
	//printa candidato
	string printCandidato();


	//SITUA��O
	void setSituacao(const std::string& colocacao);
	char getSituacao() const;

	//construtor e destrutor
	Candidato();
	virtual ~Candidato();

	//nome
	const std::string& getNome() const;
	void setNome(const std::string& nome);

	//num
	double getNum() const;
	void setNum(double num);


	//votos
	double getVotos() const;
	void setVotos(double votos);

	//next
	void setNext(Candidato*& next);
	Candidato*& getNext();

	//COLIGACAO
	Coligacao*& getColigacao();
	void setColigacao( Coligacao*& coligacao);

	//PARTIDO
	Partido*& getPartido();
	void setPartido(Partido*& partido);
};

#endif /* CANDIDATO_H_ */
