#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

#define ARQUIVO "data/alunos.txt"

void salvarAlunos(Aluno alunos[], int total) {
    FILE *f = fopen(ARQUIVO, "w");
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%d;%s;%.2f\n",
                alunos[i].matricula,
                alunos[i].nome,
                alunos[i].nota);
    }

    fclose(f);
}

int carregarAlunos(Aluno alunos[]) {
    FILE *f = fopen(ARQUIVO, "r");
    if (!f) return 0;

    int total = 0;
    while (fscanf(f, "%d;%99[^;];%f\n",
                  &alunos[total].matricula,
                  alunos[total].nome,
                  &alunos[total].nota) != EOF) {
        total++;
    }

    fclose(f);
    return total;
}
