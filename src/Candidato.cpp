/*
 * Candidato.cpp
 *
 *  Created on: 2018/11/09
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas TODO: Lembrar o nome do RegatX
 */

#include "Candidato.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

Candidato::Candidato(string& entrada){

	// 			Modelo do Arquivo de Entrada
	// Seq. (i);Núm.;Candidato;Partido/Coligação;Votação;% Válidos
	// *0001;23123;FABRÍCIO GANDINI;PPS - PPS / PROS;7.611;4,21 %

	// Conversão de string para stringstream
	stringstream in(entrada);

	// String auxiliar de leitura
	string linha;

	// Define o primeiro caracter como a situação do candidato
	//     * ------------> significa eleito
	//     [um número] --> significa não eleito
	//     # ------------> significa que seus votos não foram validados
	getline(in, linha, ';');
	situacao = linha[0];

	// Lê o número do candidato como uma string e converte para inteiro
	getline(in, linha, ';');
	int numero;
	istringstream (linha) >> numero;
	num = numero;

	// Lê o nome do candidato
	getline(in, linha, ';');
	nome = linha;

	// Lê a string do partido e coligação
	getline(in, linha, ';');
	// Armazena essa string pra uso futuro, depois de definir os votos
	partidoColigacao = linha;
	// Define o partido e a coligação como NULL temporariamente
	partido = NULL;
	coligacao = NULL;

	// Lê o número de votos do candidato como uma string
	getline(in, linha, ';');
	// Retira os pontos da string e converte para inteiro
	int votosAux = tiraPontos(linha);
	votos = votosAux;

	// Lê a porcentagem de votos válidos do candidato
	//     inutilizado no problema
	getline(in, linha, '\n');
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

// Retorna a string referente ao modelo de impressão de um candidato
string Candidato::printCandidato(){
	string saida = nome + " ";
	saida += "(" + partido->getNome() + ", " +  std::to_string(votos) + " votos)";
	if(coligacao->getNome() != partido->getNome() ){
		saida += " - Coligação: " + coligacao->getNome() + "\n";
	}
	else{
		saida += "\n";
	}

	return saida;
}

// Recebe uma string referente a um número e converte para inteiro, retirando os pontos
//     que representam as divisões de 10³
int Candidato::tiraPontos(string numString) {

	// Define a variável "ponto" como a posição do primeiro ponto na string
	std::size_t ponto = numString.find(".");

	// Se algum ponto for encontrado na string
	while (ponto != string::npos) {

		// Apaga o ponto na string
		numString.erase(numString.begin()+ponto);

		// Procura se existe outro ponto na string
		//     (no caso de serem milhões de votos, por exemplo)
		ponto = numString.find(".");
	}

	// Converte a string sem os pontos para inteiro
	int numero;
	istringstream (numString) >> numero;

	return numero;
}
