#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comprimentoString(char *texto){
    int comprimento = 0;

    while (texto[comprimento] != '\0')
    {
        comprimento++;
    }

    return comprimento; 
}

void inverterString(char *texto1){
    int tamanho = comprimentoString(texto1), invertida = 0;
    char *stringInvertida = malloc(sizeof(char) * tamanho);

    
    for(int i = tamanho-1; i >= 0; i--){ 
        stringInvertida[invertida] = texto1[i];
        //printf("%c", texto1[i]);
        invertida++;
    }
    stringInvertida[invertida] = '\0';
    strcpy(texto1, stringInvertida);
}

int main(){
    char texto1[100] = "odnum alo";

    inverterString(texto1);
    printf("%s", texto1);
    
    return 0;
}