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

int busca_sequencial_indexada(vector<int>& v, vector<int> &index, int e) {
    if(v.size() != 0) {
        int i;

        for(i = 0; i < index.size(); ++i)
            if(index[i] > e)
                break;

        i--;

        i = (i*v.size())/index.size();

        for(i; i < v.size(); ++i) {
            if(v[i] == e)
                return i;
            if(v[i] > e)
                return -1;
        }
    }
    return -1;
}