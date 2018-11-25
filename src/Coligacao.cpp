/*
 * Coligacao.cpp
 *
 *  Created on: 2018/11/11
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include "Coligacao.h"

Coligacao::Coligacao(string& n){
	nome = n;
	votos = 0;
	eleitos = 0;
}

// Getters e Setters
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

// Retorna a string reeferente ao modelo de impressão das informações de uma coligação
string Coligacao::printColigacao(){
	string saida = this->nome + ", ";
	saida += std::to_string(this->votos) + " votos, ";
	if(this->eleitos > 1){
		saida += std::to_string(this->eleitos) + " candidatos eleitos\n";
	}else{
		saida += std::to_string(this->eleitos) + " candidato eleito\n";
	}

	return saida;
}
