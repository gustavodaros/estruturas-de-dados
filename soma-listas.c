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

ListaSimples *soma_listas(ListaSimples *lista1, ListaSimples *lista2)
{
    ListaSimples *res = (ListaSimples*)malloc(sizeof(ListaSimples));
    if(res == NULL) return NULL;
    res->primeiro = NULL;
    res->ultimo = NULL;
    No *atual1 = lista1->primeiro;
    No *atual2 = lista2->primeiro;
    int i=0;

    while(atual1 != NULL || atual2 != NULL || i != 0)
    {
        int soma = i;
        if(atual1 != NULL)
        {
            soma+=atual1->dado;
            atual1 = atual1->proximo;
        }
        if(atual2 != NULL)
        {
            soma+=atual2->dado;
            atual2 = atual2->proximo;
        }

        No *novo = (No*)malloc(sizeof(No));
        if(novo == NULL) return res;
        novo->dado = soma%10;
        novo->proximo = NULL;

        if(res->primeiro == NULL) res->primeiro = novo;
        else res->ultimo->proximo = novo;

        res->ultimo = novo;
        i = soma/10;
    }

    return res;
}

int main()
{
    ListaSimples *lista1 = criar();
    ListaSimples *lista2 = criar();

    inserir_inicio(lista1, 3);
    inserir_inicio(lista1, 6);
    inserir_inicio(lista1, 2);
    inserir_inicio(lista2, 5);
    inserir_inicio(lista2, 4);
    inserir_inicio(lista2, 6);

    printf("Listas antes da soma: \n");
    imprimir_lista(lista1);
    imprimir_lista(lista2);

    ListaSimples *resultado = soma_listas(lista1, lista2);

    printf("Lista depois da soma: \n");
    imprimir_lista(resultado);

    return 0;
}