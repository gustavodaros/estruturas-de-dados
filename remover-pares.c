#include <stdio.h>
#include <stdlib.h>

typedef struct VetorDinamico {
    int tamanho;
    int capacidade;
    int *elementos;
} VetorDinamico;

VetorDinamico *criar(int inicial)
{
    VetorDinamico *vetor = (VetorDinamico*)malloc(sizeof(VetorDinamico));
    if(vetor == NULL) return NULL;
    vetor->tamanho = 0;
    vetor->capacidade = inicial;
    vetor->elementos = (int*)malloc(inicial*sizeof(int));
    if(vetor->elementos == NULL) return NULL;
    return vetor;
}

void inserir(VetorDinamico *vetor, int posicao, int elemento)
{
    if(vetor == NULL || posicao < 0 || posicao > vetor->tamanho) return;
    if(vetor->tamanho == vetor->capacidade)
    {
        int nova = 2*vetor->capacidade;
        int *novo = (int*)realloc(vetor->elementos, nova*sizeof(int));
        if(novo == NULL) return;
        vetor->capacidade = nova;
        vetor->elementos = novo;
    }
    for(int i = vetor->tamanho; i > posicao; i--) vetor->elementos[i] = vetor->elementos[i-1];
    vetor->elementos[posicao] = elemento;
    vetor->tamanho++;
}

void imprimir(VetorDinamico *vetor)
{
    if(vetor == NULL) return;
    if(vetor->tamanho == 0)
    {
        printf("Vetor vazio\n");
        return;
    }
    for(int i=0; i<vetor->tamanho; i++)
    {
        printf("%d ", vetor->elementos[i]);
    }
    printf("\n");
    return;
}

void remover_pares(VetorDinamico *vetor)
{
    if(vetor == NULL) return;
    int i=0;
    while (i<vetor->tamanho)
    {
        if(vetor->elementos[i]%2 == 0)
        {
            for(int j=i; j<vetor->tamanho-1; j++) vetor->elementos[j]=vetor->elementos[j+1];
            vetor->tamanho--;
        }
        else i++;
    }
}

int main()
{
    VetorDinamico *vetor = criar(9);
    inserir(vetor, 0, 9);
    inserir(vetor, 1, 3);
    inserir(vetor, 2, 8);
    inserir(vetor, 3, 2);
    inserir(vetor, 4, 5);
    inserir(vetor, 5, 6);
    inserir(vetor, 6, 7);
    inserir(vetor, 7, 4);
    inserir(vetor, 8, 1);

    printf("Vetor antes da remoção dos pares\n");
    imprimir(vetor);

    remover_pares(vetor);

    printf("Vetor depois da remoção dos pares\n");
    imprimir(vetor);

    return 0;
}





















