/*
 * Partido.cpp
 *
 *  Created on: 2018/11/11
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
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


