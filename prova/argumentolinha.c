#include <stdio.h>

int main(int argc, char *argv[]) {
    // argc contém o número de argumentos passados, incluindo o nome do programa
    // argv é um array de strings que contém os argumentos

    printf("Número de argumentos: %d\n", argc);

    // O primeiro elemento de argv (argv[0]) é o nome do programa em si
    printf("Nome do programa: %s\n", argv[0]);

    // Se houver mais argumentos, você pode acessá-los usando argv
    if (argc > 1) {
        printf("Outros argumentos:\n");
        for (int i = 1; i < argc; i++) {
            printf("Argumento %d: %s\n", i, argv[i]);
        }
    }

    return 0;
}
