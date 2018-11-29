/*
 * Saida.h
 *
 *  Created on: 2018/11/28
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

#include "Eleicao.h"

#ifndef SAIDA_H_
#define SAIDA_H_

class Saida {
private:
	list<Candidato*> eleitos;
	list<Candidato*> maisVotados;
	
public:
	// Faz a impressão geral de toda a Eleição, baseado nos modelos especificados
	void imprimeEleicao(Eleicao&);

	// Retorna a string referente ao modelo de impressão da classe
	string imprimeCandidato(Candidato*);
	string imprimePartido(Partido*);
	string imprimeColigacao(Coligacao*);

	// Cria as strings referentes às listas de candidatos e imprime
	string criaEleitos(Eleicao&);
	string criaMaisVotados(Eleicao&);
	string criaEleitosMajoritaria(Eleicao&);
	string criaBeneficiados(Eleicao&);

	// Funções auxiliares para a criação das listas acima
	string nFoiEleito(Eleicao&, Candidato*, int);
	string foiEleito(Eleicao&, Candidato*);

	// Cria as strings referentes aos partidos e coligações e imprime
	// Essas funções recebem cópias das listas já que elas tem que ser ordenadas
	string votacaoColigacao(list<Coligacao*>);
	string votacaoPartidos(list<Partido*>);

	// Define o número total de votos e imprime
	string totalNominais(Eleicao&);
};

#endif /* SAIDA_H_ */
