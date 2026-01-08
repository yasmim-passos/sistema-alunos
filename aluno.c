#include <string.h>
#include <stdio.h>
#include "aluno.h"
#include "arquivo.h"

void cadastrarAluno(Aluno alunos[], int *total) {
    Aluno a;
    a.matricula = (*total) + 1;

    printf("Nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';

    printf("Nota: ");
    scanf("%f", &a.nota);
    limparBuffer();

    alunos[*total] = a;
    (*total)++;

    salvarAlunos(alunos, *total);
    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno alunos[], int total) {
    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d - %s (Nota: %.2f)\n",
               alunos[i].matricula,
               alunos[i].nome,
               alunos[i].nota);
    }
}

void buscarAluno(Aluno alunos[], int total) {
    int mat;
    printf("Matrícula: ");
    scanf("%d", &mat);
    limparBuffer();

    for (int i = 0; i < total; i++) {
        if (alunos[i].matricula == mat) {
            printf("Aluno encontrado: %s | Nota %.2f\n",
                   alunos[i].nome,
                   alunos[i].nota);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
