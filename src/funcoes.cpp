#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "funcoes.hpp"
#include "buscas.hpp"

using namespace std;

void vetor_aleatorio(vector<int>& v) {
    v.clear();

    int quant, limite;
    srand(time(0));

    printf("Insira a quantidade de elementos: ");
    scanf(" %d", &quant);

    printf("Insira o limite do valor dos elementos: ");
    scanf(" %d", &limite);

    for(int i = 0; i < quant; ++i) 
        v.push_back(rand() % limite);
    
    sort(v.begin(), v.end());

    printf("\nVetor aleatorio gerado.\n");
}

void inserir_valor(vector<int>& v, int e) {
    v.push_back(e);
    sort(v.begin(), v.end());
}

void remover_valor(vector<int>& v, int e) {
    if(!v.size()) {
        printf("Vetor vazio.\n\n");
        return;
    }

    int indice = busca_binaria(v, e);

    if(indice != -1) {
        v.erase(v.begin()+indice);
        printf("Elemento removido com sucesso.\n");
    }
    else
        printf("Elemento nao encontrado.\n");
}

void imprimir_vetor(vector<int>& v) {
    printf("\n[");
    if(v.size() != 0){
        for(unsigned int i = 0; i < v.size(); i++) {
            printf("%d, ", v[i]);    
        }
    }
    else {
        printf(" Vetor vazio!");
    }
    printf("]\n\n\n");
}