#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    printf("Digite a palavra ou frase a ser procurada: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';  // Remova o caractere de nova linha

    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';  // Remova o caractere de nova linha

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[1000];
    int numeroLinha = 1;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, palavra) != NULL) {
            printf("Ocorrência encontrada na linha %d: %s", numeroLinha, linha);
        }
        numeroLinha++;
    }

    fclose(arquivo);
    return 0;
}
