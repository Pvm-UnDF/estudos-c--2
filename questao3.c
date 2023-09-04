#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char vogais[50], frase[50];

    printf("Escreva sua frase: ");
    scanf("%s", frase);

    for(int i = 0; i < strlen(frase); i++){
        char atualCharMaiusculo = toupper(frase[i]);
        if (atualCharMaiusculo == 'A' || atualCharMaiusculo == 'E' || atualCharMaiusculo == 'I' || atualCharMaiusculo == 'O' || atualCharMaiusculo == 'U'){
            vogais[strlen(vogais)] = frase[i];
        }
    }

    printf("%s %s", frase, vogais);
    return 0;
}
