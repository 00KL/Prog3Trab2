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
#include <list>
#include <sstream>
using namespace std;

Candidato::Candidato(string& entrada){
	//Seq. (i);NÃºm.;Candidato;Partido/ColigaÃ§Ã£o;VotaÃ§Ã£o;% Vç–�idos FormataÃ§Ã£o do texto
	//*0001;23123;FABRï¾�CIO GANDINI;PPS - PPS / PROS;7.611;4,21 %
	stringstream in(entrada);
	string linha;
	//colocaÃ§Ã£o,  aprimeira linha jï¿½ ï¿½ pega pelo loop
	getline(in, linha, ';');
	situacao = linha[0];

	//numero
	getline(in, linha, ';');
	int numero;
	istringstream (linha) >> numero;
	num = numero;

	//nome
	getline(in, linha, ';');
	nome = linha;

	//Partido/ColigaÃ§Ã£o
	getline(in, linha, ';');
	partidoColigacao = linha;
	partido = NULL;
	coligacao = NULL;

	//votos
	getline(in, linha, ';');
	//conversÃ£o de string para int
	int votosAux = tiraPontos(linha);
	votos = votosAux;

	//validos
	getline(in, linha, '\n'); //nÃ£o ï¿½ utilizado para resolver o problema

	//Partido/Coligacao
	//splitPartidoColigacao(c, partidoColigacao); //chamar essa funÃ§Ã£o aqui, pois
												//os votos do candidato estÃ£o computados


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

//SITUAï¾‡ï¾ƒO
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

//PROXIMO CANDIDATO
//Candidato*& Candidato::getNext() {
//	return this->next;
//}
//void Candidato::setNext(Candidato*& next) {
//	this->next = next;
//}

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

const string& Candidato::getPartidoColigacao() const {
	return partidoColigacao;
}

void Candidato::setPartidoColigacao(const string& partidoColigacao) {
	this->partidoColigacao = partidoColigacao;
}

//EXTRAS
int Candidato::tiraPontos(string numString) {
	unsigned ponto = numString.find(".");
	while (ponto != string::npos) {
		numString.erase(ponto, ponto);
		ponto = numString.find(".");
	}


	//conversÃ£o de string para double
	int numero;
	istringstream (numString) >> numero;
	return numero;
}
