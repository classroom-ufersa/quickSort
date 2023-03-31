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
    printf("Nome        \t\tMatricula       \tDocumento\n");
    for (i = 0; i < n_alunos; i++)
    {
        printf("%d - %s\t\t%d\t\t\t%d\n", i + 1, alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
    }
}
void free_aluno(Aluno *aluno)
{
    free(aluno);
}

// função de particionamento
int partition(char **arr, int low, int high)
{
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (strcmp(arr[j], pivot) <= 0)
        {
            i++;
            // troca arr[i] com arr[j]
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // troca arr[i+1] com arr[high]
    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// função QuickSort
void quickSort(char **arr, int low, int high)
{
    clock_t start = 000, end;
    double tempo_execucao;
    if (low < high)
    {
        // index é o índice da partição
        int index = partition(arr, low, high);
        // ordena a sublista à esquerda da partição
        quickSort(arr, low, index - 1);
        // ordena a sublista à direita da partição
        quickSort(arr, index + 1, high);
    }
    end = clock();                                                // Armazena o horario de termino da funcao
    tempo_execucao = ((double)(end - start)) / CLOCKS_PER_SEC;    // Calcula o tempo de execucao da funcao
    printf("Tempo de execucao: %.2f segundos\n", tempo_execucao); // Exibindo o tempo de execucao da funcao
}

/*
   Pior e Medio quicksort
   T(n) = O(nlogn)
   Melhor quicksort
   T(n) = O(n²)
*/

void ordena_alunos(Aluno **alunos, int n_alunos)
{
    Aluno *aux;
    int i, j;
    char *iniciais[n_alunos];

    for (i = 0; i < n_alunos; i++)
    {
        iniciais[i] = &(alunos[i]->nome[0]);
    }

    quickSort(iniciais, 0, n_alunos - 1);

    for (i = 0; i < n_alunos; i++)
    {
        for (j = i + 1; j < n_alunos; j++)
        {
            if (iniciais[i] == &(alunos[j]->nome[0]))
            {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
                break;
            }
        }
    }
}

void atualiza_arquivo(Aluno **alunos, int n_alunos)
{
    int i;
    FILE *arquivo;
    arquivo = fopen("dados_alunos.txt", "w"); // Abre o arquivo para escrita

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    ordena_alunos(alunos, n_alunos);

    for (i = 0; i < n_alunos; i++)
    {
        if (i == n_alunos - 1)
        {
            fprintf(arquivo, "%s;%d;%d", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        }
        else
        {
            fprintf(arquivo, "%s;%d;%d\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        }
    }

    fclose(arquivo); // Fecha o arquivo
    printf("Arquivo atualizado!\n");
}
