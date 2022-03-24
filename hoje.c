#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n;
    printf("Digite a quantidade de linha da matriz.\n");
    scanf("%d", &n);
    int **matriz = (int **)calloc(n, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        matriz[i] = (int *)malloc(5 * sizeof(int));
    }

    printf("Preencha sua matriz.\n");
    // Laço para preencher a matriz.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // imprimir matriz.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    int media[n], somatorio = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            somatorio += matriz[i][j];
        }
        media[i] = somatorio / 5;
        somatorio = 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("media da %d linha %d\n", i + 1, media[i]);
    }

    int maiorMe = media[0], linha = 0;

    for (int i = 0; i < n; i++)
    {
        if (media[i] > maiorMe)
        {
            maiorMe = media[i];
            linha = i;
        }
    }
    printf("linha de maior media %d\n", linha + 1);

    int soma = 0, somaaux = 0, vv[5];

    for (int m = 0; m < 5; m++)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = m; j < m + 1; ++j)
            {
                somaaux += matriz[i][j];
            }
            soma += somaaux;
            somaaux = 0;
        }
        vv[m] = soma;
        soma = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("soma da %d coluna %d\n", i + 1, vv[i]);
    }

    int v[2], maiorEle = matriz[0][0];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (matriz[i][j] > maiorEle)
            {
                v[0] = i;
                v[1] = j;
            }
        }
    }

    printf("linha e coluna de maior valor é: linha%d coluna%d\n", v[0] + 1, v[1] + 1);

    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}