/*
 * Partido.h
 *
 *  Created on: 11 de nov de 2018
 *      Author: regata
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
	virtual ~Partido();

	int getEleitos() const;
	void setEleitos(int eleitos);

	const string& getNome() const;
	void setNome(const string& nome);

	int getVotos() const;
	void setVotos(int votos);

	string printPartido();

	bool comparaPartido(Partido* a, Partido* b);

};

#endif /* PARTIDO_H_ */
