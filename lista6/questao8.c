#include <stdio.h>
#include <string.h>

char* encontrarSubstring( char *string, char *substring) {
     char *ptr = string;  // Ponteiro para percorrer a string principal
     char *newsub = substring;

    while (*ptr != '\0') {
         char *s = ptr;  // Ponteiro para comparar a substring
         char *newsub = substring;
        // Compare a substring com a parte da string principal
        while (*s == *newsub && *s != '\0' && *newsub != '\0') {
            //printf("%c: %c - %c = %d\n", *ptr, *(s), *(substring), *(s+1) == *(substring+1));
            //printf("aa: %s\n", s);
            s++;
            newsub++;
        }

        // Se a substring for encontrada, retorne o ponteiro para a primeira ocorrência
        if (*newsub == '\0') {
            return ptr;
        }

        ptr++;  // Avance o ponteiro na string principal
    }

    return NULL;  // Retorne NULL se a substring não for encontrada
}

int main() {
     char *string = "Esta é uma string de exemplo.";
     char *substring = "exemplo";

    char *result = encontrarSubstring(string, substring);

    if (result != NULL) {
        printf("Substring encontrada: %s\n", result);
    } else {
        printf("Substring não encontrada.\n");
    }

    return 0;
}
