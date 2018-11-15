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
	partidos.push_back(p);
	c->setPartido(p);

}

void adicionaColigacao(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligaÃ§Ã£o

	for(Coligacao* co : coligacoes){
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
	coligacoes.push_back(co);
	c->setColigacao(co);


}

void splitPartidoColigacao(Candidato* c, string linha){
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



	getline(in, linha); //linha lixo

	//loop q ira ler o texto
	//o getline pode pegar os elementos atï¿½ o delimitador ';'
	char peek = in.peek();
	while (peek != EOF){
		//coloca candidato na lista
		//adicionaCandidato(in, linha);
		getline(in, linha);
		Candidato* c = new Candidato(linha);
		splitPartidoColigacao(c, c->getPartidoColigacao());
		candidatos.push_back(c);

		peek = in.peek();
	}

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
