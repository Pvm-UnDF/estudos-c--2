#include <stdio.h>

int comprimentoString(char *texto){
    int comprimento = 0;

    while (texto[comprimento] != '\0')
    {
        comprimento++;
    }

    return comprimento; 
}

int main(){
    char *texto = "123456789";
    printf("%d", comprimentoString(texto));
    return 0;
}