/*
Esercizio 1: Manipolazione di Stringhe con Lettura da File

Descrizione:
Scrivi un programma in C che accetti il nome di un file di testo come argomento da riga di comando, legga il contenuto del file e conti il numero di vocali presenti nel testo. 
Il programma deve stampare il numero di vocali.

Istruzioni:
1. Accetta il nome di un file di testo come argomento da riga di comando.
2. Leggi il contenuto del file.
3. Conta il numero di vocali (a, e, i, o, u, sia maiuscole che minuscole) nel testo.
4. Stampa il risultato.

Esempio di input:
./esercizio1 file.txt

Esempio di output:
Numero di vocali: 976
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    //faccio il controllo di errore sul numero di argomenti
    if (argc != 2){
        printf("Error: %s", argv[0]);
    }

    //tento di aprire il file in modalità read
    FILE * file = fopen(argv[1], "r");
    if (file == NULL){
        perror("Errore nell'apertura del file");
    }

    int count = 0;
    int c; // memorizza il carattere letto dal file di testo
    while ((c =fgetc(file)) != EOF){ //fget legge il carattere successivo puntato da file che è il puntatore a file fino alla fine del fine (EOF)
        c = tolower(c); //se il carattere è maiuscolo tolower lo converte in minuscolo (libreria ctype.h)
        if (c =='a' || c == 'e' || c == 'i' || c == 'o' || c== 'u') {
            count++;
        }
    }

    fclose(file); //chiudo il file dopo che l'ha letto tutto
    printf ("Il numero di vocali é:  %d\n", count);


}


