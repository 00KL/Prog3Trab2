/*
 * Entrada.cpp
 *
 *  Created on: 2018/11/27
 *      Author: Lucas Mendonça Emery Cade
 *      		Lucas Moraes Soares de Souza
 */

#include "Entrada.h"

void Entrada::leEntrada(ifstream& in, Eleicao& eleicao) {
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
		Candidato* c = criaCandidato(entrada);

		// Organiza seu partido e coligação nas listas relevantes
		eleicao.adicionaPartidoColigacao(c, c->getPartidoColigacao());

		// Insere o candidato na lista de candidatos
		eleicao.candidatos.push_back(c);

		// Verifica o primeiro caracter da próxima linha
		peek = in.peek();
	}
}

Candidato* Entrada::criaCandidato(string& entrada) {
	// 			Modelo do Arquivo de Entrada
	// Seq. (i);Núm.;Candidato;Partido/Coligação;Votação;% Válidos
	// *0001;23123;FABRÍCIO GANDINI;PPS - PPS / PROS;7.611;4,21 %

	// Conversão de string para stringstream
	stringstream in(entrada);

	// String auxiliar de leitura
	string linha;

	// Strings de entrada para o construtor de candidato
	string situacao;
	int numero;
	string nome;
	string partidoColigacao;
	int votos;

	// Define o primeiro caracter como a situação do candidato
	//     * ------------> significa eleito
	//     [um número] --> significa não eleito
	//     # ------------> significa que seus votos não foram validados
	getline(in, linha, ';');
	situacao = linha[0];

	// Lê o número do candidato como uma string e converte para inteiro
	getline(in, linha, ';');
	istringstream (linha) >> numero;

	// Lê o nome do candidato
	getline(in, linha, ';');
	nome = linha;

	// Lê a string do partido e coligação
	getline(in, linha, ';');
	// Armazena essa string pra uso futuro, depois de definir os votos
	partidoColigacao = linha;

	// Lê o número de votos do candidato como uma string
	getline(in, linha, ';');
	// Retira os pontos da string e converte para inteiro
	int votosAux = tiraPontos(linha);
	votos = votosAux;

	// Lê a porcentagem de votos válidos do candidato
	//     inutilizado no problema
	getline(in, linha, '\n');

	Candidato* c = Candidato(situacao, numero, nome, partidoColigacao, votos);

	return c;
}


// Funções Auxiliares

// Recebe uma string referente a um número e converte para inteiro, retirando os pontos
//     que representam as divisões de 10³
int Entrada::tiraPontos(string& numString) {

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
