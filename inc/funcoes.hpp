#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <vector>

using namespace std;

void vetor_aleatorio(vector<int>& v);
void inserir_valor(vector<int>& v, int e);
void remover_valor(vector<int>& v, int e);
void imprimir_vetor(vector<int>& v);
vector<int> gerar_tabela_index(vector<int>& v);
void busca_sequencial_indexada(vector<int>&v, vector<int>&index, int e);

#endif // FUNCOES_HPP