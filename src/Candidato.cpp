/*
 * Candidato.cpp
 *
 *  Created on: 2018/11/09
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include "Candidato.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

Candidato::Candidato(string& sit, int numero, string& name, string& partCol, int votes){
	situacao = sit;
	num = numero;
	nome = name;
	partidoColigacao = partCol;
	votos = votes;

	partido = NULL;
	coligacao = NULL;
}

// Getters e Setters
const std::string& Candidato::getNome() const {
	return nome;
}
void Candidato::setNome(const std::string& nome) {
	this->nome = nome;
}
int Candidato::getNum() const {
	return num;
}
void Candidato::setNum(int num) {
	this->num = num;
}
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
void Candidato::setPartido( Partido*& partido) {
	this->partido = partido;
}
int Candidato::getVotos() const {
	return votos;
}
void Candidato::setVotos(int votos) {
	this->votos = votos;
}
const string& Candidato::getPartidoColigacao() const {
	return partidoColigacao;
}
void Candidato::setPartidoColigacao(const string& partidoColigacao) {
	this->partidoColigacao = partidoColigacao;
}
