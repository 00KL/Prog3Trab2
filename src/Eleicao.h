/*
 * Eleicao.h
 *
 *  Created on: 2018/11/15
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <locale>
using namespace std;

// Classes
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
	int vagas;

public:
	Eleicao();

	// Getters e Setters
	const list<Candidato*>& getCandidatos() const;
	const list<Coligacao*>& getColigacoes() const;
	const list<Partido*>& getPartidos() const;
	int getVagas() const;

	// Percorre a lista de candidatos e atualiza o número de vagas baseado no número
	//     de candidatos eleitos no arquivo de entrada
	void setVagas();

	// Arruma os partidos, coligações e contagem de vagas
	void partidoColigacaoVagas();
	// Adiciona um partido a partir de uma string em um candidato e na lista de partidos
	void adicionaPartido(Candidato*, string);
	// Adiciona uma coligação a partir de uma string em um candidato e na lista de coligações
	void adicionaColigacao(Candidato*, string);
	// Divide a string referente ao partido e coligação e chama as funções adicionaPartido e
	// 	   adicionaColigacao para adicioná-los no candidato e nas listas
	void adicionaPartidoColigacao(Candidato*);
	// Adiciona um candidato na lista de candidatos
	void adicionaCandidato(Candidato*);

	~Eleicao();
};

#endif /* ELEICAO_H_ */
