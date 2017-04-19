#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "io.h"
#include "sort.h"

#define TAMSTRING 30
#define TAMENTRADA 4

int main(int argc, char *argv[]){
	char entrada[TAMSTRING], saida[TAMSTRING];
	int *vetEntrada, i;

	int *vetor;

    struct timeval inicio, fim;
    float tempoExecucao;
    int nComp, nMov;
	// fim declaracao de variaveis

	strcpy(entrada, (argv[argc = 1]));
	strcpy(saida, (argv[argc = 2]));

	vetEntrada = leEntrada(entrada, TAMENTRADA);

	for(i = 0; i < TAMENTRADA; i++){
		vetor = geraVetorOrdenado(vetEntrada[i]);
		gettimeofday(&inicio, NULL);
		quicksort(vetor, 0, vetEntrada[i] - 1, &nComp, &nMov);
		gettimeofday(&fim, NULL);
		tempoExecucao = (float) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1);
		salvaEstatistica(saida, 0, vetEntrada[i], nComp, nMov, tempoExecucao);
		nComp = 0;
		nMov = 0;
		free(vetor);
	}

	free(vetEntrada);
	return 0;
}