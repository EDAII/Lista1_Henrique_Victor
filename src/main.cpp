#include <iostream>

#include "funcoes.hpp"
#include "buscas.hpp"

using namespace std;

void menu_principal();

int main() {
    int opcao, valor, encontrado, limite;
    time_t tempo;
    vector<int> v;
    string vetor_atual = "Nenhum";
    bool modificado;

    while(1) {
        system("clear");
        printf("Vetor atual: %s\n\n", vetor_atual.c_str());
        menu_principal();
        scanf(" %d", &opcao);

        system("clear");

        switch (opcao) {
            case 1:
                printf("Opcao escolhida: Gerar vetor aleatorio\n");
                printf("Insira a quantidade de elementos: ");
                scanf(" %d", &valor);
                printf("A lista ira gerar %d elementos aleatorios de 0 a n.\n", valor);
                printf("Insira o valor de n: ");
                scanf(" %d", &limite);
                tempo = clock();
                vetor_aleatorio(v, valor, limite+1);
                tempo = clock() - tempo;
                printf("\nVetor aleatorio gerado.\n");
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                vetor_atual = "Vetor aleatorio";
                modificado = false;
                pause();
                break;
            case 2:
                printf("Opcao escolhida: Gerar vetor de primos\n");
                printf("Gerar primos de 1 a n.\n");
                printf("Insira o valor de n: ");
                scanf(" %d", &valor);
                while(valor < 2 || valor > 50000000) {
                    if(valor < 2)
                        printf("Valor nao pode ser menor que 2, tente novamente: ");
                    else
                        printf("Valor nao pode ser maior que 50.000.000, tente novamente: ");
                        
                    scanf(" %d", &valor);
                }
                tempo = clock();
                vetor_primos(v, valor);
                tempo = clock() - tempo;
                printf("\nVetor de primos gerado.\n");
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                vetor_atual = "Vetor de Primos";
                modificado = false;
                pause();
                break;
            case 3:
                printf("Opcao escolhida: Gerar vetor de Fibonacci\n");
                printf("Insira quantos numeros de Fibonacci deseja: ");
                scanf(" %d", &valor);
                while(valor < 1 || valor > 47) {
                    if(valor < 1)
                        printf("Valor nao pode ser menor que 1, tente novamente: ");
                    else
                        printf("Valor nao pode ser maior que 47, tente novamente: ");
                        
                    scanf(" %d", &valor);
                }
                tempo = clock();
                vetor_fibo(v, valor);
                tempo = clock() - tempo;
                printf("\nVetor de Fibonacci gerado.\n");
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                vetor_atual = "Vetor de Fibonacci";
                modificado = false;
                pause();
                break;
            case 4:
                printf("Opcao escolhida: Inserir valor\n");
                printf("Digite o elemento que deseja inserir: ");
                scanf(" %d", &valor);
                tempo = clock();
                inserir_valor(v, valor);
                tempo = clock() - tempo;
                printf("Elemento inserido com sucesso.\n");
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                if(!modificado) {
                    vetor_atual += " (modificado)";
                    modificado = true;
                }
                pause();
                break;
            case 5:
                printf("Opcao escolhida: Remover valor\n");
                printf("Digite o elemento que deseja remover: ");
                scanf(" %d", &valor);
                tempo = clock();
                remover_valor(v, valor);
                tempo = clock() - tempo;
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                if(!modificado) {
                    vetor_atual += " (modificado)";
                    modificado = true;
                }
                pause();
                break;
            case 6:
                printf("Opcao escolhida: Busca Sequencial\n");
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 7:
                printf("Opcao escolhida: Busca Sequencial com Sentinela\n");
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial_sentinela(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 8:
                printf("Opcao escolhida: Busca Binaria\n");
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_binaria(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 9:
                printf("Opcao escolhida: Busca por Interpolacao\n");
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_interpolacao(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 10:
                printf("Opcao escolhida: Busca Sequencial Indexada\n");
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                tempo = clock();
                encontrado = busca_sequencial_indexada(v, valor);
                tempo = clock() - tempo;

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                printf("Tempo: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
                pause();
                break;
            case 11:
                printf("Opcao escolhida: Fazer todas as buscas e comparar tempos\n");
                //Fazer todas as buscas de uma vez e comparar tempos
                printf("Insira o elemento que deseja buscar: ");
                scanf(" %d", &valor);
                
                //Busca sequencial
                printf("\n------------ Busca sequencial ----------> ");
                tempo = clock();
                busca_sequencial(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);

                //Busca Sequencial com sentinela                
                printf("\n---- Busca sequencial com sentinela ----> ");
                tempo = clock();
                busca_sequencial_sentinela(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);

                //Busca Binaria
                printf("\n------------ Busca binaria -------------> ");
                tempo = clock();
                encontrado = busca_binaria(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);

                //Busca por interpolacao
                printf("\n-------- Busca por interpolacao --------> ");
                tempo = clock();
                busca_interpolacao(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);

                //busca sequencial indexada
                printf("\n------ Busca sequencial indexada -------> ");
                tempo = clock();
                busca_sequencial_indexada(v, valor);
                tempo = clock() - tempo;
                printf("Tempo decorrido: %.6f segundos.\n", ((float)tempo)/CLOCKS_PER_SEC);

                if(encontrado != -1)
                    printf("\nValor encontrado. Posicao: %d\n", encontrado);
                else
                    printf("\nValor não encontrado.\n");
                
                pause();
                break;
            case 12:
                printf("Opcao escolhida: Imprimir vetor na tela\n");
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
    printf("ESCOLHA UMA OPCAO:\n\n");

    printf("1. Gerar vetor aleatorio\n");
    printf("2. Gerar vetor de primos\n");
    printf("3. Gerar vetor de Fibonacci\n");
    printf("4. Inserir valor\n");
    printf("5. Remover valor\n");
    printf("6. Busca Sequencial\n");
    printf("7. Busca Sequencial com Sentinela\n");
    printf("8. Busca Binaria\n");
    printf("9. Busca por Interpolacao\n");
    printf("10. Busca Sequencial Indexada\n");
    printf("11. Fazer todas as buscas e comparar tempos\n");
    printf("12. Imprimir vetor na tela\n");
    printf("0. Encerrar\n\n");

    printf("Opcao: ");
}