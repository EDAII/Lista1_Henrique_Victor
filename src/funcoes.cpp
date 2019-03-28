#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <bitset>

#include "funcoes.hpp"
#include "buscas.hpp"

using namespace std;

void vetor_aleatorio(vector<int>& v, int quant, int limite) {
    v.clear();
    srand(time(0));

    for(int i = 0; i < quant; ++i) 
        v.push_back(rand() % limite);
    
    sort(v.begin(), v.end());
}

void vetor_primos(vector<int>& v, int N) {
    v.clear();
    bitset<50000010> sieve;
    sieve.set();

    v.push_back(2);

    for (long long i = 3; i <= N; i += 2) {
        if (sieve[i]) {
            v.push_back(i);

            for (long long j = i * i; j <= N; j += 2*i)
                sieve[j] = false;
        }
    }
}

void vetor_fibo(vector<int>& v, int N) {
    v.clear();

    int a = 0, b = 1;

    v.push_back(a);

    if(N < 2)
        return;
    
    v.push_back(b);
    
    if(N < 3)
        return;

    for(int i = 2; i < N; ++i) {
        int c = a + b;
        v.push_back(c);
        a = b; b = c;
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
    //Verifica se o vetor existe
    if(v.size() != 0){
        printf("\n[");

        //Percorre o vetor até o final
        for(unsigned int i = 0; i < v.size(); i++) {
            printf(" %d", v[i]);

            printf("%c", i != v.size() - 1 ? ',' : ' ');

            int resto = i%10;

            if(resto == 9 && i < v.size() - 1)
                printf("\n");
        }

        printf("]\n");
    }
    else
        printf("Vetor vazio.\n");
}

//Função auxiliar que pausa o programa para melhor usabilidade
void pause() {
    getchar();
	printf("\nPressione 'Enter' para voltar ao menu principal\n");
	getchar();
    system("clear");
}