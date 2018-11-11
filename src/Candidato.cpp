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
	situacao = '0';
	num = 0;
	nome = "";
	//partido
	//coligacao
	votos = 0;
	next = NULL;
}

//printa candidato
void Candidato::printCandidato(){
	//cout << colocacao << " ";
	cout << num << " ";
	cout << nome << " ";
	cout << votos << "\n";
}

//NOME
const std::string& Candidato::getNome() const {
	return nome;
}
void Candidato::setNome(const std::string& nome) {
	this->nome = nome;
}

//NUM
double Candidato::getNum() const {
	return num;
}
void Candidato::setNum(double num) {
	this->num = num;
}

//SITUAÇÃO
void Candidato::setSituacao(const std::string& colocacao) {
	this->situacao = colocacao[0];
}
char Candidato::getSituacao() const {
	return situacao;
}

//PROXIMO CANDIDATO
Candidato*& Candidato::getNext() {
	return this->next;
}
void Candidato::setNext(Candidato*& next) {
	this->next = next;
}

//VOTOS
double Candidato::getVotos() const {
	return votos;
}
void Candidato::setVotos(double votos) {
	this->votos = votos;
}

Candidato::~Candidato() {
	// TODO Auto-generated destructor stub
}

