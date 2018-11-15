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
	//o getline pode pegar os elementos at�ｿｽ o delimitador ';'
	char peek = in.peek();
	while (peek != 'EOF'){
		//coloca candidato na lista
		string entrada;
		getline(in, entrada);
		Candidato* c = new Candidato(entrada);
		adicionaPartidoColigacao(c, c->partidoColigacao);

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

void adicionaPartido(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligaÃ§Ã£o

	for(Partido* p : partidos){
		//se compare retornar 0 as strings sÃ£o iguais
		if(linha.compare(p->getNome()) == 0){
			p->setVotos(c->getVotos());
			if(c->getSituacao() == '*'){
				p->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			c->setPartido(p);
			return;//mata a funÃ§Ã£o assim q a coligaÃ§Ã£o for encontrada
				   // e atualizada
		}
	}

	Partido* p = new Partido(linha);
	p->setVotos(c->getVotos());

	if(c->getSituacao() == '*'){
		p->setEleitos(1);
	}
	this->partidos.push_back(p);
	c->setPartido(p);

}

void adicionaColigacao(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligaÃ§Ã£o

	for(Coligacao* co : this->coligacoes){
		//se compare retornar 0 as strings sÃ£o iguais
		if(linha.compare(co->getNome()) == 0){
			co->setVotos(c->getVotos());

			if(c->getSituacao() == '*'){
				co->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			c->setColigacao(co);
			return;//mata a funÃ§Ã£o assim q a coligaÃ§Ã£o for encontrada
				   // e atualizada
		}
	}

	Coligacao* co = new Coligacao(linha);
	co->setVotos(c->getVotos());

	if(c->getSituacao() == '*'){
		co->setEleitos(1);
	}
	this->coligacoes.push_back(co);
	c->setColigacao(co);


}

void adicionaPartidoColigacao(Candidato* c, string linha){
	unsigned split = linha.find(" - "); //string q separa partido de coligaÃ§Ã£o

	if(split == string::npos){//"npos" é retornado quando o find
							  //nao encontra a o q procura

		adicionaPartido(c, linha);
		adicionaColigacao(c, linha);
	}
	else{
		//caso seja encontrada o split terï¿½ o valor da primeira posiÃ§Ã£o da
		//string " - " logo tudo antes dela serï¿½ o partido em questÃ£o
		string partido = linha.substr(0, split);

		//cout << partido << endl;
		adicionaPartido(c, partido);

		string coligacao = linha.substr(split+3/*pula para o comeè¼Ÿ da coligacao*/, linha.size());

		adicionaColigacao(c, coligacao);

	}
}

Eleicao::~Eleicao() {
	// TODO Auto-generated destructor stub
}
