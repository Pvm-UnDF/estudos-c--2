#include <stdio.h>
#include <string.h>
#include <ctype.h>

void escolhaOpcao(int *escolha){
    int invalido = 0;
    *escolha = 0;
    while (*escolha < 1 || *escolha > 3){
        if(invalido){
            printf("Escolha inválida!\n");
        }
        printf("1. Cifrar uma mensagem\n2. Descifrar uma mensagem\n3. Sair\nEscolha sua opção: ");
        scanf("%d", escolha);
        invalido = 1;
    }
}

int validarAdiantamento(){
    int adiantamento;
    do{
    if(adiantamento > 26 || adiantamento < 0){
        printf("adiantamento inválido!\n");
    }
    printf("Digite o adiantamento da cifra (0 a 26): ");
    scanf("%d", &adiantamento);
    }while(adiantamento < 0 || adiantamento > 26);

    return adiantamento;
}

void adicionarString(unsigned char mensagem[], int adiantamento){
    for(int i = 0; i < strlen(mensagem); i++){
        int tipoLetra = isalpha(mensagem[i]);

        if(tipoLetra == 1){ // Maiuscula
            mensagem[i] += adiantamento;

            if(mensagem[i] > 90){
                mensagem[i] -= 26;
            }else if(mensagem[i] < 65){
                mensagem[i] += 26;
            }
        }else if(tipoLetra == 2){ // Minuscula
            mensagem[i] += adiantamento;
            if(mensagem[i] > 122){
                mensagem[i] -= 26;
            }else if(mensagem[i] < 97){
                mensagem[i] += 26;
            }
        }
    }
}

void sistemaCifragem(int cifrar){
    unsigned char frase[50];
    int adiantamento;

    printf("Digite a frase: ");
    scanf(" %[^\n]s", frase);

    adiantamento = validarAdiantamento();
    adiantamento *= cifrar;

    adicionarString(frase, adiantamento);
    printf("O resultado é: %s\n", frase);
}

int main(){
    int escolha = 0;
    while(escolha != 3){
        escolhaOpcao(&escolha);

        switch (escolha)
        {
        case 1:
            sistemaCifragem(1);
            break;
        case 2:
            sistemaCifragem(-1);
            break;
        default:
            printf("Programa encerrado");
        }
    }

    return 0;
}
