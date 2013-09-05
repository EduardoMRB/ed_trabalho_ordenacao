#include <stdlio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Autores: Eduardo Borges, Michel Rodrigues e Jean Osowski
 * 
 * Eduardo Borges       - Método de ordenação: Merge Sort campo valor
 *
 * Michel Rodrigues     - Método de ordenação: Bubble Sort campo id
 *
 * Jean Osowski(JENIAU) - Método de ordenação: Quick Sort campo nome
 *
 */

typedef struct mercadoria {
    int id;
    float valor;
    char *nome;
} Mercadoria;

void merge(Mercadoria vet[], int tamanho) {
    int meio;
    int i, j, k;
    int* tmp;

    tmp = (int*) malloc(tamanho * sizeof(int));

    meio = tamanho / 2;

    i = 0;
    j = meio;
    k = 0;

    while (i < meio && j < tamanho) {
        if (vet[i] < vet[j]) {
            tmp[k] = vet[i++];
        } else {
            tmp[k] = vet[j++];
        }
        ++k;
    }

    if (i == meio) {
        while (j < tamanho) {
            tmp[k++] = vet[j++];
        }
    } else {
        while (i < meio) {
            tmp[k++] = vet[i++];
        }
    }

    for (i = 0; i < tamanho; ++i) {
        vet[i] = tmp[i];
    }

    free(tmp);
}

void mergeSort(Mercadoria vet[], int tamanho) {
    int meio;

    if (tamanho > 1) {
        meio = tamanho / 2;
        mergeSort(vet, meio);
        mergeSort(vet + meio, tamanho - meio);
        merge(vet, tamanho);
    }
}

int main() {

}