/*
 * Entrada.h
 *
 *  Created on: 2018/11/27
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
#include "Eleicao.h"

#ifndef ENTRADA_H_
#define ENTRADA_H_

class Entrada {
private:
	// Recebe uma string referente a um número e converte para inteiro, retirando os pontos
	//     que representam as divisões de 10³
	int tiraPontos(string&);
public:
	void leEntrada(ifstream&, Eleicao&);
	Candidato* criaCandidato(string&);



};


#endif /* ENTRADA_H_ */
