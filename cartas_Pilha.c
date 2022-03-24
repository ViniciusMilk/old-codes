#include <stdio.h>
#include <stdlib.h>

typedef struct cartas
{
    char carta[25];
    char naipe[15];
    struct cartas *prox;
} CARTAS;

typedef struct
{
    CARTAS *topo;
    int tamanho;
} Pilha;

Pilha *esvazia(Pilha *pilha)
{

    Pilha *aux = pilha;

    while (aux->topo != NULL)
    {

        aux->topo = aux->topo->prox;
        pilha->tamanho--;
        free(pilha->topo);
    }
    return aux;
}

Pilha *inicializaPilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->tamanho = 0;
    return pilha;
}

int vazia(Pilha *pilha)
{
    return (pilha->tamanho == 0);
}

CARTAS *inicializaCARTAS()
{

    CARTAS *carta = (CARTAS *)malloc(sizeof(CARTAS));
    printf("\nDigite o nome da carta.\n");
    scanf(" %24[^\n]", carta->carta);

    printf("Digite a naipe da carta.\n");
    scanf(" %14[^\n]", carta->naipe);

    return carta;
}

void push(Pilha *pilha, CARTAS *carta)
{

    carta->prox = pilha->topo;
    pilha->topo = carta;
    pilha->tamanho++;
}

void pop(Pilha *pilha)
{
    CARTAS *carta = pilha->topo;

    if (vazia(pilha))
        printf("Erro: pilha vazia\n");

    else
    {

        pilha->topo = pilha->topo->prox;
        pilha->tamanho--;
        carta->prox = NULL;
    }
}

void imprime(Pilha *pilha)
{

    if (vazia(pilha))
        printf("\nA Pilha está Vazia.\n");

    else
    {
        printf("\nPilha:\n\n");

        for (CARTAS *aux = pilha->topo; aux != NULL; aux = aux->prox)
        {

            printf("carta: \t\t%s\n", aux->carta);
            printf("naipe: \t\t%s\n", aux->naipe);
        }
        printf("\nA pilha tem %d cartas.\n", pilha->tamanho);
    }
}

int busca(CARTAS *carta, Pilha *pilha)
{
    int contador = 1;

    while (pilha->topo != NULL)
    {
        if (carta->carta == pilha->topo->carta || carta->naipe == pilha->topo->naipe)
        {
            pilha->topo = pilha->topo->prox;
            contador++;
        }
        else
        {
            contador = pilha->tamanho - contador;
            printf("Carta encontrada.\n");
            return contador;
        }
    }
}

int main()
{

    Pilha *pilha = inicializaPilha();
    Pilha *pilha2 = inicializaPilha();
    CARTAS *carta = NULL;
    CARTAS *cartabuscada = NULL;

    int cartasAcima = 0;

    int opt = 1;
    while (opt != 0)
    {
        printf("\n\n");
        printf("\t|=============MENU==============|\n");
        printf("\t|\t1-Empilhar\t\t|\n");
        printf("\t|\t2-Desempilhar\t\t|\n");
        printf("\t|\t3-Esvaziar\t\t|\n");
        printf("\t|\t4-Imprimir\t\t|\n");
        printf("\t|\t5-Buscar\t\t|\n");
        printf("\t|\t0-Sair\t\t\t|\n");
        printf("\t================================|\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opt);

        int deck = 0;

        switch (opt)
        {
        case 1:
            printf("\nDigite 1 para empilhar carta no deck 1 ou 2 para o deck 2.\n");
            scanf("%d", &deck);
            if (deck == 1)
            {
                carta = inicializaCARTAS();
                push(pilha, carta);
            }
            else
            {
                carta = inicializaCARTAS();
                push(pilha2, carta);
            }
            break;
        case 2:
            printf("\nDigite 1 para descartar uma carta do deck 1 ou 2 para do deck 2.\n");
            scanf("%d", &deck);
            if (deck == 1)
            {
                pop(pilha);
            }
            else
            {
                pop(pilha2);
            }

            break;
        case 3:
            pilha = esvazia(pilha);
            break;
        case 4:
            printf("\nDigite o deck que você quer imprimir.\n");
            printf("1 para deck 1 ou 2 para deck 2.\n");
            scanf("%d", &deck);
            if (deck == 1)
            {
                imprime(pilha);
            }
            else
            {
                imprime(pilha2);
            }
            break;
        case 5:
            printf("\nDigite o deck que deseja buscar carta.\n");
            printf("1- para deck 1 ou 2-para deck 2.\n");
            scanf("%d", &deck);

            cartabuscada = inicializaCARTAS();

            if (deck == 1)
            {
                cartasAcima = busca(cartabuscada, pilha);
            }
            else
            {
                cartasAcima = busca(cartabuscada, pilha2);
            }
            printf("Existe %d cartas acima da buscada.\n", cartasAcima);
            break;
        case 0:
            pilha = esvazia(pilha);
            printf("\nPrograma encerrado...\n");
            return 0;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }

    return 0;
}