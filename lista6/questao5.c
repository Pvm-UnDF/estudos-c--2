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

int compararStrings(char *texto1, char *texto2){
    int tamanho1 = comprimentoString(texto1), tamanho2 = comprimentoString(texto2);

    if(tamanho1 > tamanho2){
        return -1;
    }else if(tamanho1 < tamanho2){
        return 1;
    }else{
        for(int i = 0; i < tamanho1; i++){
            if(texto1[i] != texto2[i]){
                return 2;
            }
        }
        return 0;
    }
}

int main(){
    char texto1[100] = "olaaa", texto2[100] = "olaaa";

    int resultado = compararStrings(texto1, texto2);
    
    switch (resultado)
    {
    case -1:
        printf("texto1 > texto2");
        break;
    case 1:
        printf("texto1 < texto2");
        break;
    case 0:
        printf("texto1 = texto2");
        break;
    default:
        printf("texto1 ~= texto2");
        break;
    }

    return 0;
}