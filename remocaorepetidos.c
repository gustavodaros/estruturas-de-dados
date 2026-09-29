#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

typedef struct ListaSimples
{
    No *primeiro;
    No *ultimo;
} ListaSimples;

ListaSimples *criar()
{
    ListaSimples *lista = (ListaSimples*)malloc(sizeof(ListaSimples));
    if (lista == NULL)
        return NULL;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

No *inserir_inicio(ListaSimples *lista, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return NULL;
    novo->dado = dado;
    novo->proximo = NULL;
    if (lista->primeiro == NULL)
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
    if (lista->primeiro == NULL)
    {
        printf("Lista vazia");
        return;
    }
    No *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void remocao_repetidos(ListaSimples *lista)
{
    No *atual = lista->primeiro;
    while (atual != NULL)
    {
        No *comparado = atual->proximo;
        while (comparado != NULL)
        {
            if (atual->dado == comparado->dado)
            {
                No *anterior = atual;

                while(anterior->proximo != comparado) anterior = anterior->proximo;

                anterior->proximo = comparado->proximo;
                free(comparado);
                comparado = anterior->proximo;
            }
            else comparado = comparado->proximo;
        }
        atual = atual->proximo;
    }
}

int main()
{
    ListaSimples *Lista = criar();

    inserir_inicio(Lista, 4);
    inserir_inicio(Lista, 5);
    inserir_inicio(Lista, 8);
    inserir_inicio(Lista, 3);
    inserir_inicio(Lista, 5);
    inserir_inicio(Lista, 8);
    inserir_inicio(Lista, 8);
    inserir_inicio(Lista, 1);

    printf("Lista antes da remoção dos algarismos repetidos: ");
    imprimir_lista(Lista);

    remocao_repetidos(Lista);

    printf("Lista depois da remoção dos algarismos repetidos: ");
    imprimir_lista(Lista);

    return 0;
}