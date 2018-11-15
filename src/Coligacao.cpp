/*
 * Coligacao.cpp
 *
 *  Created on: 11 de nov de 2018
 *      Author: regata
 */

#include "Coligacao.h"

Coligacao::Coligacao(string& n){
	this->nome = n;
	this->votos = 0;
	this->eleitos = 0;
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

int Coligacao::getVotos() const {
	return votos;
}

void Coligacao::setVotos(int votos) {
	this->votos += votos;
}

void Coligacao::adicionaCandidato(Candidato* c) {
	this->candidatos.push_back(c);
	this->votos += c->getVotos();
	if (c->getSituacao() == '*') {
		this->eleitos++;
	}
	this->partidos.push_back(c->getPartido());
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

