/*
 * Partido.cpp
 *
 *  Created on: 11 de nov de 2018
 *      Author: regata
 */

#include "Partido.h"

Partido::Partido(string& n) {
	// TODO Auto-generated constructor stub
	nome = n;
	votos = 0;
	eleitos = 0;
}

int Partido::getEleitos() const {
	return eleitos;
}

void Partido::setEleitos(int eleitos) {
	this->eleitos += eleitos;
}

const string& Partido::getNome() const {
	return nome;
}

void Partido::setNome(const string& nome) {
	this->nome = nome;
}

int Partido::getVotos() const {
	return votos;
}

void Partido::setVotos(int votos) {
	this->votos += votos;
}

void Partido::adicionaCandidato(Candidato* c) {
	this->candidatos.push_back(c);
	this->votos += c->getVotos();
	if (c->getSituacao() == '*') {
		this->eleitos++;
	}
}

string Partido::printPartido(){
	string saida =  this->nome + ", ";
	saida += std::to_string(this->votos) + " votos, ";
	saida += std::to_string(this->eleitos) + " candidatos eleitos \n";
	return saida;
}

bool Partido::comparaPartido(Partido* a, Partido* b){
	return a->getVotos() < b->getVotos();
}

Partido::~Partido() {
	// TODO Auto-generated destructor stub
}

