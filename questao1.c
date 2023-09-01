#include <stdio.h>

int pegarEscolha(int *escolha){
    printf("  Calculadora\n   1. Somar\n   2. Subtrair\n   3. Multiplicar\n   4. Dividir\n   5. Média Ponderada das notas\n   0. Sair\n\nDigite a sua opção: ");
    scanf("%d", escolha);

    while (*escolha < 0 || *escolha > 5){
        printf("\n\n\nEscolha uma opção válida!\n\n");
        printf("  Calculadora\n   1. Somar\n   2. Subtrair\n   3. Multiplicar\n   4. Dividir\n   5. Média Ponderada das notas\n   0. Sair\n\nDigite a sua opção: ");
        scanf("%d", escolha);
    }
}

float operacao(int operacao){
    float numero1,numero2;

    printf("Digite o primeiro número: ");
    scanf("%f",&numero1);

    printf("Digite o segundo número: ");
    scanf("%f",&numero2);

    switch(operacao){
        case 1:
            return numero1+numero2;
        case 2:
            return numero1-numero2;
        case 3:
            return numero1*numero2;
        case 4:
            return numero1/numero2;
    }

}

float mediaPonderada(){
    int opcao = 1, divisor = 0, pesoAtual;
    float pontuacao = 0, notaAtual;

    while(opcao == 1){
        printf("Escreva uma nota: ");
        scanf("%f", &notaAtual);

        printf("Escreva o peso dessa nota: ");
        scanf("%d", &pesoAtual);

        pontuacao += notaAtual*pesoAtual;
        divisor += pesoAtual;

        printf("1. Adicionar uma nota\n2. Calcular a nota final\nDigite sua opção: ");
        scanf("%d", &opcao);
    }
    return pontuacao/divisor;

}

int main(){
    int escolha = 1;
    float resultado = 0;

    while(escolha){
        pegarEscolha(&escolha);
        if(escolha){
            if(escolha == 5){
                resultado = mediaPonderada();
            }else{
                resultado = operacao(escolha);
            }
            printf("\nO resultado é %f\n\n", resultado);
        }

    }
    return 0;
}
