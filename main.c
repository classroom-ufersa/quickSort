#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void quicksort(char **arr, int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}
