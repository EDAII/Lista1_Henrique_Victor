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

void vetor_primos(vector<int>& v, int N) {
    int max = 500000010;
    vector<int>isprime(max , true); 
    vector<int>SPF(max);
    isprime[0] = isprime[1] = false ; 
  
    for (int i=2; i<N ; i++) { 
        if (isprime[i]) { 
            v.push_back(i); 
            SPF[i] = i; 
        } 
  
        for (int j=0; j < (int)v.size() && i*v[j] < N && v[j] <= SPF[i]; j++) { 
            isprime[i*v[j]]=false; 
            SPF[i*v[j]] = v[j] ; 
        } 
    }
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

    //Verifica se o vetor existe
    if(v.size() != 0){

        //Percorre o vetor até o final
        for(unsigned int i = 0; i < v.size(); i++) {
            printf(" %d, ", v[i]);

            int resto = i % 10;
            //quebra a linha a cada 10 elementos
            if(i > 1 && resto == 0) {
                printf("\n");
            }
        }
    }
    else {
        printf(" Vetor vazio!");
    }
    printf("]\n\n\n");
}

//Função auxiliar que pausa o programa para melhor usabilidade
void pause() {
    getchar();
	printf("\nPressione 'Enter' para voltar ao menu principal\n");
	getchar();
}