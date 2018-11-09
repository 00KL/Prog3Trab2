/*
 * Candidato.cpp
 *
 *  Created on: 9 de nov de 2018
 *      Author: regata
 */

#include "Candidato.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Candidato::Candidato(){
	colocacao = " ";
	num = 0;
	nome = "";
	//partido
	//coligacao
	votos = 0;
	next = NULL;
}

//printa candidato
void Candidato::printCandidato(){
	cout << colocacao << " ";
	cout << num << " ";
	cout << nome << " ";
	cout << votos << "\n";
}


const std::string& Candidato::getNome() const {
	return nome;
}

void Candidato::setNome(const std::string& nome) {
	this->nome = nome;
}

double Candidato::getNum() const {
	return num;
}

void Candidato::setNum(double num) {
	this->num = num;
}


double Candidato::getVotos() const {
	return votos;
}

const std::string& Candidato::getColocacao() const {
	return colocacao;
}

void Candidato::setColocacao(const std::string& colocacao) {
	this->colocacao = colocacao;
}

Candidato*& Candidato::getNext() {
	return this->next;
}

void Candidato::setNext(Candidato*& next) {
	this->next = next;
}

void Candidato::setVotos(double votos) {
	this->votos = votos;
}

Candidato::~Candidato() {
	// TODO Auto-generated destructor stub
}

