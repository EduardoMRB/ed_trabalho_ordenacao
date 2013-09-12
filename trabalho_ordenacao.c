#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Autores: Eduardo Borges, Michel Rodrigues e Jean Osowski
 * 
 * Eduardo Borges       - Método de ordenação: Shell Sort campo valor
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

void shellSort(Mercadoria vet[], int tamanho) {
    int i, j;
    float valor;
    int intervalo = 1;
    do {
        intervalo = 3 * intervalo + 1;
    } while (intervalo < tamanho);
    do {
        intervalo /= 3;
        for(i = intervalo; i < tamanho; i++) {
            valor = vet[i].valor;
            j = i - intervalo;
            while (j >= 0 && valor < vet[j].valor) {
                vet [j + intervalo].valor = vet[j].valor;
                j -= intervalo;
            }
            vet [j + intervalo].valor = valor;
        }
    } while ( intervalo > 1);
}

int main() {
    Mercadoria merc1, merc2, merc3;
    merc1.valor = 2.2;
    merc2.valor = 2.1;
    merc3.valor = 0.9;

    int i = 0;

    Mercadoria vet[3] = { merc1, merc2, merc3 };
    shellSort(vet, 3);

    for (i; i < 3; ++i) {
        printf("%f\n", vet[i].valor);
    }
}