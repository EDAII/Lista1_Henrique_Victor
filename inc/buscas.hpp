#ifndef BUSCAS_HPP
#define BUSCAS_HPP

#include <vector>

using namespace std;

int busca_binaria(vector<int>& v, int e);
int busca_sequencial(vector<int>& v, int e);
int busca_sequencial_sentinela(vector<int>& v, int e);
int busca_interpolacao(vector<int>& v, int e);
vector<int> gerar_tabela_index(vector<int>& v);
int busca_sequencial_indexada(vector<int>&v, int e);

#endif // BUSCAS_HPP