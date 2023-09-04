#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verificaSenha(char senha[]){
    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0, tamanhoSenha = strlen(senha);

    if (tamanhoSenha < 8){
        return 0;
    }

    for (int i = 0; i < tamanhoSenha; i++){
        int eAlphaNumerico = isalpha(senha[i]);
        if(!eAlphaNumerico){
            if(isdigit(senha[i])){
                temNumero = 1;
            }
        }else{
            if(eAlphaNumerico == 1){
                temMaiuscula = 1;
            }else{
                temMinuscula = 1;
            }
        }
    }

    if (temMaiuscula && temMinuscula && temNumero){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char senha[50];
    int senhaAprovada = 0;

    while (!senhaAprovada){
        printf("Digite a senha: ");
        scanf("%s", senha);

        senhaAprovada = verificaSenha(senha);
        if(!senhaAprovada){
            printf("Sua senha é inválida!\n");
        }
    }

    printf("Sua senha é válida!");

    return 0;
}
