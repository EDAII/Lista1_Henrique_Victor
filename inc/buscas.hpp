#ifndef BUSCAS_HPP
#define BUSCAS_HPP

#include <vector>

using namespace std;

int busca_binaria(vector<int>& v, int e);
int busca_sequencial(vector<int>& v, int e);
int busca_sequencial_sentinela(vector<int>& v, int e);
int busca_interpolacao(vector<int>& v, int e);
int busca_sequencial_indexada(vector<int>&v, vector<int>&index, int e);

#endif // BUSCAS_HPP