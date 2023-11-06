#include <stdio.h>
#include <string.h>

void copiarString(char *texto1, char *texto2){
    strcpy(texto2, texto1);
}

int main(){
    char *texto1 = "ola mundo", texto2[100];

    copiarString(texto1, texto2);
    printf("%s", texto2);
    
    return 0;
}