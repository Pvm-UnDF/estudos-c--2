#include <stdio.h>
#include <stdio.h>
int main()
{
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("nomes.csv", "r");
    if (arquivo != NULL)
    {
        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            printf("Linha lida: %s", linha);
        }
        fclose(arquivo);
    }
}