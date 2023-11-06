#include <stdio.h>
#include <ctype.h>

int contarPalavras(FILE *arquivo) {
    int totalPalavras = 0;
    int dentroDaPalavra = 0; // Indicador se estamos dentro de uma palavra

    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (isalnum(caractere)) {
            if (!dentroDaPalavra) {
                totalPalavras++;
                dentroDaPalavra = 1;
            }
        } else {
            dentroDaPalavra = 0;
        }
    }
    return totalPalavras;
}

int main() {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int totalPalavras = contarPalavras(arquivo);

    printf("Total de palavras no arquivo: %d\n", totalPalavras);

    fclose(arquivo);
    return 0;
}
