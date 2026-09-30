#include <stdio.h>
#include <stdlib.h>

typedef struct VetorDinamico {
    int tamanho;
    int capacidade;
    int *elementos;
} VetorDinamico;

typedef struct VetorResultante {
    VetorDinamico *vetor_resultante;
    int tamanho;
} VetorResultante;

VetorDinamico *criar(int inicial)
{
    VetorDinamico *vetor = (VetorDinamico*)malloc(sizeof(VetorDinamico));
    if(vetor == NULL) return NULL;
    vetor->tamanho = 0;
    vetor->capacidade = inicial;
    vetor->elementos = (int*)malloc(inicial*sizeof(int));
    if(vetor->elementos == NULL)
    {
        free(vetor);
        return NULL;
    }
    return vetor;
}

void inserir(VetorDinamico *vetor, int posicao, int elemento)
{
    if(vetor == NULL || posicao < 0 || posicao > vetor->tamanho)
    {
        printf("Posição inválida\n");
        return;
    }
    if(vetor->tamanho == vetor->capacidade)
    {
        int nova = 2 * vetor->capacidade;
        int *novo = (int*)realloc(vetor->elementos, nova*sizeof(int));
        if(novo == NULL) 
        {
            printf("Erro ao realocar memória\n");
            return;
        }
        vetor->capacidade = nova;
        vetor->elementos = novo;
    }
    for(int i = vetor->tamanho; i > posicao; i--) vetor->elementos[i] = vetor->elementos[i-1];
    vetor->elementos[posicao] = elemento;
    vetor->tamanho++;
}

void imprimir(VetorDinamico *vetor) 
{
    if (vetor->tamanho == 0) {
        printf("Vetor está vazio.\n");
        return;
    }
    for (int i = 0; i < vetor->tamanho; i++) {
        printf("%d ", vetor->elementos[i]);
    }
    printf("\n");
}

void imprimir_resultante(VetorResultante *novo) 
{
    if(novo == NULL)
    {
        printf("Vetor resultante vazio.\n");
        return;
    }
    if (novo->vetor_resultante->tamanho == 0) 
    {
        printf("Vetor está vazio.\n");
        return;
    }
    printf("Elementos do vetor resultante: ");
    for (int i = 0; i < novo->vetor_resultante->tamanho; i++) printf("%d ", novo->vetor_resultante->elementos[i]);
    printf("\n");
}

VetorResultante *mesclar_vetores(VetorDinamico *vetor1, VetorDinamico *vetor2, int tam1, int tam2, int min, int max)
{
    int cap = tam1 + tam2;
    VetorDinamico *vetor3 = (VetorDinamico*)malloc(sizeof(VetorDinamico));
    if(vetor3 == NULL) return NULL;
    vetor3->capacidade = cap;
    vetor3->elementos = (int*)malloc(cap*sizeof(int));
    if(vetor3->elementos == NULL)
    {
        free(vetor3);
        return NULL;
    }
    vetor3->tamanho = 0;

    for(int i = 0; i < vetor1->tamanho; i++)
    {
        if(vetor1->elementos[i] >= min && vetor1->elementos[i] <= max)
        {
            int controle = 0;
            for(int j = 0; j < vetor3->tamanho; j++)
            {
                if(vetor3->elementos[j] == vetor1->elementos[i]) 
                {
                    controle = 1;
                    break;
                }
            }
            if(!controle)
            {
                vetor3->elementos[vetor3->tamanho] = vetor1->elementos[i];
                vetor3->tamanho++;
            }
        }
    }
    for(int i = 0; i < vetor2->tamanho; i++)
    {
        if(vetor2->elementos[i] >= min && vetor2->elementos[i] <= max)
        {
            int controle = 0;
            for(int j = 0; j < vetor3->tamanho; j++)
            {
                if(vetor3->elementos[j] == vetor2->elementos[i]) 
                {
                    controle = 1;
                    break;
                }
            }
            if(!controle)
            {
                vetor3->elementos[vetor3->tamanho] = vetor2->elementos[i];
                vetor3->tamanho++;
            }
        }
    }
    if(vetor3->tamanho == 0)
    {
        free(vetor3->elementos);
        free(vetor3);
        return NULL;
    }
    int *novo_elementos = (int*)realloc(vetor3->elementos, vetor3->tamanho*sizeof(int));
    if(novo_elementos != NULL) vetor3->elementos = novo_elementos;  

    VetorResultante *novo = (VetorResultante*)malloc(sizeof(VetorResultante));
    if(novo == NULL)
    {
        free(vetor3->elementos);
        free(vetor3);
        return NULL;
    }   
    novo->vetor_resultante = vetor3;
    novo->tamanho = vetor3->tamanho;
    return novo;
}

int main()
{
    VetorDinamico *vetor1 = criar(6);
    VetorDinamico *vetor2 = criar(6);
    VetorResultante *novo;

    inserir(vetor1, 0, 2);
    inserir(vetor1, 1, 5);
    inserir(vetor1, 2, 8);
    inserir(vetor1, 3, 12);
    inserir(vetor1, 4, 15);
    inserir(vetor1, 5, 20);

    printf("Elementos do primeiro vetor: ");
    imprimir(vetor1);

    inserir(vetor2, 0, 3);
    inserir(vetor2, 1, 5);
    inserir(vetor2, 2, 7);
    inserir(vetor2, 3, 10);
    inserir(vetor2, 4, 15);
    inserir(vetor2, 5, 18);

    printf("Elementos do segundo vetor: ");
    imprimir(vetor2);

    novo = mesclar_vetores(vetor1, vetor2, 6, 6, 3, 18);
    imprimir_resultante(novo);

    return 0;
}