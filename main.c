#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Faça um programa para cadastrar alunos e professores em um vetor de struct. Os dados dos alunos são: nome, serie e nível.
Os dados dos professores são: nome, escolaridade, disciplina. O programa deve exibir os dados de todos os alunos e professores cadastrados.
*/
typedef struct
{
    char nome[20];
    char serie[20];
    char nivel[20];
} aluno;

typedef struct
{
    char nome[20];
    char escolaridade[20];
    char diciplina[20];
} professor;

int main()
{
    aluno a[20];
    professor p[20];

    int escolha;
    int i;

    printf("Escolha a opcao que voce ira fornecer os dados.\n");
    printf("\nDigite:\n1 para aluno\n2 para professor\nQualquer numero diferente de 1 ou 2 para encerrar o programa\n");

    scanf("%d", &escolha);

    if (escolha == 1)
    {

        for (i = 0; i < 3; ++i)
        {
            printf("\nDigite o nome aluno %d.\n", i + 1);
            scanf("%s", &a[i].nome);
            printf("Digite a serie do aluno %d.\n", i + 1);
            scanf("%s", &a[i].serie);
            printf("Digite o nivel do aluno %d.\n", i + 1);
            scanf("%s", &a[i].nivel);
        }
        for (i = 0; i < 3; ++i)
        {
            printf("\nO nome do aluno %d eh:\t%s\n\n", i + 1, a[i].nome);
            printf("A serie do aluno %d eh:\t %s serie\n\n", i + 1, a[i].serie);
            printf("O nivel do aluno %d eh:\t %s\n\n", i + 1, a[i].nivel);
        }
    }
    else if (escolha == 2)
    {
        for (i = 0; i < 3; ++i)
        {
            printf("\nDigite o nome do professor %d.\n", i + 1);
            scanf("%s", &p[i].nome);
            printf("\nDigite a escolaridade do professor %d.\n", i + 1);
            scanf("%s", &p[i].escolaridade);
            printf("\nDigite a diciplina do professor %d.\n", i + 1);
            scanf("%s", &p[i].diciplina);
        }
        for (i = 0; i < 3; ++i)
        {
            printf("\nO nome do professor %d eh:\t %s\n\n", i + 1, p[i].nome);
            printf("A escolaridade do professor %d eh:\t %s\n\n", i + 1, p[i].escolaridade);
            printf("A diciplina do professor %d eh:\t %s\n\n", i + 1, p[i].diciplina);
        }
    }
    else if (escolha != (1 || 2))
    {
        return 0;
    }
    return 0;
}
