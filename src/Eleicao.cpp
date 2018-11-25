/*
 * Eleicao.cpp
 *
 *  Created on: 2018/11/15
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
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

	// A primeira linha do arquivo é um modelo e deve ser ignorado
	string lixo;
	getline(in, lixo);

	// Loop q ira ler o texto
	// Cria um caracter utilizado para verificar o EOF
	char peek = in.peek();

	// Enquanto o caracter não for o EOF
	while (peek != EOF){

		// Lê uma linha da entrada
		string entrada;
		getline(in, entrada);

		// Cria um candidato novo a partir dessa linha
		Candidato* c = new Candidato(entrada);

		// Organiza seu partido e coligação nas listas relevantes
		adicionaPartidoColigacao(c, c->getPartidoColigacao());

		// Insere o candidato na lista de candidatos
		candidatos.push_back(c);

		// Verifica o primeiro caracter da próxima linha
		peek = in.peek();
	}
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
void Eleicao::adicionaPartidoColigacao(Candidato* c, string linha){

	// Cria uma variável que recebe a posição do hífen que separa o partido e a coligação
	std::size_t split = linha.find("-");

	// Se não houver o hífen na string
	if(split == string::npos){

		// A string está na forma "[Partido]", então

		// A coligação do partido é ele mesmo, então ele é inserido nas duas funções
		adicionaPartido(c, linha);
		adicionaColigacao(c, linha);

	// Se houver hífen na string
	}else{
		// A string está na forma "[Partido] - [Coligação]", então
		         // split marca essa posição ^

		// O partido é a primeira parte da string, até o espaço antes do hífen
		string partido = linha.substr(0, split-1);
		adicionaPartido(c, partido);

		// A coligação é a segunda parte da string, depois do espaço após o hífen
		string coligacao = linha.substr(split+2, linha.size());
		adicionaColigacao(c, coligacao);
	}
}


// As funções abaixo tem a mesma funcionalidade, criar uma string referente a
//     alguma das listas especificadas para impressão

// Essa função cria a string referente à lista de candidatos eleitos
string Eleicao::criaEleitos(){
	int cont = 0;
	string saida = "Vereadores eleitos:\n";
	for(Candidato* c : candidatos){
		if(c->getSituacao() == '*'){
			cont++;
			saida += std::to_string(cont) + " - ";
			saida += c->printCandidato();
		}
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos mais votados
string Eleicao::criaMaisVotados(){
	this->maisVotados = candidatos;
	this->maisVotados.sort(comparaCandidatos);

	int cont = 0;
	string saida = "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):\n";

	for(Candidato* c : this->maisVotados){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += c->printCandidato();
		if( cont == vagas ) break;
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos que seriam eleitos caso
//     fosse usado o sistema de votos majoritário
string Eleicao::criaEleitosMajoritaria(){
	string saida = "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : maisVotados){
		cont++;
		saida += nFoiEleito(c, cont);

		if(cont == vagas) break;
	}
	saida += "\n";
	return saida;
}

// Essa função cria a string referente à lista de candidatos que não teriam sido eleitos
//     pelo sistema de votos majoritário
string Eleicao::criaBeneficiados(){
	string saida = "Eleitos, que se beneficiaram do sistema proporcional:\n";
	saida += "(com sua posição no ranking de mais votados)\n";
	int cont = 0;

	for(Candidato* c : candidatos){
		cont++;
		saida += foiEleito(c);

		if(cont == vagas) break;
	}
	saida += "\n";
	return saida;
}

// Checa se o candidato que está em maisVotados está em candidatos
string Eleicao::nFoiEleito(Candidato* c, int posicao){
	int cont = 0;
	for(Candidato* can : candidatos){
		cont++;
		// Se o candidato estiver presente ums string vazia é retornada
		if(c->getNome().compare(can->getNome()) == 0){
			return "";
		}
		if(cont == vagas) break;
	}
	// Caso o candidato não tenhasito encontrado uma string é criada
	// com o número referente aquele candidato na lista de mais votados
	// e as informações do candidato em questão
	string saida = std::to_string(posicao) + " - ";
	saida += c->printCandidato();
	return saida;
}

// Checa se o candidato que está em candidatos está em maisVotados
string Eleicao::foiEleito(Candidato* c){
	int cont = 0;
	for(Candidato* can : maisVotados){
		cont++;
		// Se o candidato estiver presente ums string vazia é retornada
		if(cont > vagas){
			if(c->getNome().compare(can->getNome()) == 0){
				// Caso o candidato não tenhasito encontrado uma string é criada
				// com o número referente aquele candidato na lista de mais votados
				// e as informações do candidato em questão
				string saida = std::to_string(cont) + " - ";
				saida += c->printCandidato();
				return saida;
			}
		}
	}
	return "";
}

// Essa função retorna a string referente à impressão das coligações
string Eleicao::votacaoColigacao(){
	coligacoes.sort(comparaColigacao);

	int cont = 0;
	string saida = "Votação (nominal) das coligações e número de candidatos eleitos:\n";

	for(Coligacao* co : coligacoes){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += "Coligação: ";
		saida += co->printColigacao();
	}
	saida += "\n";
	return saida;
}

// Essa função retorna a string referente à impressão dos partidos
string Eleicao::votacaoPartidos(){
	partidos.sort(comparaPartido);

	int cont = 0;
	string saida = "Votação (nominal) dos partidos e número de candidatos eleitos:\n";

	for(Partido* p : partidos){
		cont++;
		saida += std::to_string(cont) + " - ";
		saida += p->printPartido();
	}
	saida += "\n";
	return saida;

}

// Essa função retorna a string referente à impressão do total de votos nominais
string Eleicao::totalNominais(){
	string saida = "Total de votos nominais: ";
	int total = 0;
	for(Candidato* c : candidatos){
		total += c->getVotos();
	}

	saida += std::to_string(total) + "\n";
	return saida;
}
