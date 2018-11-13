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
	partido = NULL;
	coligacao = NULL;
	nome = "";
	votos = 0;
	next = NULL;
}

//printa candidato
string Candidato::printCandidato(){
	string saida = nome + " ";
	saida += "(" + partido->getNome() + ", " +  std::to_string(votos) + ") - ";
	saida += "Coligação: " + coligacao->getNome() + "\n";

	return saida;
}

//NOME
const std::string& Candidato::getNome() const {
	return nome;
}
void Candidato::setNome(const std::string& nome) {
	this->nome = nome;
}

//NUM
int Candidato::getNum() const {
	return num;
}
void Candidato::setNum(int num) {
	this->num = num;
}

//SITUAﾇﾃO
void Candidato::setSituacao(const std::string& colocacao) {
	this->situacao = colocacao[0];
}
char Candidato::getSituacao() const {
	return situacao;
}

Coligacao*& Candidato::getColigacao() {
	return coligacao;
}

void Candidato::setColigacao(Coligacao*& coligacao) {
	this->coligacao = coligacao;
}

Partido*& Candidato::getPartido() {
	return partido;
}

void Candidato::setPartido(Partido*& partido) {
	this->partido = partido;
}

//PROXIMO CANDIDATO
Candidato*& Candidato::getNext() {
	return this->next;
}
void Candidato::setNext(Candidato*& next) {
	this->next = next;
}

//VOTOS
int Candidato::getVotos() const {
	return votos;
}
void Candidato::setVotos(int votos) {
	this->votos = votos;
}

Candidato::~Candidato() {
	// TODO Auto-generated destructor stub
}

