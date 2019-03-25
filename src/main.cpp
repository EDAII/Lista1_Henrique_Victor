#include <iostream>

#include "funcoes.hpp"
#include "buscas.hpp"

using namespace std;

void menu_principal();

int main() {
    int opcao, valor, encontrado;
    time_t tempo;
    vector<int> v;

    while(1) {
        menu_principal();
        scanf(" %d", &opcao);

        while(opcao < 0 || opcao > 7) {
            printf("Opção Inválida, tente novamente: ");
            scanf(" %d", &opcao);
        }

        switch (opcao) {
            case 1:
                tempo = clock();
                vetor_aleatorio(v);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 2:
                printf("Insira o elemento que deseja inserir: ");
                scanf(" %d", &valor);
                tempo = clock();
                inserir_valor(v, valor);
                tempo = clock() - tempo;
                printf("Elemento inserido com sucesso.\n");
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 3:
                printf("Insira o elemento que deseja remover: ");
                scanf(" %d", &valor);
                tempo = clock();
                remover_valor(v, valor);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 4:
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 5:
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial_sentinela(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 6:
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_binaria(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 7:
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_interpolacao(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                break;
            case 0:
                printf("Programa encerrado.\n");
                exit(0);
        }
    }    
    
    return 0;
}

void menu_principal() {
    printf("ESCOLHA UMA OPCAO:\n\n");

    printf("1. Gerar vetor aleatorio\n");
    printf("2. Inserir valor\n");
    printf("3. Remover valor\n");
    printf("4. Busca Sequencial\n");
    printf("5. Busca Sequencial com Sentinela\n");
    printf("6. Busca Binaria\n");
    printf("7. Busca por Interpolacao\n");
    printf("0. Encerrar\n\n");

    printf("Opcao: ");
}