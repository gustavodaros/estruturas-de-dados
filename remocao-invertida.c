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

void remocao_invertida(ListaSimples *lista, int n)
{
    No *atual = lista->primeiro;
    No *anterior = NULL;
    int c=1, i=1;
    while(atual != NULL)
    {
        atual = atual->proximo;
        c++;
    }
    atual = lista->primeiro;
    while(i < c-n)
    {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
    if(anterior == NULL)
    {
        lista->primeiro = atual->proximo;
        free(atual);
    }
    else
    {
        anterior->proximo = atual->proximo;
        if(atual == lista->ultimo) lista->ultimo = anterior;
        free(atual);
    }
}

int main()
{
    ListaSimples *lista = criar();

    inserir_inicio(lista, 9);
    inserir_inicio(lista, 8);
    inserir_inicio(lista, 6);
    inserir_inicio(lista, 5);
    inserir_inicio(lista, 4);
    inserir_inicio(lista, 3);
    inserir_inicio(lista, 2);
    inserir_inicio(lista, 1);

    printf("Lista antes da remoção: \n");
    imprimir_lista(lista);

    remocao_invertida(lista, 3);

    printf("Lista depois da remoção: \n");
    imprimir_lista(lista);

    return 0;
}