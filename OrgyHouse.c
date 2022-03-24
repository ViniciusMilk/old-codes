#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct days
{
    char firstDay[20];
    char secondDay[20];
}DAY;

typedef struct OrgyHouse
{
    int id;
    char city[30];
    char burgh[30];
    char number[6];
    DAY days;
    
}HOUSE;

typedef struct node
{
    HOUSE house;
    struct node *left;
    struct node *right;
    
}NODE;

int main () {

    NODE* treeInitialize();    
    HOUSE houseCreate();
    NODE* treeInsert(NODE *root, HOUSE x);    
    void treeImprimi(NODE *root);
    NODE* treeFree(NODE *root);
    NODE* treeSearch(NODE *root, int id);
    NODE* treeRemove(NODE *root, int id);
    void treeImprimiOne(NODE *root);

    NODE *root = treeInitialize();

    int opt = 1;
    while(opt!=0){
    printf("|============================|MENU|=============================|\n");
    printf("|\t\t1-Adicionar casa de orgia\t\t\t|\n");
    printf("|\t\t2-Imprimir arvore\t\t\t\t|\n");
    printf("|\t\t3-Buscar casa de orgia pelo Id\t\t\t|\n");
    printf("|\t\t4-remover casa de orgia \t\t\t|\n");
    printf("|\t\t5-liberar arvore \t\t\t\t|\n");
    printf("|\t\t0-Sair              \t\t\t\t|\n");
    printf("|===============================================================|\n");

    printf("Entre com uma opcao: ");
    scanf("%d", &opt);
    switch (opt){

      case 1: {
        root = treeInsert(root, houseCreate());
        break;
       }
      case 2:{
        printf("\nSua arvore é: \n\n");
        if (root != NULL)
        {
            printf("\n");
            treeImprimi(root);
            printf("\n");
        } else
        {
            printf("Arvore vazia.\n\n");
        }
        break;
      }
      case 3:{
         int eleBuscado = 0;
          printf("Pesquise por um elemento: ");
          scanf("%d", &eleBuscado);
          NODE *busca = treeSearch(root, eleBuscado);
          if (busca == NULL)
            printf("\ncasa de orgia não encontrada.\n");
            else
            printf("\ncasa de origa encontrada.\n\n");
            treeImprimiOne(busca);
            printf("\n");

        break;
      }
      case 4:{
          int remove;
          printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &remove);
            root = treeRemove(root,remove);
        break;
      }
     case 5:{
          while(root != NULL){
            root = treeFree(root);
          }      
        break;
      }
     case 0:{
          while(root != NULL){
            root = treeFree(root);
          }
        printf("Programa encerrado!\n");
        return 0;
      }
   
     default:{
     printf("opcao invalida\n");
        break;
       }
    
    }
    }
    return 0;
    
}

NODE* treeInitialize() {
    return NULL;
}

HOUSE houseCreate() {
    HOUSE house;
    printf("Digite o Id do casa de orgia: ");
    scanf("%d", &house.id);
    printf("Digite a cidade que a casa de orgia esta localizada: ");
    scanf(" %29[^\n]", house.city);
    for(int i=0; house.city[i]!='\0'; i++){
       house.city[i] = toupper(house.city[i]);
    }
    printf("Digite o bairro que casa de orgia esta localizada: ");
    scanf(" %29[^\n]", house.burgh);
    for(int i=0; house.burgh[i]!='\0'; i++){
       house.burgh[i] = toupper(house.burgh[i]);
    }
    printf("Digite o numero do casa de orgia: ");
    scanf(" %5[^\n]", house.number);
    for(int i=0; house.number[i]!='\0'; i++){
       house.number[i] = toupper(house.number[i]);
    }
    printf("Digite um dia da semana que a casa de orgia fará uma orgia: ");
    scanf(" %19[^\n]", house.days.firstDay);
    for(int i=0; house.days.firstDay[i]!='\0'; i++){
       house.days.firstDay[i] = toupper(house.days.firstDay[i]);
    }
    printf("Digite outro dia da semana que a casa de orgia fará uma orgia: ");
    scanf(" %19[^\n]", house.days.secondDay);
    for(int i=0; house.days.secondDay[i]!='\0'; i++){
       house.days.secondDay[i] = toupper(house.days.secondDay[i]);
    }
    return house;
}

NODE* treeInsert(NODE *root, HOUSE new){
    if (root == NULL){
        NODE *aux = (NODE*) malloc(sizeof(NODE));
        aux->house = new;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else 
    {
        if (new.id >= root->house.id)
        {
            root->right = treeInsert(root->right, new);
        }
        else 
        {
            root->left = treeInsert(root->left, new);
        } 
    }
    
    return root;
}

void treeImprimi(NODE *root){
    
    if (root != NULL)
    {
        printf("Id:\t\t\t %d\n", root->house.id);
        printf("cidade:\t\t\t %s\n", root->house.city);
        printf("bairro:\t\t\t %s\n", root->house.burgh);
        printf("casa:\t\t\t %s\n", root->house.number);
        printf("dias de orgia:\t\t %s, %s\n", root->house.days.firstDay, root->house.days.secondDay);

        treeImprimi(root->left);
        treeImprimi(root->right);
    }
    
}

void treeImprimiOne(NODE *root){

    if (root != NULL)
    {
        printf("Id:\t\t\t %d\n", root->house.id);
        printf("cidade:\t\t\t %s\n", root->house.city);
        printf("bairro:\t\t\t %s\n", root->house.burgh);
        printf("casa:\t\t\t %s\n", root->house.number);
        printf("dias de orgia:\t\t %s, %s\n", root->house.days.firstDay, root->house.days.secondDay);
    }
    
}

NODE* treeFree(NODE *root){
    NODE *aux = root;
    if (aux->left == NULL && aux->right == NULL)
    {
        free(root);
        return NULL;
    } 
    else if (aux->left != NULL && aux->right == NULL)
    {
        treeFree(aux->left);
    }
     else if (aux->left == NULL && aux->right != NULL)
    {
        treeFree(aux->right);
    }
    
}

NODE* treeSearch(NODE *root, int id){
    if (root != NULL){
        if (id == root->house.id)
        {
            return root;
        } else 
        {
            if (id > root->house.id)
            {
                return treeSearch(root->right, id);
            } else 
            {
               return treeSearch(root->left, id);
            }
        }
        return NULL;
    }
}

NODE* treeMin(NODE *root){
    if (root != NULL)
    {
        NODE *aux = root;
        while (aux->left != NULL)
        {
            aux = aux->left;
        }
        return aux;
    }
    return NULL;
}

NODE* treeRemove(NODE *root, int id){
    if (root != NULL){
        if (id > root->house.id)
        {
            root->right = treeRemove(root->right, id);
        } 
        else if (id < root->house.id)
        {
            root->left = treeRemove(root->left, id);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                NODE *aux = root->left;
                free(root);
                return aux;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                NODE *aux = root->right;
                free(root);
                return aux;
            }
            else
            {
                NODE *aux = treeMin(root->right);
                HOUSE houseaux = aux->house;
                root = treeRemove(root,houseaux.id);
                root->house = houseaux;
                
            }
        }
        return root;
    }
    return NULL;
}