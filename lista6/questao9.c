#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criptografa(char *texto, int avanco) {
    for (int i = 0; i < strlen(texto); i++) {
        texto[i] += avanco;
    }
}


void descriptografa(char *texto, int avanco){
    for(int i = 0; i < strlen(texto); i++){
        texto[i] -= avanco;
    }
}

int main(){
    char texto[] = "ola mundo!";
    int avanco = 3;

    criptografa(texto, avanco);
    printf("%s\n", texto);

    descriptografa(texto, avanco);
    printf("%s\n", texto);
    

    return 0;
}