#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20000

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
void insertionSortC(int *array, int tamanho);
void selection_sort(int *a, int tam);
void bubbleSort(int *v, int tam);
void quick_sort(int *a, int left, int right);
void shellSort(int *numbers, int *merge, int *insertion, int *selection, int *bubble, int *quick, int array_size);

void print(int *v)
{
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int i, shell[MAX], merge[MAX], insertion[MAX], selection[MAX], bubble[MAX], quick[MAX];

    // geração aleatório dos valores do vetor
    srand((unsigned)time(NULL));
    for (int a = 0; a < MAX; a++)
    {
        shell[a] = rand() % MAX;
    }

    shellSort(shell, merge, insertion, selection, bubble, quick, MAX);
    print(merge);
    clock_t t = clock(); // armazena tempo
    mergesort(merge, MAX);
    t = clock() - t;
    printf("Tempo de execucao do merge: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
    print(insertion);
    t = clock();
    insertionSortC(insertion, MAX);
    t = clock() - t;
    printf("Tempo de execucao do insertion: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
    print(bubble);
    t = clock();
    bubbleSort(bubble, MAX);
    t = clock() - t;
    printf("Tempo de execucao do bubble: %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
    print(selection);
    t = clock();
    selection_sort(selection, MAX);
    t = clock() - t;
    printf("Tempo de execucao: selection %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
    print(quick);
    t = clock();
    quick_sort(quick, 0, MAX - 1);
    t = clock() - t;
    printf("Tempo de execucao: quick %lf\n", ((double)t) / ((CLOCKS_PER_SEC)));
    printf("\n");
    return 0;
}

void selection_sort(int *a, int tam)
{
    int k, tmp, troca;
    for (int i = 0; i < tam; i++)
    {
        troca = 0;
        k = i;
        tmp = a[i];
        for (int j = i + 1; j < tam; j++)
        {
            if (a[j] < tmp)
            {
                k = j;
                tmp = a[j];
                troca = 1;
            }
        }
        if (troca)
        {
            a[k] = a[i];
            a[i] = tmp;
        }
    }
}

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
    }
}

void bubbleSort(int *v, int tam)
{
    int a, b, aux;
    for (a = tam - 1; a >= 1; a--)
    {
        for (b = 0; b < a; b++)
        {
            if (v[b] > v[b + 1])
            {
                aux = v[b];
                v[b] = v[b + 1];
                v[b + 1] = aux;
            }
        }
    }
}

void insertionSortC(int *array, int tamanho)
{
    int i, j, tmp;
    for (i = 1; i < tamanho; i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            j--;
        }
    }
}

void mergesort(int *v, int n)
{
    int c[n];
    sort(v, c, 0, n - 1);
}

void sort(int *v, int *c, int i, int f)
{
    if (i >= f)
        return;

    int m = (i + f) / 2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);
    if (c[m] >= c[m + 1])
    {
        merge(v, c, i, m, f);
    }
}

void merge(int *v, int *c, int i, int m, int f)
{
    int z, iv = i, ic = m + 1;
    for (int z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;

    while (iv <= m && ic <= f)
    {
        if (c[iv] <= c[ic])
        {
            v[z] = c[iv];
            z++;
            iv++;
        }
        else
        {
            v[z] = c[ic];
            z++;
            ic++;
        }
    }

    while (iv <= m)
    {
        v[z++] = c[iv++];
    }
    while (ic <= f)
    {
        v[z++] = c[ic++];
    }
}

void shellSort(int *numbers, int *merge, int *insertion, int *selection, int *bubble, int *quick, int array_size)
{
    int i, j, increment, temp;

    increment = 3;
    while (increment > 0)
    {
        for (i = 0; i < array_size; i++)
        {
            j = i;
            temp = numbers[i];
            while ((j >= increment) && (numbers[j - increment] > temp))
            {
                numbers[j] = numbers[j - increment];
                j = j - increment;
            }
            numbers[j] = temp;
        }
        if (increment / 2 != 0)
            increment = increment / 2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }

    for (int i = 0; i < MAX; i++)
    {
        merge[i] = insertion[i] = selection[i] = bubble[i] = quick[i] = numbers[i];
    }
}