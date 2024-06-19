/*
Esercizio 2: Ordinamento di Due Vettori da File

Descrizione:
Scrivi un programma in C che legge n righe di numeri double da un file di testo, crea due vettori, 
ordina ciascun vettore utilizzando l'algoritmo Bubble Sort e stampa entrambi i vettori prima e dopo l'ordinamento. 
Il programma deve utilizzare il file 'file.txt' contenente i numeri double.

Istruzioni:
1. Leggi le due righe di numeri double dal file 'file.txt'.
2. Crea due vettori per memorizzare i numeri di ciascuna riga.
3. Implementa l'algoritmo Bubble Sort per ordinare ciascun vettore.
4. Stampa entrambi i vettori prima e dopo l'ordinamento.

NB Assumere al più un numero prefissato di righe e di colonne.

Esempio di input/output:

Contenuto di file.txt:
12.3 45.6 23.1 78.9 34.5 67.8 56.7 89.0 43.2 90.1
11.1 22.2 33.3 44.4 55.5 66.6 77.7 88.8 99.9 100.0

Output atteso:

Prima dell'ordinamento:
Primo vettore: 12.3 45.6 23.1 78.9 34.5 67.8 56.7 89.0 43.2 90.1
Secondo vettore: 11.1 22.2 33.3 44.4 55.5 66.6 77.7 88.8 99.9 100.0

Dopo l'ordinamento:
Primo vettore ordinato: 12.3 23.1 34.5 43.2 45.6 56.7 67.8 78.9 89.0 90.1
Secondo vettore ordinato: 11.1 22.2 33.3 44.4 55.5 66.6 77.7 88.8 99.9 100.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLUMNS 50

void printVector(double* vet, int size) {
    for(int i = 0; i < size; i++)
        printf("%.2f ", vet[i]);
    printf("\n");
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b; 
    *b = tmp;
}

void bubblesort(double* vet, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(vet[i] > vet[j])
                swap(&vet[i], &vet[j]);
        }
    }
}

// Memorizzare il ciclo di tokenizzazione e la lettura con fgets
int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Errore: numero di argomenti insufficiente.\n");
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    
    double vectors[MAX_ROWS][MAX_COLUMNS]; // Matrice di double
    int sizes[MAX_ROWS] = {0}; // Array di interi per memorizzare la dimensione di ciascun vettore
    int i = 0; int j = 0; // Indici per scorrere righe e colonne

    char buffer[BUFSIZ]; // Buffer per leggere una riga del file
    while(fgets(buffer, BUFSIZ, fp)) {
        buffer[strlen(buffer)-1] = '\0'; // Rimuovi il carattere '\n'
        i++; 
        j = 0; 
        char* token = strtok(buffer, " ");
        while(token) { 
            vectors[i][j] = atof(token); 
            j++;
            token = strtok(NULL, " ");
        }
        sizes[i] = j;
    }
    fclose(fp);

    printf("\nBefore sorting:\n\n");
    for(int i = 0; i < MAX_ROWS; i++) {
        if(sizes[i] > 0) {
            printf("Vector %d: ", i);
            printVector(vectors[i], sizes[i]);
        }
    }
    printf("\n");

    printf("... sorting ...\n");
    for(int i = 0; i < MAX_ROWS; i++) {
        if(sizes[i] > 0) 
            bubblesort(vectors[i], sizes[i]);
    }

    printf("\nAfter sorting:\n\n");
    for(int i = 0; i < MAX_ROWS; i++) {
        if(sizes[i] > 0) {
            printf("Vector %d: ", i);
            printVector(vectors[i], sizes[i]);
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}