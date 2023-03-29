#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "aluno.h"
#define TAM_LINHA 100

struct aluno
{
    char nome[51];
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
    nome[0] = toupper(nome[0]);
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->documento = documento;

    printf("Aluno criado com sucesso!\n");
    return aluno;
}

int obter_alunos(Aluno **alunos)
{
    FILE *arquivo_origem;
    char linha[TAM_LINHA], nome[91];
    int matricula, documento, i = 0, linhas = 0;
    ;

    arquivo_origem = fopen("dados_alunos.txt", "r"); // Abre o arquivo_origem para leitura
    if (arquivo_origem == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL)
    {
        Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
        sscanf(linha, " %[^;];%d;%d", nome, &matricula, &documento); // Resgata as informações do aluno
        strcpy(aluno->nome, nome);
        aluno->matricula = matricula;
        aluno->documento = documento;
        alunos[i++] = aluno; // Inclui um ponteiro de Aluno para o vetor
        linhas++;
    }
    fclose(arquivo_origem); // Fecha o arquivo

    return linhas;
}

void exibe_alunos(Aluno **alunos, int n_alunos)
{
    int i;
    printf("----------ALUNOS----------\n");
    printf("Nome        Matricula       Documento\n");
    for (i = 0; i < n_alunos; i++)
    {
        printf("%d - %s\t\t%d\t%d\n", i + 1, alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
    }
}
void free_aluno(Aluno *aluno)
{
    free(aluno);
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
    clock_t inicio, fim;
    double tempo_execucao;

    // Inicio da funcao quick_sort
    inicio = clock(); // Armazena o horario de inicio da funcao
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quick_sort(arr, baixo, pi - 1);
        quick_sort(arr, pi + 1, alto);
    }
    fim = clock();                                                // Armazena o horario de termino da funcao
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;   // Calcula o tempo de execucao da funcao
    printf("Tempo de execucao: %.2f segundos\n", tempo_execucao); // Exibindo o tempo de execucao da funcao
}
