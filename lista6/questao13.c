#include <stdio.h>

void criptografarDescriptografar(FILE *arquivo, int chave) {
    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        // Aplicar a operação de criptografia/descriptografia
        caractere = caractere ^ chave;
        fputc(caractere, arquivo);
    }
}

int main() {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r+");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int opcao, chave;

    printf("Escolha uma opção:\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("Digite a chave de criptografia: ");
    scanf("%d", &chave);

    if (opcao == 1) {
        criptografarDescriptografar(arquivo, chave);
        printf("Arquivo criptografado com sucesso.\n");
    } else if (opcao == 2) {
        criptografarDescriptografar(arquivo, chave);
        printf("Arquivo descriptografado com sucesso.\n");
    } else {
        printf("Opção inválida.\n");
    }

    fclose(arquivo);
    return 0;
}
