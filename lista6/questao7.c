#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenizeString(char *input, char delimiter, int *tokenCount) {
    char **tokens = NULL;  // Inicialize o array de ponteiros como nulo
    *tokenCount = 0;      // Inicialize o contador de tokens como 0
    char *token = strtok(input, &delimiter);  // Use strtok para obter o primeiro token

    while (token != NULL) {
        (*tokenCount)++;  // Incremente o contador de tokens

        // Realoque o array de ponteiros para acomodar o novo token
        tokens = realloc(tokens, *tokenCount * sizeof(char*));
        if (tokens == NULL) {
            perror("Erro de alocação de memória");
            exit(1);
        }

        // Aloque memória para o token atual e copie o token nele
        tokens[*tokenCount - 1] = malloc(strlen(token) + 1);
        if (tokens[*tokenCount - 1] == NULL) {
            perror("Erro de alocação de memória");
            exit(1);
        }
        strcpy(tokens[*tokenCount - 1], token);

        token = strtok(NULL, &delimiter);  // Obtenha o próximo token
    }

    return tokens;
}

int main() {
    char input[100] = "um,dois,três,quatro,cinco";
    char delimiter = ',';
    int tokenCount = 0;

    char **tokens = tokenizeString(input, delimiter, &tokenCount);

    for (int i = 0; i < tokenCount; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);  // Libere a memória alocada para cada token
    }

    free(tokens);  // Libere o array de ponteiros
    return 0;
}
