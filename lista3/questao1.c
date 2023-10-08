#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void utf8(){
    SetConsoleOutputCP(65001);
}

void limpaBuffer(){
    while(getchar() != '\n'); 
}

int stringsIguais(char str1[], char str2[]){
    if (strcmp(str1, str2) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char *argv[]){
    utf8();

    float valorVenda, valorRecebido, moedasExistentes[] = {1.0,0.5,0.25,0.1,0.05,0.01}, troco;
    int cedulas = 0, moedas = 0, cedulasExistentes[] = {100,50,20,10,5,2}, cedulasDadas[] = {0,0,0,0,0,0}, moedasDadas[] = {0,0,0,0,0,0};
    char moedasNomes[6][60] = {"1 real", "50 centavos", "25 centavos", "10 centavos", "5 centavos", "1 centavo"};



    if (argc <= 1){
        printf("Informe os valores de venda e recebimento");
        return 1;
    }

    if (stringsIguais(argv[1], "-v")){
        if (argc > 4){
            if (stringsIguais(argv[3], "-r")){
                valorVenda = atof(argv[2]);
                valorRecebido = atof(argv[4]);
            }else{
                printf("Informe o valor recebido");
                return 1;
            }
        }else{
            if (stringsIguais(argv[2], "-r")){
                printf("Informe o valor de venda");
            }else{
                printf("Informe o valor recebido");
            }
            return 1;
        }
    }else if (stringsIguais(argv[1], "-r")){
        if (argc > 4){
            if (stringsIguais(argv[3], "-v")){
                valorVenda = atof(argv[4]);
                valorRecebido = atof(argv[2]);
            }else{
                if (stringsIguais(argv[2], "-v")){
                    printf("Informe o valor recebido");
                }else{
                    printf("Informe o valor de venda");
                }
                return 1;
            }
        }else{
            printf("Informe o valor de venda");
            return 1;
        }
    }else{
        printf("Informe os valores de venda e recebimento");
        return 1;
    }
    
    if(valorRecebido < valorVenda){
        printf("O valor recebido é menor que o valor de venda");
        return 1;
    }else{
        troco = valorRecebido - valorVenda;
        printf("%f\n", troco);
        for(int i = 0; i < 6; i++){
            while(troco >= cedulasExistentes[i]){
                troco -= cedulasExistentes[i];
                cedulas++;
                cedulasDadas[i] += 1;
            }
        }
        for(int i = 0; i < 6; i++){
            while(troco >= moedasExistentes[i]){
                troco -= moedasExistentes[i];
                moedas++;
                moedasDadas[i] += 1;
            }
        }

        printf("troco entregue = %d cédulas e %d moedas\n", cedulas, moedas);
        for(int i = 0; i < 6; i++){
            if (cedulasDadas[i] != 0){
                printf("(%d) %d reais\n", cedulasDadas[i], cedulasExistentes[i]);
            }         
        }
        for(int i = 0; i < 6; i++){
            if (moedasDadas[i] != 0){
                printf("(%d) %s\n", moedasDadas[i], moedasNomes[i]);
            }         
        }
    }

    return 0;
} 