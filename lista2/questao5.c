#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

void utf8(){
    SetConsoleOutputCP(65001);
}

int indexPalavraSecreta(int maxPalavras){
    srand(time(NULL));

    return rand()%maxPalavras;
}

int getEscolha(int maxOpcao){
    int escolha = -1;
    scanf("%d", &escolha);

    while (escolha > maxOpcao || escolha <= 0)
    {
        printf("Escolha inválida, tente novamente: ");
        scanf("%d", &escolha);
    }
    

    return escolha;
}

int stringsIguais(char string1[], char string2[]){ // 0 = String iguais, 1 = String diferentes
    return strcmp(string1, string2);
}

void palavraCompleta(int *acertou, char palavraSecreta[]){
    char tentativa[50];
    printf("\n\nDigite a palavra completa que você acha que é: ");
    scanf(" %[^\n]s", tentativa);
    if (stringsIguais(tentativa, palavraSecreta) == 0){
        *acertou = 1;
    }else{
    
    }
} 

int letrasNaString(char string[], char letra){
    int letras = 0;
    for(int i = 0; i < strlen(string); i++){
        if (string[i] == letra){
            letras++;
        }
    }

    return letras;
}

void chuteLetra(char palavraSecreta[]){
    char letra;
    int letras;

    
    while(getchar() != '\n');
    printf("Digite a letra que deseja chutar: ");
    scanf("%c", &letra);

    letras = letrasNaString(palavraSecreta, letra);
    if(letras){
        printf("A letra %c aparece %d vez(es) na palavra!\n", letra, letras);
    }else{
        printf("A letra %c não aparece na palavra!\n", letra);
    }
}


int main(){
    utf8();

    int tentativas, maxPalavras = 6, tamanho, acertou = 0;
    char palavrasPossiveis[6][50] = {"mafagafo","girafa", "albergue", "corpo", "espaco", "felino"}, palavraSecreta[50], tentativa[50];


    printf("Bem-vindo(a) ao jogo de descobrir as palavras, digite quantas tentativas você quer ter: ");
    scanf("%d", &tentativas);
    printf("Você terá %d tentativas para advinhar a palavra escolhen duas opções:\n", tentativas);
    

    strcpy(palavraSecreta, palavrasPossiveis[indexPalavraSecreta(maxPalavras)]);
    printf("%s", palavraSecreta);

    tamanho = strlen(palavraSecreta);
    while (tentativas && acertou == 0){
        printf("\nO tamanho da palavra secreta é %d.\n\n1- Advinhar Palavra Completa\n2- Chutar uma letra\nEscolha uma opção: ", tamanho);
        switch (getEscolha(2))
        {
        case 1:
            palavraCompleta(&acertou, palavraSecreta);
            break;
        case 2:
            chuteLetra(palavraSecreta);
            break;
        }
        tentativas--;
    }
    if (acertou){
        printf("Parabéns você acertou a palavra!\n");
    }else{
        printf("Você não acertou a palavra!\n");
    }

    return 0;
}