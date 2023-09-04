#include <stdio.h>
int main(int argc, char *argv[]){
    printf("Temos %d argumentos\n", argc);
    for(int i = 0; i < argc; i++){
        printf("Argumento %d - %s\n", i, argv[i]);
    }
}