#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char modelo[30];
	char fabricante[30];
	float valor;
	int disponivel;
} aparelho;

typedef struct cel
{
	aparelho aparelho;
	struct cel *ant;
	struct cel *prox;
} Celula;

Celula *inserirFim(Celula *head, Celula *cel)
{
	cel->prox = NULL;
	if (head == NULL)
	{
		cel->ant = NULL;
		return cel;
	}
	else
	{
		Celula *last = head;
		while (last->prox != NULL)
		{
			last = last->prox;
		}
		last->prox = cel;
		cel->ant = last;
	}
	return head;
}

Celula *inserirInicio(Celula *head, Celula *aux)
{
	aux->ant = NULL;
	if (head == NULL)
	{
		aux->prox = NULL;
		return aux;
	}
	head->ant = aux;
	aux->prox = head;
	return aux;
}

Celula *adicionar(Celula *head)
{
	Celula *aux = (Celula *)malloc(sizeof(Celula));

	printf("\nDigite o modelo do aparelho: ");
	scanf(" %29[^\n]", aux->aparelho.modelo);

	printf("Digite o nome do fabricante do aparelho: ");
	scanf(" %29[^\n]", aux->aparelho.fabricante);

	printf("Digite o valor do aparelho: ");
	scanf("%f", &aux->aparelho.valor);

	printf("Digite a quantidade de aparelho disponivel no estoque: ");
	scanf("%d", &aux->aparelho.disponivel);

	head = inserirFim(head, aux);

	return head;
}

void venda(Celula *aux)
{
	char modelo[30];
	printf("\nDigite o modelo que deseja: ");
	scanf(" %[^\n]", modelo);

	if (aux == NULL)
	{
		printf("\nAparelho não encontrado!\n");
	}
	else if (aux->aparelho.modelo == modelo)
	{
		if (aux->aparelho.disponivel > 0)
		{
			printf("Aparelho vendido com sucesso.\n");
			aux->aparelho.disponivel--;
		}
	}
}

void imprimir(Celula *aux)
{
	printf("\nLISTA DE APARELHO: ");
	while (aux != NULL)
	{
		printf("\nModelo: \t%s\nFabricante: \t%s\nValor: \t%.2f\nEm estoque: \t%d\n ", aux->aparelho.modelo, aux->aparelho.fabricante, aux->aparelho.valor, aux->aparelho.disponivel);
		aux = aux->prox;
	}
}

int main(int argc, char const *argv[])
{

	Celula *head = NULL;

	int opt = 1;
	while (opt != 0)
	{
		printf("\n\n");
		printf("\t|=============MENU==============|\n");
		printf("\t|\t1-Adicionar\t\t|\n");
		printf("\t|\t2-Buscar\t\t|\n");
		printf("\t|\t3-Arrecadação Total\t|\n");
		printf("\t|\t4-Alugar\t\t|\n");
		printf("\t|\t5-Imprimir\t\t|\n");
		printf("\t|\t0-Sair\t\t\t|\n");
		printf("\t================================|\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			head = adicionar(head);
			break;
		/*case 2:
			buscaFabricante(head);
			break;
		case 3:
			totalArrecadado(head);
			break;*/
		case 4:
			venda(head);
			break;
		case 5:
			imprimir(head);
			break;
		case 0:
			printf("\nPrograma encerrado...\n");
			return 0;
		default:
			printf("\nOpção invalida\n");
			break;
		}
	}

	return 0;
}