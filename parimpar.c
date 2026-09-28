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

void ordenar(ListaSimples *lista)
{
    No *atual = lista->primeiro;
    No *anterior = NULL;
    No *ultimo_original = lista->ultimo;
    while(atual != NULL)
    {
        No *proximo = atual->proximo;
        if((atual->dado)%2 != 0) 
        {
            if(anterior == NULL) lista->primeiro = proximo;
            else anterior->proximo = proximo;

            atual->proximo = NULL;
            lista->ultimo->proximo = atual;
            lista->ultimo = atual;
        }
        else anterior = atual;
        if(atual == ultimo_original) break;
        atual = proximo;
    }
}

int main()
{
    ListaSimples *Lista = criar();

    inserir_inicio(Lista, 1);
    inserir_inicio(Lista, 9);
    inserir_inicio(Lista, 6);
    inserir_inicio(Lista, 8);
    inserir_inicio(Lista, 2);
    inserir_inicio(Lista, 3);
    inserir_inicio(Lista, 7);
    inserir_inicio(Lista, 4);

    printf("Lista antes da ordenação par-ímpar: ");
    imprimir_lista(Lista);

    ordenar(Lista);

    printf("Lista depois da ordenação par-ímpar: ");
    imprimir_lista(Lista);

    return 0;
}