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

int Coligacao::getVotos() const {
	return votos;
}

void Coligacao::setVotos(int votos) {
	this->votos += votos;
}

string Coligacao::printColigacao(){
	string saida = "Coligação: ";
	saida += this->nome + ", ";
	saida += std::to_string(this->votos) + " votos, ";
	if(this->eleitos > 1){
		saida += std::to_string(this->eleitos) + " candidatos eleitos\n";
	}else{
		saida += std::to_string(this->eleitos) + " candidato eleito\n";
	}

	return saida;
}

Coligacao::~Coligacao() {
	// TODO Auto-generated destructor stub
}

