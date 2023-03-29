#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#define TAM 100

struct aluno
{
    char nome[91];
    int matricula;
    int documento;
};
Aluno *cria_aluno(char *nome, int matricula, int documento)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    // Verifica a alocação
    if (aluno == NULL)
    {
        printf("ERRO, MEMORIA INSUFICIENTE!\n");
        exit(1);
    }
}

int obter_alunos(Aluno **alunos)
{
    FILE *arquivo_origem;
    char linha[TAM], nome[91];
    int matricula, documento, i = 0, linhas = 0;
}

void trocar(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(char **arr, int baixo, int alto)
{
    char *pivo = arr[alto]; // escolhe o pivo como o ultimo elemento
    int i = baixo - 1;      // indice do menor elemento

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (strcmp(arr[j], pivo) < 0)
        {
            i++; // incrementa o indice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quick_sort(char **arr, int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

void free_aluno(Aluno *aluno)
{
    free(aluno);
}
