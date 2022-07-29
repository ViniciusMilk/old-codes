
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[], int tam)
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

int binary_search(int vector[], int begin, int end, int item)
{
      /* Índice representando o meio do sub-vetor begin->end */
      int i = (begin + end) / 2;

      if (begin > end)
      { /* Ponto de parada. Item não está no vetor */
            return -1;
      }

      if (vector[i] == item)
      { /* Item encontrado */
            return i;
      }

      if (vector[i] < item)
      { /* Item está no sub-vetor à direita */
            return binary_search(vector, i + 1, end, item);
      }
      else
      { /* vector[i] > item. Item está no sub-vetor à esquerda */
            return binary_search(vector, begin, i - 1, item);
      }
}

int main(int argc, char **argv)
{

      int array[100], tamanho, ordem;
      printf("\n\n\t Entre com o numero de termos...: ");
      scanf("%d", &tamanho);
      printf("\n\t Entre com os elementos do array...:");
      for (int i = 0; i < tamanho; i++)
      {
            printf("\nDigite o %d numero: ", i + 1);
            scanf("%d", &array[i]);
      }

      printf("\nArray inicial: ");
      for (int i = 0; i < tamanho; i++)
      {
            printf("\n\t\t\t%d", array[i]);
      }
      printf("\n");

      int opt = 1;
      while (opt != 0)
      {

            printf("|============================|MENU|=============================|\n");
            printf("|\t\t1- ORDENAR POR INSERTION\t\t\t|\n");
            printf("|\t\t2- ORDENAR POR SHELL\t\t\t\t|\n");
            printf("|\t\t3- ORDENAR POR SELECTION\t\t\t|\n");
            printf("|\t\t4- BUSCAR POR UM ITEM\t\t\t\t|\n");
            printf("|\t\t0- EXIT \t\t\t\t\t\t|\n");
            printf("|===============================================================|\n");

            printf("| ENTRE COM UMA OPCAO |\n");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
            {
                  insertionSortC(array, tamanho);
                  printf("\nArray em ordem crescente: ");
                  for (int i = 0; i < tamanho; i++)
                  {
                        printf("\n\t\t\t%d", array[i]);
                  }
                  printf("\n");
                  break;
            }
            case 2:
            {
                  shellSort(array, tamanho);
                  printf("\nArray em ordem crescente: ");
                  for (int i = 0; i < tamanho; i++)
                  {
                        printf("\n\t\t\t%d", array[i]);
                  }
                  printf("\n");
                  break;
            }
            case 3:
            {
                  selection_sort(array, tamanho);
                  printf("\nArray em ordem crescente: ");
                  for (int i = 0; i < tamanho; i++)
                  {
                        printf("\n\t\t\t%d", array[i]);
                  }
                  printf("\n");
                  break;
            }
            case 4:
            {
                  int item;
                  printf("Busque por um item: ");
                  scanf("%d", &item);

                  int enc = binary_search(array, 0, tamanho, item);
                  if (enc == -1)
                  {
                        printf("Numero nao encontrado.\n");
                  }
                  else
                  {
                        printf("%d encontrado.\n", item);
                  }
                  printf("\n");
                  break;
            }
            case 0:
            {
                  return 0;
            }

            default:
            {
                  printf("OPCAO INVALIDA:\n");
                  break;
            }
            }
      }

      return 0;
}
