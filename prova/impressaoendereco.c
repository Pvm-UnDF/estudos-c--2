#include <stdio.h>

int main()
{
    int valor = 42;
    int *ponteiro = &valor;
    printf("Endereço do ponteiro: %p e %d\n", ponteiro, **&*(&ponteiro));

    char s[] = "OI!";
    printf("s = %s\n", s);
    printf("s[0] = %c %p\n", s[0], &s[0]);
    printf("s[1] = %c %p\n", s[1], &s[1]);
    printf("s[2] = %c %p\n", s[2], &s[2]);
    printf("s[3] = %d %p\n", s[3], &s[3]);
    return 0;
}