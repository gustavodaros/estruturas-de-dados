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

ListaSimples *juntar(ListaSimples *lista1, ListaSimples *lista2)
{
    ListaSimples *resultado = (ListaSimples*)malloc(sizeof(ListaSimples));
    if(resultado == NULL) return NULL;
    resultado->primeiro = NULL;
    resultado->ultimo = NULL;
    No *atual1 = lista1->primeiro;
    No *atual2 = lista2->primeiro;
    if(atual1->dado <= atual2->dado)
    {
        resultado->primeiro = lista1->primeiro;
        resultado->ultimo = lista1->primeiro;
        atual1 = atual1->proximo;
    }
    else
    {
        resultado->primeiro = lista2->primeiro;
        resultado->ultimo = lista2->primeiro;
        atual2 = atual2->proximo;
    }
    No *res = resultado->primeiro;
    while(atual1 != NULL && atual2 != NULL)
    {
        if(atual1->dado <= atual2->dado)
        {
            res->proximo = atual1;
            atual1 = atual1->proximo;
        }
        else
        {
            res->proximo = atual2;
            atual2 = atual2->proximo;
        }
        res = res->proximo;
    }
    if(atual1 == NULL)
    {
        while(atual2 != NULL)
        {
            res->proximo = atual2;
            atual2 = atual2->proximo;
            res = res->proximo;
        }
    }
    else if(atual2 == NULL)
    {
        while(atual1 != NULL)
        {
            res->proximo = atual1;
            atual1 = atual1->proximo;
            res = res->proximo;
        }
    }
    resultado->ultimo = res;
    res->proximo = NULL;

    return resultado;
}

int main()
{
    ListaSimples *lista1 = criar();
    ListaSimples *lista2 = criar();

    inserir_inicio(lista1, 9);
    inserir_inicio(lista1, 8);
    inserir_inicio(lista1, 5);
    inserir_inicio(lista1, 2);
    inserir_inicio(lista2, 8);
    inserir_inicio(lista2, 6);
    inserir_inicio(lista2, 4);
    inserir_inicio(lista2, 3);
    inserir_inicio(lista2, 1);

    printf("Listas antes da ordenação par-ímpar: \n");
    imprimir_lista(lista1);
    imprimir_lista(lista2);

    ListaSimples *resultado = juntar(lista1, lista2);

    printf("Lista depois da ordenação par-ímpar: ");
    imprimir_lista(resultado);

    return 0;
}