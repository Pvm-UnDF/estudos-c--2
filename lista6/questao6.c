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

int ePalindromo(char *texto){
    int tamanho = comprimentoString(texto);
    for(int i = 0; i < tamanho; i++){
        if(texto[i] != texto[tamanho-1]){
            return 0;
        }
        tamanho--;
    }
    return 1;
}

int main(){
    char *texto = "121";
    int resultado = ePalindromo(texto);

    switch (resultado)
    {
    case 1:
        printf("E palindromo");
        break;
    default:
        printf("Nao e palindromo");
        break;
    }

    return 0;
}