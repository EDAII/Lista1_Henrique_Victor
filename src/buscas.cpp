#include "buscas.hpp"

int busca_binaria(vector<int>& v, int e) {
    int inicio = 0, meio, fim = v.size() - 1;

    while(inicio <= fim) {
        meio = inicio + (fim - inicio)/2;

        if(e == v[meio])
            return meio;
        else if (e < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}

int busca_sequencial(vector<int>& v, int e) {
    for(size_t i = 0; i < v.size(); ++i)
        if(v[i] == e)
            return i;
    
    return -1;
}

int busca_sequencial_sentinela(vector<int>& v, int e) {
    size_t i = 0, n = v.size();
    v.push_back(e);

    while(e != v[i])
        i++;
    
    v.pop_back();

    if(i < n)
        return i;
    
    return -1;
}

int busca_interpolacao(vector<int>& v, int e) {
    int inicio = 0, meio, fim = v.size() - 1;

    while(inicio <= fim) {
        meio = inicio + (fim - inicio) * ((e-v[inicio]) / (v[fim]-v[inicio]));

        if(e == v[meio])
            return meio;
        else if (e < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}

vector<int> gerar_tabela_index(vector<int>& v) {
    int tamanho_index = v.size() / 10000;
    vector<int> index;

    if(tamanho_index == 0)
        index.push_back(0);

    for(int i = 0; i < tamanho_index; ++i)
        index.push_back(v[i * 10000]);

    return index;
}

int busca_sequencial_indexada(vector<int>& v, int e) {
    vector<int> index = gerar_tabela_index(v);
    unsigned int i;

    for(i = 0; i < index.size(); ++i)
        if(index[i] > e)
            break;

    i--;

    for(i = (i*v.size())/index.size(); i < v.size(); ++i) {
        if(v[i] == e)
            return i;
        if(v[i] > e)
            return -1;
    }
    
    return -1;
}