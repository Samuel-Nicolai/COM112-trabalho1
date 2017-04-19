#include "sort.h"

int particiona(int *vetor, int inicio, int fim, int *nComp, int *nMov){
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while(esq < dir){
        while(vetor[esq] <= pivo){
            esq++;
            (*nComp)++;
        }
        while(vetor[dir] > pivo){
            dir--;
            (*nComp)++;
        }
        if(esq < dir){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
            (*nMov)++;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    (*nMov)++;
    return dir;
}

void quicksortInteligente(int *vetor, int inicio, int fim, int *nComp, int *nMov){
    int pivo;
    while(inicio < fim){
        pivo = particiona(vetor, inicio, fim, nComp, nMov);
        if((pivo - inicio) < (fim - pivo)){
            quicksortInteligente(vetor, inicio, pivo - 1, nComp, nMov);
            inicio = pivo + 1;
        }
        else{
            quicksortInteligente(vetor, pivo + 1, fim, nComp, nMov);
            fim = pivo - 1;
        }
    }
}

void quicksort(int *vetor, int inicio, int fim, int *nComp, int *nMov){
    int pivo;
    if(inicio < fim){
        pivo = particiona(vetor, inicio, fim, nComp, nMov);
        quicksort(vetor, inicio, pivo - 1, nComp, nMov);
        quicksort(vetor, pivo + 1, fim, nComp, nMov);
    }
}