#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <vector>

using namespace std;

void vetor_aleatorio(vector<int>& v, int quant, int limite);
void vetor_primos(vector<int>& v, int N);
void vetor_fibo(vector<int>& v, int N);
void inserir_valor(vector<int>& v, int e);
void remover_valor(vector<int>& v, int e);
void imprimir_vetor(vector<int>& v);
void pause();
#endif // FUNCOES_HPP