#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main (){

    int m, n = 50;
    printf("Digite a quantidade de Alunos.\n");
    scanf("%d", &m);
    char **matriz = (char**) calloc(m, sizeof(char));
    int i;
    for (i = 0; i < m; i++) {
        matriz[i] = (char *) malloc (n * sizeof(char));
    }

    printf("Digite os nomes dos alunos da turma.\n");

    for ( i = 0; i < m; i++){
        scanf(" %49[^\n]", matriz[i]);
    }

    char nome[50];
    printf("Busque por um nome.\n");
    scanf(" %49[^\n]", nome);
    
    int x = 0;

    for ( i = 0; i < m; i++){
        if (strcmp(nome,matriz[i]) == 0){
            x = 1;
        }
    }

    if (x == 0)
        printf("Aluno %s nao matriculado.\n", nome);
    else
        printf("Aluno %s matriculado.\n", nome);
    
    printf("Turma:\n");

    for (int i = 0; i < m; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}


