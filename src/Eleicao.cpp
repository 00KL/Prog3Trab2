/*
 * Eleicao.cpp
 *
 *  Created on: 2018/11/15
 *      Author: USER
 */

#include "Eleicao.h"

Eleicao::Eleicao(ifstream& in) {
	string lixo;

	getline(in, lixo); //linha lixo

	//loop q ira ler o texto
	//o getline pode pegar os elementos at� o delimitador ';'
	char peek = in.peek();
	while (peek != 'EOF'){
		//coloca candidato na lista
		string entrada;
		getline(in, entrada);
		Candidato* c = new Candidato(entrada);
		adicionaPartidoEColigacao(c, c->partidoColigacao);

		candidatos.push_back(c);
		peek = in.peek();
	}

}

const list<Candidato*>& Eleicao::getCandidatos() const {
	return candidatos;
}

void Eleicao::setCandidatos(const list<Candidato*>& candidatos) {
	this->candidatos = candidatos;
}

const list<Coligacao*>& Eleicao::getColigacoes() const {
	return coligacoes;
}

void Eleicao::setColigacoes(const list<Coligacao*>& coligacoes) {
	this->coligacoes = coligacoes;
}

const list<Partido*>& Eleicao::getPartidos() const {
	return partidos;
}

void Eleicao::setPartidos(const list<Partido*>& partidos) {
	this->partidos = partidos;
}

Eleicao::~Eleicao() {
	// TODO Auto-generated destructor stub
}
