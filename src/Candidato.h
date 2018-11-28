/*
 * Candidato.h
 *
 *  Created on: 2018/11/09
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
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
	int num;
	std::string nome;
	Partido* partido;
	Coligacao* coligacao;
	int votos;
	string partidoColigacao;

public:
	Candidato(string& sit, int numero, string& name, string& partCol, int votes);

	// Getters e Setters
	void setSituacao(const std::string& colocacao);
	char getSituacao() const;
	const std::string& getNome() const;
	void setNome(const std::string& nome);
	int getNum() const;
	void setNum(int num);
	int getVotos() const;
	void setVotos(int votos);
	Coligacao*& getColigacao();
	void setColigacao( Coligacao*& coligacao);
	Partido*& getPartido();
	void setPartido( Partido*& partido);
	const string& getPartidoColigacao() const;
	void setPartidoColigacao(const string& partidoColigacao);

	// Recebe uma string referente a um número e converte para inteiro, retirando os pontos
	//     que representam as divisões de 10³
	int tiraPontos(string numString);
};

#endif /* CANDIDATO_H_ */
