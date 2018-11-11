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
	double votos;
	int eleitos;

public:
	Partido(string& nome);
	virtual ~Partido();

	int getEleitos() const;
	void setEleitos(int eleitos);

	const string& getNome() const;
	void setNome(const string& nome);

	double getVotos() const;
	void setVotos(double votos);

	string printPartido();

};

#endif /* PARTIDO_H_ */
