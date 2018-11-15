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

#include "Partido.h"
#include "Coligacao.h"

class Candidato {

private:
	//atributos
	char situacao;
	int num;
	std::string nome;
	Partido* partido;
	Coligacao* coligacao;
	int votos;
	Candidato* next;
	string partidoColigacao;

public:
	//printa candidato
	string printCandidato();


	//SITUA��O
	void setSituacao(const std::string& colocacao);
	char getSituacao() const;

	//construtor e destrutor
	Candidato(string& linha);
	virtual ~Candidato();

	//nome
	const std::string& getNome() const;
	void setNome(const std::string& nome);

	//num
	int getNum() const;
	void setNum(int num);


	//votos
	int getVotos() const;
	void setVotos(int votos);

	//next
//	void setNext(Candidato*& next);
//	Candidato*& getNext();

	//COLIGACAO
	Coligacao*& getColigacao();
	void setColigacao( Coligacao*& coligacao);

	//PARTIDO
	 Partido*& getPartido();
	void setPartido( Partido*& partido);

	//EXTRAS
	int tiraPontos(string numString);
	const string& getPartidoColigacao() const;
	void setPartidoColigacao(const string& partidoColigacao);
};

#endif /* CANDIDATO_H_ */
