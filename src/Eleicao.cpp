/*
 * Eleicao.cpp
 *
 *  Created on: 2018/11/15
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include "Eleicao.h"

Eleicao::Eleicao() {
	vagas = 0;
}

// Getters (só o getVagas() é utilizado no código)
const list<Candidato*>& Eleicao::getCandidatos() const {
	return candidatos;
}
const list<Coligacao*>& Eleicao::getColigacoes() const {
	return coligacoes;
}
const list<Partido*>& Eleicao::getPartidos() const {
	return partidos;
}
int Eleicao::getVagas() const {
	return vagas;
}

// Percorre a lista de candidatos e atualiza o número de vagas baseado no número
//     de candidatos eleitos no arquivo de entrada
void Eleicao::setVagas(){
	vagas = 0;

	// Para cada candidato eleito na lista inicial
	for(Candidato* c : candidatos){

		// Adiciona um no limite de vagas
		if(c->getSituacao() == '*'){
			vagas++;
		}
	}
}

// Arruma os partidos, coligações e contagem de vagas
void Eleicao::partidoColigacaoVagas() {

	// Organiza os partidos e coligações nas listas
	for (Candidato* c : candidatos) {
		adicionaPartidoColigacao(c);
	}

	// Define o número de vagas
	setVagas();
}

// Adiciona um partido a partir de uma string em um candidato e na lista de partidos
void Eleicao::adicionaPartido(Candidato* c, string linha){

	// Percorre a lista de partidos
	for(Partido* p : partidos){
		// Verifica se o partido a ser inserido já está na lista
		if(linha.compare(p->getNome()) == 0){
			// Se sim,

			// Adiciona no partido os votos do candidato
			p->setVotos(c->getVotos());

			// Se o candidato tiver sido eleito, aumenta os eleitos do partido em 1
			if(c->getSituacao() == '*'){
				p->setEleitos(1);
			}

			// Adiciona esse partido nas informações do candidato
			c->setPartido(p);

			// Encerra a função
			return;
		}
	}

	// Caso o partido não esteja na lista, ele deve ser criado a partir da string
	Partido* p = new Partido(linha);

	// E suas informações atualizadas com as informações do candidato, como acima
	p->setVotos(c->getVotos());

	if(c->getSituacao() == '*'){
		p->setEleitos(1);
	}

	// Então, o partido é inserido na lista de partidos
	this->partidos.push_back(p);

	// E colocado nas informações do candidato
	c->setPartido(p);
}


// Adiciona uma coligação a partir de uma string em um candidato e na lista de coligações
void Eleicao::adicionaColigacao(Candidato* c, string linha){

	// Percorre a lista de coligações
	for(Coligacao* co : this->coligacoes){

		// Verifica se a coligação a ser inserida já está na lista
		if(linha.compare(co->getNome()) == 0){
			// Se sim,

			// Adiciona os votos do candidato na coligação
			co->setVotos(c->getVotos());

			// Se o candidato tiver sido eleito, aumenta os eleitos da coligação em 1
			if(c->getSituacao() == '*'){
				co->setEleitos(1);
			}

			// Depois insere a coligação nas informações do candidato
			c->setColigacao(co);

			// E encerra a função
			return;
		}
	}

	// Caso a coligação não exista na lista, ela deve ser criada a partir da string
	Coligacao* co = new Coligacao(linha);

	// Então os votos do candidato são adicionados à coligação
	co->setVotos(c->getVotos());

	// Se o candidato tiver sido eleito, a coligação começa com um eleito
	if(c->getSituacao() == '*'){
		co->setEleitos(1);
	}

	// A coligação é adicionada na lista de coligações
	this->coligacoes.push_back(co);

	// E adicionada nas informações do candidato
	c->setColigacao(co);
}


// Divide a string referente ao partido e coligação e chama as funções adicionaPartido e
// 	   adicionaColigacao para adicioná-los no candidato e nas listas
void Eleicao::adicionaPartidoColigacao(Candidato* c){

	string partidoColigacao = c->getPartidoColigacao();

	// Cria uma variável que recebe a posição do hífen que separa o partido e a coligação
	std::size_t split = partidoColigacao.find("-");

	// Se não houver o hífen na string
	if(split == string::npos){

		// A string está na forma "[Partido]", então

		// A coligação do partido é ele mesmo, então ele é inserido nas duas funções
		adicionaPartido(c, partidoColigacao);
		adicionaColigacao(c, partidoColigacao);

	// Se houver hífen na string
	}else{
		// A string está na forma "[Partido] - [Coligação]", então
		         // split marca essa posição ^

		// O partido é a primeira parte da string, até o espaço antes do hífen
		string partido = partidoColigacao.substr(0, split-1);
		adicionaPartido(c, partido);

		// A coligação é a segunda parte da string, depois do espaço após o hífen
		string coligacao = partidoColigacao.substr(split+2, partidoColigacao.size());
		adicionaColigacao(c, coligacao);
	}
}

Eleicao::~Eleicao(){
	for(Candidato* c : candidatos){
		delete c;
	}
	for(Partido* p : partidos){
		delete p;
	}
	for(Coligacao* ca : coligacoes){
		delete ca;
	}
}


