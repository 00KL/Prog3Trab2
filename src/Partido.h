/*
 * Partido.h
 *
 *  Created on: 2018/11/11
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#ifndef PARTIDO_H_
#define PARTIDO_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Partido {
private:
	string nome;
	int votos;
	int eleitos;

public:
	Partido(string& nome);

	// Getters e Setters
	int getEleitos() const;
	void setEleitos(int eleitos);
	const string& getNome() const;
	void setNome(const string& nome);
	int getVotos() const;
	void setVotos(int votos);

	// Retorna a string referente ao modelo de impressão das informações de um partido
	string printPartido();

	// Compara o número de votos de dois partidos
	bool comparaPartido(Partido* a, Partido* b);
};

#endif /* PARTIDO_H_ */
