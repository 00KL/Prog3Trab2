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

//classes
#include "Candidato.h"
#include "Partido.h"
#include "Coligacao.h"

using namespace std;

//listas
list<Candidato*> candidatos;
list<Partido*> partidos;
list<Coligacao*> coligacoes;
string partidoColigacao;

void adicionaPartido(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligação

	for(Partido* p : partidos){
		//se compare retornar 0 as strings são iguais
		if(linha.compare(p->getNome()) == 0){
			p->setVotos(c->getVotos());
			if(c->getSituacao() == '*'){
				p->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			return;//mata a função assim q a coligação for encontrada
				   // e atualizada
		}
	}

	Partido* p = new Partido(linha);
	p->setVotos(c->getVotos());

	if(c->getSituacao() == '*'){
		p->setEleitos(1);
	}
	partidos.push_back(p);

}

void adicionaColigacao(Candidato* c, string linha){
	//caso tal string n tenhe sido encontrada o candidato n
	//esta em uma coligação

	for(Coligacao* co : coligacoes){
		//se compare retornar 0 as strings são iguais
		if(linha.compare(co->getNome()) == 0){
			co->setVotos(c->getVotos());

			if(c->getSituacao() == '*'){
				co->setEleitos(1);//adiciona um eleito ao contador de eleitos
			}

			return;//mata a função assim q a coligação for encontrada
				   // e atualizada
		}
	}

	Coligacao* co = new Coligacao(linha);
	co->setVotos(c->getVotos());

	if(c->getSituacao() == '*'){
		co->setEleitos(1);
	}
	coligacoes.push_back(co);


}

void splitPartidoColigacao(Candidato* c, string linha){
	int split = linha.find(" - "); //string q separa partido de coligação

	if(split == -1){
		adicionaPartido(c, linha);
		adicionaColigacao(c, linha);
	}
	else{
		//caso seja encontrada o split terá o valor da primeira posição da
		//string " - " logo tudo antes dela será o partido em questão
		string partido = linha.substr(0, split);
		//cout << partido << endl;
		adicionaPartido(c, partido);

		string coligacao = linha.substr(split+3/*pula para o começo da coligacao*/, linha.size());
		adicionaColigacao(c, coligacao);

	}


}

void adicionaCandidato(ifstream& in, string linha){
	Candidato *c = new Candidato();
	double numero;
	//Seq. (i);Núm.;Candidato;Partido/Coligação;Votação;% Válidos Formatação do texto
	//*0001;23123;FABRÍCIO GANDINI;PPS - PPS / PROS;7.611;4,21 %

	//colocação,  aprimeira linha já é pega pelo loop
	c->setSituacao(linha);

	//numero
	getline(in, linha, ';');
	//conversão de string para double
	istringstream (linha) >> numero;
	c->setNum(numero);

	//nome
	getline(in, linha, ';');
	c->setNome(linha);

	//Partido/Coligação
	getline(in, linha, ';');
	partidoColigacao = linha;

	//votos
	getline(in, linha, ';');
	//conversão de string para double
	istringstream (linha) >> numero;
	c->setVotos(numero);

	//validos
	getline(in, linha, '\n'); //não é utilizado para resolver o problema

	//Partido/Coligacao
	splitPartidoColigacao(c, partidoColigacao); //chamar essa função aqui, pois
												//os votos do candidato estão computados

	candidatos.push_back(c);

}

//Listas
string vagas(){
	int vagas = 0;
	for(Candidato* c : candidatos){
		if(c->getSituacao() == '*'){
			vagas++;
		}
	}

	string saida = "Número de vagas: " + std::to_string(vagas) + "\n";


	return saida;
}

int main() {
	//leitura de arquivo
	ifstream in("test.txt");
	string linha;

	getline(in, linha); //linha lixo

	//loop q ira ler o texto
	//o getline pode pegar os elementos até o delimitador ';'
	while (getline(in, linha, ';')){
		//coloca candidato na lista
		adicionaCandidato(in, linha);
	}

	cout << vagas();

	in.close();

	return 0;
}
