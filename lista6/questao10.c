#include <stdio.h>
#include <stdlib.h>

void copiarArquivo(FILE *arq1, FILE *arq2){
    char carac;

    while(fscanf(arq1, "%c", &carac) != EOF) {
        fprintf(arq2, "%c", carac);

    }
}

int main(){
    FILE *arq1 = fopen("arqv1.txt", "r"), *arq2 = fopen("arqv2.txt", "w");
    copiarArquivo(arq1, arq2);
    return 0;
}