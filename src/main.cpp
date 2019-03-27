#include <iostream>

#include "funcoes.hpp"
#include "buscas.hpp"

using namespace std;

void menu_principal();

int main() {
    int opcao, valor, encontrado;
    time_t tempo;
    vector<int> v, index;

    while(1) {
        menu_principal();
        scanf(" %d", &opcao);

        system("clear");

        switch (opcao) {
            case 1:
                tempo = clock();
                vetor_aleatorio(v);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 2:
                printf("Gerar primos de 1 a n.\n");
                printf("Insira o valor de n: \n");
                scanf(" %d", &valor);
                while(valor > 500000000) {
                    printf("Valor maior que 500.000.000, tente novamente.\n");
                    scanf(" %d", &valor);
                }
                tempo = clock();
                vetor_primos(v, valor);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 3:
                printf("Insira o elemento que deseja inserir: ");
                scanf(" %d", &valor);
                tempo = clock();
                inserir_valor(v, valor);
                tempo = clock() - tempo;
                printf("Elemento inserido com sucesso.\n");
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 4:
                printf("Insira o elemento que deseja remover: ");
                scanf(" %d", &valor);
                tempo = clock();
                remover_valor(v, valor);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 5:
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
                pause();
                break;
            case 6:
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
                pause();
                break;
            case 7:
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
                pause();
                break;
            case 8:
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
                pause();
                break;
            case 9:
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial_indexada(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                printf("Tempo: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 10:
                //Fazer todas as buscas de uma vez e comparar tempos
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);

                encontrado = busca_sequencial(v, valor);

                if(encontrado != -1)
                    printf("\nValor encontrado.\n");
                else
                    printf("\nValor não encontrado.\n");
                
                //Busca sequencial
                printf("\nBuscando por busca sequencial:");
                tempo = clock();
                encontrado = busca_sequencial(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);



                //Busca Sequencial com sentinela                
                printf("\nBuscando por busca sequencial com sentinela:");

                tempo = clock();
                encontrado = busca_sequencial_sentinela(v, valor);
                tempo = clock() - tempo;

                
                printf("Tempo decorrido: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);

                //Busca Binaria
                printf("\nBuscando por busca binaria:");

                tempo = clock();
                encontrado = busca_binaria(v, valor);
                tempo = clock() - tempo;

                
                printf("Tempo decorrido: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);

                //Busca por interpolacao
                printf("\nBuscando por interpolação:");

                tempo = clock();
                encontrado = busca_interpolacao(v, valor);
                tempo = clock() - tempo;

                
                printf("Tempo decorrido: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);

                //busca sequencial indexada
                printf("\nBuscando por busca sequencial indexada:");

                tempo = clock();
                encontrado = busca_sequencial_indexada(v, valor);
                tempo = clock() - tempo;

                printf("Tempo decorrido: %.6f segundos.\n\n", ((float)tempo)/CLOCKS_PER_SEC);

                pause();
                break;
            case 11:
                imprimir_vetor(v);
                pause();
                break;
            case 0:
                printf("Programa encerrado.\n");
                exit(0);
            default:
                printf("Opção Inválida! ");
        }
    }    
    
    return 0;
}

void menu_principal() {
    system("clear");
    printf("ESCOLHA UMA OPCAO:\n\n");

    printf("1. Gerar vetor aleatorio\n");
    printf("2. Gerar vetor de primos\n");
    printf("3. Inserir valor\n");
    printf("4. Remover valor\n");
    printf("5. Busca Sequencial\n");
    printf("6. Busca Sequencial com Sentinela\n");
    printf("7. Busca Binaria\n");
    printf("8. Busca por Interpolacao\n");
    printf("9. Busca Sequencial Indexada\n");
    printf("10. Fazer todas as buscas e comparar tempos\n");
    printf("11. Imprimir vetor na tela\n");
    printf("0. Encerrar\n\n");

    printf("Opcao: ");
}