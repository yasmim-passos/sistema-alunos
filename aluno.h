#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;

void cadastrarAluno(Aluno alunos[], int *total);
void listarAlunos(Aluno alunos[], int total);
void buscarAluno(Aluno alunos[], int total);
void limparBuffer();

#endif
