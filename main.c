#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"
#define Quantidade_MAX 10

int main(void)
{
    system("cls");
    Aluno *alunos[Quantidade_MAX];          // vetor de ponteiros para Aluno
    int n_alunos = obter_alunos(alunos), i; // vetor preenchido no inicio do programa
    char nome[81];
    int matricula, documento;

    int escolha = 0;
    while (escolha != 3)
    {
        printf("\nMenu:\n");
        printf("1. Cadastrar novo aluno\n");
        printf("2. Listar alunos cadastrados\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            // add um aluno
            if (n_alunos <= Quantidade_MAX - 1)
            {
                // Solicita ao usuário as informações do novo aluno
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]s", nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("Digite o documento do aluno: ");
                scanf("%d", &documento);

                // Cria o novo aluno usando as informações fornecidas pelo usuário
                Aluno *novo_aluno = cria_aluno(nome, matricula, documento);
                alunos[n_alunos++] = novo_aluno;
                atualiza_arquivo(alunos, n_alunos);
            }
            else
            {
                printf("NUMERO MAXIMO DE ALUNOS ATINGIDO\n");
            }
            break;
        case 2:
            /* Funcao de listar */
            exibe_alunos(alunos, n_alunos);
            break;
        case 3:
            printf("Saindo do programa...\n");
            // Liberando a memória alocada para cada aluno
            for (i = 0; i < n_alunos; i++)
            {
                free_aluno(alunos[i]);
            }
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    }
    return 0;
}
