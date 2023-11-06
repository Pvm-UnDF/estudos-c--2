#include <stdio.h>
#include <string.h>

int comprimentoString(char *texto){
    int comprimento = 0;

    while (texto[comprimento] != '\0')
    {
        comprimento++;
    }

    return comprimento; 
}

void concatenarString(char *texto1, char *texto2){
    int tamanho = comprimentoString(texto1);
    int progresso = 0;

    while(texto2[progresso] != '\0'){
        texto1[tamanho] = texto2[progresso];
        tamanho++;
        progresso++;
    }
    texto1[tamanho] = '\0';
}

int main(){
    char texto1[100] = "ola", texto2[100] = " mundo";

    concatenarString(texto1, texto2);
    printf("%s", texto1);
    
    return 0;
}