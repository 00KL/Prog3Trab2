/*
 * Coligacao.cpp
 *
 *  Created on: 11 de nov de 2018
 *      Author: regata
 */

#include "Coligacao.h"

Coligacao::Coligacao(string& n){
	// TODO Auto-generated constructor stub
	//cout << n << endl;
	nome = n;
	votos = 0;
	eleitos = 0;
}

int Coligacao::getEleitos() const {
return eleitos;
}

void Coligacao::setEleitos(int eleitos) {
this->eleitos += eleitos;
}

const string& Coligacao::getNome() const {
return nome;
}

void Coligacao::setNome(const string& nome) {
this->nome = nome;
}

double Coligacao::getVotos() const {
return votos;
}
void Coligacao::setVotos(double votos) {
this->votos += votos;
}

string Coligacao::printColigacao(){
	string saida =  this->nome + ", ";
	saida += std::to_string(this->votos) + " votos, ";
	saida += std::to_string(this->eleitos) + " candidatos eleitos \n";
	return saida;
}

Coligacao::~Coligacao() {
	// TODO Auto-generated destructor stub
}

