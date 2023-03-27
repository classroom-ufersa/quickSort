typedef struct aluno Aluno;

Aluno *cria_aluno(char *nome, int matricula, int documento);
int obter_alunos(Aluno **alunos);
int particionar(char **arr, int baixo, int alto);
void trocar(char **a, char **b);
void exibe_alunos(Aluno **alunos, int n_alunos);
void free_aluno(Aluno *aluno);
void quick_sort(char **arr, int baixo, int alto);
void ordena_alunos(Aluno **alunos, int n_alunos);
void atualiza_arquivo(Aluno **alunos, int n_alunos);