/*
 * Saida.cpp
 *
 *  Created on: 2018/11/28
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include "Saida.h"

void Saida::imprimeEleicao(Eleicao& e) {
	string saida = "Número de vagas: " + std::to_string(e.getVagas()) + "\n\n";
	cout << saida;

	// Cria as strings referentes às listas de candidatos e imprime
	cout << criaEleitos(e);
	cout << criaMaisVotados(e);
	cout << criaEleitosMajoritaria(e);
	cout << criaBeneficiados(e);

	// Ordena as listas de partidos e coligações por votos, depois
	//     cria as strings referentes aos partidos e coligações e imprime
	cout << votacaoColigacao(e);
	cout << votacaoPartidos(e);

	// Define o número total de votos e imprime
	cout << totalNominais(e);
}

// Retorna a string referente ao modelo de impressão de um candidato
string Saida::imprimeCandidato(Candidato* c){
	string saida = c->getNome() + " ";
	saida += "(" + c->getPartido()->getNome() + ", " +  std::to_string(c->getVotos()) + " votos)";
	if(c->getColigacao()->getNome() != c->getPartido()->getNome() ){
		saida += " - Coligação: " + c->getColigacao()->getNome() + "\n";
	}
	else{
		saida += "\n";
	}

	return saida;
}

// Retorna a string referente ao modelo de impressão das informações de um partido
string Saida::imprimePartido(Partido* p){
	string saida =  p->getNome() + ", ";
	saida += std::to_string(p->getVotos()) + " votos, ";

	if(this->eleitos > 1){
			saida += std::to_string(p->getEleitos()) + " candidatos eleitos\n";
	}else{
		saida += std::to_string(p->getEleitos()) + " candidato eleito\n";
	}
	return saida;
}

// Retorna a string reeferente ao modelo de impressão das informações de uma coligação
string Saida::imprimeColigacao(Coligacao* col){
	string saida = col->getNome() + ", ";
	saida += std::to_string(col->getVotos()) + " votos, ";
	if(this->eleitos > 1){
		saida += std::to_string(col->getEleitos()) + " candidatos eleitos\n";
	}else{
		saida += std::to_string(col->getEleitos()) + " candidato eleito\n";
	}

	return saida;
}

// As funções abaixo tem a mesma funcionalidade, criar uma string referente a
//     alguma das listas especificadas para impressão

// Essa função cria a string referente à lista de candidatos eleitos
string Saida::criaEleitos(Eleicao& e){
	int cont = 0;
	string saida = "Vereadores eleitos:\n";
	for(Candidato* c : e.getCandidatos()){
		if(c->getSituacao() == '*'){
			cont++;
			saida += std::to_string(cont) + " - ";
			saida += imprimeCandidato(c);
		}
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos mais votados
string Saida::criaMaisVotados(Eleicao& e){
	maisVotados = e.getCandidatos();
	maisVotados.sort(comparaCandidato);

	int cont = 0;
	string saida = "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):\n";

	for(Candidato* c : maisVotados){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += imprimeCandidato(c);
		if( cont == e.getVagas() ) break;
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos que seriam eleitos caso
//     fosse usado o sistema de votos majoritário
string Saida::criaEleitosMajoritaria(Eleicao& e){
	string saida = "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : maisVotados){
		cont++;
		saida += nFoiEleito(e, c, cont);

		if(cont == e.getVagas()) break;
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos que não teriam sido eleitos
//     pelo sistema de votos majoritário
string Saida::criaBeneficiados(Eleicao& e){
	string saida = "Eleitos, que se beneficiaram do sistema proporcional:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : e.getCandidatos()){
		cont++;
		saida += foiEleito(e, c);

		if(cont == e.getVagas()) break;
	}
	saida += "\n";
	return saida;
}

// Checa se o candidato que está em maisVotados está em candidatos
string Saida::nFoiEleito(Eleicao& e, Candidato* c, int posicao){
	int cont = 0;
	for(Candidato* can : e.getCandidatos()){
		cont++;
		// Se o candidato estiver presente ums string vazia é retornada
		if(c->getNome().compare(can->getNome()) == 0){
			return "";
		}
		if(cont == e.getVagas()) break;
	}
	// Caso o candidato não tenhasito encontrado uma string é criada
	// com o número referente aquele candidato na lista de mais votados
	// e as informações do candidato em questão
	string saida = std::to_string(posicao) + " - ";
	saida += imprimeCandidato(c);
	return saida;
}

// Checa se o candidato que está em candidatos está em maisVotados
string Saida::foiEleito(Eleicao& e, Candidato* c){
	int cont = 0;
	for(Candidato* can : maisVotados){
		cont++;
		// Se o candidato estiver presente ums string vazia é retornada
		if(cont > e.getVagas()){
			if(c->getNome().compare(can->getNome()) == 0){
				// Caso o candidato não tenhasito encontrado uma string é criada
				// com o número referente aquele candidato na lista de mais votados
				// e as informações do candidato em questão
				string saida = std::to_string(cont) + " - ";
				saida += imprimeCandidato(c);
				return saida;
			}
		}
	}
	return "";
}

// Essa função retorna a string referente à impressão das coligações
string Saida::votacaoColigacao(list<Coligacao*> coligacoes){
	coligacoes.sort(comparaColigacao);

	int cont = 0;
	string saida = "Votação (nominal) das coligações e número de candidatos eleitos:\n";

	for(Coligacao* co : coligacoes){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += "Coligação: ";
		saida += imprimeColigacao(co);
	}
	saida += "\n";
	return saida;
}

// Essa função retorna a string referente à impressão dos partidos
string Saida::votacaoPartidos(list<Partido*> partidos){
	partidos.sort(comparaPartido);

	int cont = 0;
	string saida = "Votação (nominal) dos partidos e número de candidatos eleitos:\n";

	for(Partido* p : partidos){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += imprimePartido(p);
	}
	saida += "\n";
	return saida;

}

// Essa função retorna a string referente à impressão do total de votos nominais
string Saida::totalNominais(Eleicao& e){
	string saida = "Total de votos nominais: ";
	int total = 0;
	for(Candidato* c : e.getCandidatos()){
		total += c->getVotos();
	}

	saida += std::to_string(total) + "\n";
	return saida;
}

// FUNÇÕES AUXILIARES
bool Saida::comparaCandidato(Candidato* a, Candidato* b){
	return a->getVotos() > b->getVotos();
}

bool Saida::comparaPartido(Partido* a, Partido* b){
	return a->getVotos() > b->getVotos();
}

bool Saida::comparaColigacao(Coligacao* a, Coligacao* b){
	return a->getVotos() > b->getVotos();
}
