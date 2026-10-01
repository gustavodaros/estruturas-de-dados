#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct ListaSimples {
    No *primeiro;
    No *ultimo;
} ListaSimples;

ListaSimples *criar() 
{
    ListaSimples *lista = (ListaSimples*)malloc(sizeof(ListaSimples));
    if(lista == NULL) return NULL;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

No *inserir_inicio(ListaSimples *lista, int dado)
{
    No *novo=(No*)malloc(sizeof(No));
    if(novo==NULL) return NULL;
    novo->dado = dado;
    novo->proximo = NULL;
    if(lista->primeiro == NULL) 
    {
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else
    {
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
    }
    return novo;
}

void imprimir_lista(ListaSimples *lista)
{
    if(lista->primeiro == NULL)
    {
        printf("Lista vazia");
        return;
    }
    No *atual = lista->primeiro;
    while(atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void rotacionar(ListaSimples *lista, int k)
{
    if(lista == NULL || lista->primeiro == NULL || lista->primeiro == lista->ultimo || k <= 0) 
    {
        return;
    }
    for(int i = 0; i < k; i++)
    {
        No *percorrer = lista->primeiro;
        No *prim = lista->primeiro;
        No *ult = lista->ultimo;
        while(percorrer->proximo != lista->ultimo)
        {
            percorrer = percorrer->proximo;
        }
        lista->primeiro = ult;
        ult->proximo = prim;
        lista->ultimo = percorrer;
        percorrer->proximo = NULL;
    }
}

int main()
{
    ListaSimples *lista = criar();

    inserir_inicio(lista, 6);
    inserir_inicio(lista, 5);
    inserir_inicio(lista, 4);
    inserir_inicio(lista, 3);
    inserir_inicio(lista, 2);
    inserir_inicio(lista, 1);

    printf("Lista antes da rotação à direita: \n");
    imprimir_lista(lista);

    rotacionar(lista, 2);

    printf("Lista depois da rotação à direita: \n");
    imprimir_lista(lista);

    return 0;
}