/*
 * Partido.cpp
 *
 *  Created on: 2018/11/11
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas TODO: Lembrar o nome do RegatX
 */

#include "Partido.h"

Partido::Partido(string& n) {
	nome = n;
	votos = 0;
	eleitos = 0;
}

// Getters e Setters
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

// Retorna a string referente ao modelo de impressão das informações de um partido
string Partido::printPartido(){
	string saida =  this->nome + ", ";
	saida += std::to_string(this->votos) + " votos, ";

	if(this->eleitos > 1){
			saida += std::to_string(this->eleitos) + " candidatos eleitos\n";
	}else{
		saida += std::to_string(this->eleitos) + " candidato eleito\n";
	}
	return saida;
}

// Compara o número de votos de dois partidos
bool Partido::comparaPartido(Partido* a, Partido* b){
	return a->getVotos() < b->getVotos();
}
