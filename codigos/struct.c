#include <stdio.h>
#include <string.h>


typedef struct
{
    char nome[50];
    float notas[100]; //ate 100 notas.
    int numNotas;
} aluno;

void adicionarAluno(aluno alunos[], int *qntAlunos){
    aluno novoAluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", novoAluno.nome);

    printf("Digite quantas notas quer cadastrar: ");
    scanf("%d", &novoAluno.numNotas);

    for(int i = 0; i < novoAluno.numNotas; i++){
        printf("Digite a nota numero %d: ", i+1);
        scanf("%f", &novoAluno.notas[i]);
    }

    alunos[*qntAlunos] = novoAluno;
    *qntAlunos = *qntAlunos + 1;

    return;
}

int acharAluno(aluno alunos[], int qntAlunos, char nomeAluno[]){
    for(int i = 0; i < qntAlunos; i++){
        if(strcmp(nomeAluno, alunos[i].nome) == 0){
            return i;
        }
    }
    return -1;
}

void calcularMedia(aluno alunos[], int qntAlunos){
    char nome[50];
    int indexAchado, numeroNotas = 0;
    float notaTotal = 0;

    

    if(!qntAlunos){
        printf("Não há alunos registrados\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", nome);

    indexAchado = acharAluno(alunos, qntAlunos, nome);
    if(indexAchado == -1){
        printf("Aluno não encontrado!\n");
    }else{
        for(int i = 0; i < alunos[indexAchado].numNotas; i++){
            notaTotal += alunos[indexAchado].notas[i];
        }
        printf("A média desse aluno é %f\n", notaTotal/alunos[indexAchado].numNotas);
    }

}

int pegarEscolha(){
    int escolha;
    printf("\n1- Adicionar um aluno;\n2- Calcular média de aluno\n3- Sair\n\nEscolha uma opção: ");
    scanf("%d", &escolha);

    return escolha;
}

int main(){
    int escolha, qntAlunos = 0;
    aluno alunos[100];

    while (escolha != 3)
    {
        escolha = pegarEscolha();
        switch (escolha)
        {
        case 1:
            adicionarAluno(alunos, &qntAlunos);
            break;
        
        case 2:
            calcularMedia(alunos, qntAlunos);
            break;

        case 3:
            printf("Programa encerrado!\n");
            break;
        default:
            printf("Escolha Inválida!\n");
            break;
        }
    }
    
    return 0;
}