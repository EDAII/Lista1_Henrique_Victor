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


vector<int> gerar_tabela_index(vector<int>& v) {

    int elementos = v.size() / 10;
    
    vector<int> index;
    
    if(v.size() != 0) {
        for(unsigned int i = 0; i < v.size(); i += elementos){
            index.push_back(v[i]);
        }
        for (auto x : index)
            printf("%d ", x);
        
        printf("\n");
        return index;
    } else {
        printf("Impossivel gerar tabela de indices, o vetor não existe ou esta vazio!\n\n");
        return index;
    }
}

void busca_sequencial_indexada(vector<int>& v, vector<int> &index, int e) {
    if(v.size() != 0) {
        for(unsigned int i = 0; i < index.size(); i++) {
            if(e >= index[i] && e <= index[i+1]) {
                i += index.size();
                for(int j = i ; v[j] <= e; j++) {
                    if(e == v[j]) {
                        printf("valor encontrado!\n\n");
                        return;
                    }
                }
            }
        }
    } else {
        printf("impossivel fazer a busca, o vetor não existe ou está vazio!\n\n");
    }
}

/* 7 13 25 42 52 54 66 73 84 90 */

/* 7,  9,  9,  13,  16,  18,  25,  26,  37,  42,  50,  51,  52,  53,  53,  54,  56,  66,  66,  68,  70,  73,  80,  80,  84,  85,  86,  90,  96,  96 */