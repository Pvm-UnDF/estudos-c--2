#include <stdio.h>

void compactarArquivo(FILE *entrada, FILE *saida) {
    int caractere, espacoAnterior = 0;
    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere == ' ') {
            if (!espacoAnterior) {
                fputc(caractere, saida);
                espacoAnterior = 1;
            }
        } else {
            fputc(caractere, saida);
            espacoAnterior = 0;
        }
    }
}

void descompactarArquivo(FILE *entrada, FILE *saida) {
    int caractere;
    while ((caractere = fgetc(entrada)) != EOF) {
        fputc(caractere, saida);
    }
}

int main() {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    FILE *saidaCompactado = fopen("arquivoCompactado.txt", "w");
    if (saidaCompactado == NULL) {
        perror("Erro ao criar o arquivo compactado");
        return 1;
    }

    compactarArquivo(entrada, saidaCompactado);
    fclose(entrada);
    fclose(saidaCompactado);

    FILE *entradaCompactado = fopen("arquivoCompactado.txt", "r");
    if (entradaCompactado == NULL) {
        perror("Erro ao abrir o arquivo compactado");
        return 1;
    }

    FILE *saidaDescompactado = fopen("arquivoDescompactado.txt", "w");
    if (saidaDescompactado == NULL) {
        perror("Erro ao criar o arquivo descompactado");
        return 1;
    }

    descompactarArquivo(entradaCompactado, saidaDescompactado);

    printf("Compactação e descompactação concluídas com sucesso.\n");

    fclose(entradaCompactado);
    fclose(saidaDescompactado);

    return 0;
}
