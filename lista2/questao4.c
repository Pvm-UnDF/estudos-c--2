#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limparPrompt(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void exibirItens(char itens[][50], int numItens) {
    if (numItens == 0) {
        printf("A lista de itens está vazia.\n");
        return;
    }

    printf("Lista de itens:\n");
    for (int i = 0; i < numItens; i++) {
        printf("%d. %s\n", i + 1, itens[i]);
    }
}

void adicionarItem(char itens[][50], int *numItens) {
    if (*numItens >= 10) {
        printf("A lista de itens está cheia.\n");
        return;
    }

    char novoItem[50];
    printf("Digite o nome do novo item: ");
    scanf(" %[^\n]s", novoItem);

    strcpy(itens[*numItens], novoItem);
    *numItens = *numItens + 1;

    printf("Item adicionado.\n");
}

void removerItem(char itens[][50], int *numItens) {
    if (*numItens == 0) {
        printf("A lista de itens está vazia.\n");
        return;
    }
    exibirItens(itens, *numItens);
    printf("Digite o número do item a ser removido (1 a %d): ", *numItens);
    int indice;
    scanf("%d", &indice);

    if (indice < 1 || indice > *numItens) {
        printf("Índice inválido. Por favor, insira um índice válido.\n");
        return;
    }

    for (int i = indice - 1; i < *numItens - 1; i++) {
        strcpy(itens[i], itens[i + 1]);
    }

    *numItens = *numItens - 1;

    printf("Item removido.\n");
}

int main() {
    char itens[10][50];
    int numItens = 0;
    char escolha;

    while (escolha != 'd'){
        printf("\n\n");
        printf("Sistema de itens\na. Exibir itens\nb. Adicionar item\nc. Remover item\nd. Sair\nDigite a sua opção: ");
        scanf(" %c", &escolha);
        limparPrompt();
        escolha = tolower(escolha);
        switch (escolha) {
            case 'a':
                exibirItens(itens, numItens);
                break;
            case 'b':
                adicionarItem(itens, &numItens);
                break;
            case 'c':
                removerItem(itens, &numItens);
                break;
            case 'd':
                break;
            default:
                printf("Escolha uma opção válida.\n");
        }
    }

    return 0;
}
