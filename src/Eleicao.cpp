/*
 * Eleicao.cpp
 *
 *  Created on: 2018/11/15
 *      Author: USER
 */

#include "Eleicao.h"

// FUNÇÕES AUXILIARES
bool comparaCandidatos(Candidato* a, Candidato* b){
	return a->getVotos() > b->getVotos();
}

bool comparaPartido(Partido* a, Partido* b){
	return a->getVotos() > b->getVotos();
}

bool comparaColigacao(Coligacao* a, Coligacao* b){
	return a->getVotos() > b->getVotos();
}


Eleicao::Eleicao(ifstream& in) {
	string lixo;

	getline(in, lixo); //linha lixo

	//loop q ira ler o texto
	//o getline pode pegar os elementos at�ｿｽ o delimitador ';'
	char peek = in.peek();
	while (peek != EOF){
		//coloca candidato na lista
		string entrada;
		getline(in, entrada);
		Candidato* c = new Candidato(entrada);
		adicionaPartidoColigacao(c, c->getPartidoColigacao());

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

int Eleicao::getVagas() const {
	return vagas;
}

void Eleicao::setVagas(){
	vagas = 0;
	for(Candidato* c : candidatos){
		if(c->getSituacao() == '*'){
			vagas++;
		}
	}
}

void Eleicao::adicionaPartido(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligação

	for(Partido* p : partidos){
		//se compare retornar 0 as strings sÃ£o iguais
		if(linha.compare(p->getNome()) == 0){
			p->setVotos(c->getVotos());
			if(c->getSituacao() == '*'){
				p->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			c->setPartido(p);
			return;//mata a função assim q a coligação for encontrada
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

void Eleicao::adicionaColigacao(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligação

	for(Coligacao* co : this->coligacoes){
		//se compare retornar 0 as strings sÃ£o iguais
		if(linha.compare(co->getNome()) == 0){
			co->setVotos(c->getVotos());

			if(c->getSituacao() == '*'){
				co->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			c->setColigacao(co);
			return;//mata a função assim q a coligação for encontrada
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

void Eleicao::adicionaPartidoColigacao(Candidato* c, string linha){
	unsigned split = linha.find(" - "); //string q separa partido de coligação

	if(split == string::npos){//"npos" é retornado quando o find
							  //nao encontra a o q procura

		adicionaPartido(c, linha);
		adicionaColigacao(c, linha);
	}
	else{
		//caso seja encontrada o split terï¿½ o valor da primeira posição da
		//string " - " logo tudo antes dela serï¿½ o partido em questÃ£o
		string partido = linha.substr(0, split);

		//cout << partido << endl;
		adicionaPartido(c, partido);

		string coligacao = linha.substr(split+3/*pula para o comeè¼Ÿ da coligacao*/, linha.size());

		adicionaColigacao(c, coligacao);

	}
}


string Eleicao::criaEleitos(){
	int cont = 0;
	string saida = "Vereadores eleitos:\n\n";
	for(Candidato* c : candidatos){
		if(c->getSituacao() == '*'){
			cont++;
			saida += std::to_string(cont) + " - ";
			saida += c->printCandidato();
		}

	}
	saida += "\n\n";

	return saida;
}

string Eleicao::criaMaisVotados(){
	this->maisVotados = candidatos;
	this->maisVotados.sort(comparaCandidatos);

	int cont = 0;
	string saida = "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):\n\n";

	for(Candidato* c : this->maisVotados){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += c->printCandidato();
		if( cont == vagas ) break;
	}
	saida += "\n\n";
	return saida;
}

string Eleicao::criaEleitosMajoritaria(){
	string saida = "Teriam sido eleitos se a votação fosse majoritÃ¡ria, e nÃ£o foram eleitos:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : maisVotados){
		cont++;
		saida += nFoiEleito(c, cont);

		if(cont == vagas) break;
	}

	saida += "\n\n";

	return saida;

}

string Eleicao::criaBeneficiados(){
	string saida = "Eleitos, que se beneficiaram do sistema proporcional:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : candidatos){
		cont++;
		saida += foiEleito(c);

		if(cont == vagas) break;
	}

	saida += "\n\n";

	return saida;

}


string Eleicao::nFoiEleito(Candidato* c, int posicao){
	int cont = 0;
	for(Candidato* can : candidatos){
		cont++;
		if(c->getNome().compare(can->getNome()) == 0){
			return "";
		}
		if(cont == vagas) break;
	}
	string saida = std::to_string(posicao) + " - ";
	saida += c->printCandidato();
	return saida;
}

string Eleicao::foiEleito(Candidato* c){
	int cont = 0;
	for(Candidato* can : maisVotados){
		cont++;

		if(cont >= vagas){
			if(c->getNome().compare(can->getNome()) == 0){
				string saida = std::to_string(cont) + " - ";
				saida += c->printCandidato();
				return saida;
			}
		}
	}

	return "";
}

string Eleicao::votacaoColigacao(){
	coligacoes.sort(comparaColigacao);

	int cont = 0;
	string saida = "Votação (nominal) das coligações e número de candidatos eleitos:\n\n";

	for(Coligacao* co : coligacoes){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += co->printColigacao();
	}
	saida += "\n\n";
	return saida;
}

string Eleicao::votacaoPartidos(){
	partidos.sort(comparaPartido);

	int cont = 0;
	string saida = "Votação (nominal) dos partidos e número de candidatos eleitos:\n\n";

	for(Partido* p : partidos){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += p->printPartido();
	}
	saida += "\n\n";
	return saida;

}

string Eleicao::totalNominais(){
	string saida = std::to_string(candidatos.size());
	return saida;
}




Eleicao::~Eleicao() {
	// TODO Auto-generated destructor stub
}
