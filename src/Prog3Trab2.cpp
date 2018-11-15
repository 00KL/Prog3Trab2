//============================================================================
// Name        : Prog3Trab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <locale>
using namespace std;

//classes
#include "Candidato.h"
#include "Partido.h"
#include "Coligacao.h"

//Variaveis Globais
list<Candidato*> candidatos;
list<Candidato*> candidatosMaisVotados;

list<Partido*> partidos;
list<Coligacao*> coligacoes;

string partidoColigacao;
int vagas;






//Listas
void setVagas(){
	vagas = 0;
	for(Candidato* c : candidatos){
		if(c->getSituacao() == '*'){
			vagas++;
		}
	}
}

string eleitos(){
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

bool comparaCandidatos(Candidato* a, Candidato* b){
	return a->getVotos() > b->getVotos();
}

string maisVotados(){
	candidatosMaisVotados = candidatos;
	candidatosMaisVotados.sort(comparaCandidatos);

	int cont = 0;
	string saida = "Candidatos mais votados (em ordem decrescente de votaÃ§Ã£o e respeitando nÃºmero de vagas):\n\n";

	for(Candidato* c : candidatosMaisVotados){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += c->printCandidato();
		if( cont == vagas ) break;
	}
	saida += "\n\n";
	return saida;
}

string nFoiEleito(Candidato* c, int posicao){
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

string majoritaria(){
	string saida = "Teriam sido eleitos se a votaÃ§Ã£o fosse majoritÃ¡ria, e nÃ£o foram eleitos:\n";
	saida += "(com sua posiÃ§Ã£o no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : candidatosMaisVotados){
		cont++;
		saida += nFoiEleito(c, cont);

		if(cont == vagas) break;
	}

	saida += "\n\n";

	return saida;

}

string foiEleito(Candidato* c){
	int cont = 0;
	for(Candidato* can : candidatosMaisVotados){
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

string beneficiados(){
	string saida = "Eleitos, que se beneficiaram do sistema proporcional:\n";
	saida += "(com sua posiÃ§Ã£o no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : candidatos){
		cont++;
		saida += foiEleito(c);

		if(cont == vagas) break;
	}

	saida += "\n\n";

	return saida;

}

bool comparaColigacao(Coligacao* a, Coligacao* b){
	return a->getVotos() > b->getVotos();
}

string votacaoColigacao(){
	coligacoes.sort(comparaColigacao);

	int cont = 0;
	string saida = "VotaÃ§Ã£o (nominal) das coligaÃ§Ãµes e nÃºmero de candidatos eleitos:\n\n";

	for(Coligacao* co : coligacoes){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += co->printColigacao();
	}
	saida += "\n\n";
	return saida;
}

bool comparaPartido(Partido* a, Partido* b){
	return a->getVotos() > b->getVotos();
}

string votacaoPartidos(){
	partidos.sort(comparaPartido);

	int cont = 0;
	string saida = "VotaÃ§Ã£o (nominal) dos partidos e nÃºmero de candidatos eleitos:\n\n";

	for(Partido* p : partidos){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += p->printPartido();
	}
	saida += "\n\n";
	return saida;

}

string totalNominais(){
	string saida = std::to_string(candidatos.size());
	return saida;
}

int main() {
	//leitura de arquivo
	ifstream in("test.txt");

	//std::locale mylocale("C");   // get global locale
	//std::ifstream.imbue(mylocale);
	//in.imbue(mylocale);
	//setlocale(LC_ALL, "pt_BR.utf8");

	string linha;



	Eleicao e = new Eleicao(in);

	setVagas();
	string saida = "NÃºmero de vagas: " + std::to_string(vagas) + "\n\n";
	cout << saida;

	cout << eleitos();
	cout << maisVotados();
	cout << majoritaria();
	cout << beneficiados();

	cout << votacaoColigacao();
	cout << votacaoPartidos();

	cout << totalNominais();

	in.close();

//	int i;
//	while(1) {
//		i = 0;
//	}

	return 0;
}
