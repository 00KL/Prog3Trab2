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
using namespace std;

class Candidato {

private:
	//atributos
	//char situacao;
	std::string colocacao;
	double num;
	std::string nome;
	//partido
	//coligacao
	double votos;
	Candidato* next;

public:
	//printa candidato
	void printCandidato();


	//
	const std::string& getColocacao() const;
	void setColocacao(const std::string& colocacao);

	//construtor e destrutor
	Candidato();
	virtual ~Candidato();

	//nome
	const std::string& getNome() const;
	void setNome(const std::string& nome);

	//num
	double getNum() const;
	void setNum(double num);

	//situação
	char getSituacao() const;
	void setSituacao(char situacao);

	//votos
	double getVotos() const;
	void setVotos(double votos);

	//next
	void setNext(Candidato*& next);
	Candidato*& getNext();
};

#endif /* CANDIDATO_H_ */
