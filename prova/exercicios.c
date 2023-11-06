#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inserir texto no arquivo
void inserirTexto(FILE *arquivo) {
    char texto[1000]; // Tamanho máximo do texto
    printf("Digite o texto que deseja inserir (ou deixe em branco para sair):\n");
    getchar(); // Consumir a nova linha pendente
    fgets(texto, sizeof(texto), arquivo);
    //fprintf(arquivo, "%s", texto);
}

// Função para ler o arquivo e exibir seu conteúdo
void lerArquivo(FILE *arquivo) {
    char linha[1000]; // Tamanho máximo de uma linha
    printf("Conteúdo do arquivo:\n");

    rewind(arquivo); // Volta ao início do arquivo

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    printf("\n");
}

int main() {
    char nomeArquivo[100];
    FILE *arquivo;

    printf("Digite o nome do arquivo que deseja criar: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "a+"); // Abre o arquivo para leitura e escrita (append mode)

    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }

    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir texto no arquivo\n");
        printf("2 - Ler o arquivo\n");
        printf("3 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirTexto(arquivo);
                break;
            case 2:
                lerArquivo(arquivo);
                break;
            case 3:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    fclose(arquivo);

    return 0;
}
