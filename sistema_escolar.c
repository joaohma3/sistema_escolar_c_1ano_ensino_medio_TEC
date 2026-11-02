#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 30
#define MAX_OCORRENCIAS 100

struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
    int notasRegistradas;
};

struct Ocorrencia {
    int matriculaAluno;
    char data[11];
    char descricao[200];
};

int buscarAlunoPorMatricula(struct Aluno alunos[], int totalAlunos, int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

int matriculaJaExiste(struct Aluno alunos[], int totalAlunos, int matricula) {
    return buscarAlunoPorMatricula(alunos, totalAlunos, matricula) != -1;
}

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    struct Ocorrencia ocorrencias[MAX_OCORRENCIAS];

    int totalAlunos = 0;
    int totalOcorrencias = 0;

    int opcao;
    int matriculaBusca;
    int indiceAluno;

    while (1) {
        printf("\n========================================\n");
        printf("      SISTEMA DE GERENCIAMENTO ESCOLAR\n");
        printf("========================================\n");
        printf("1  - Cadastrar aluno\n");
        printf("2  - Listar alunos\n");
        printf("3  - Buscar aluno\n");
        printf("4  - Registrar notas\n");
        printf("5  - Consultar notas\n");
        printf("6  - Mostrar situacao do aluno\n");
        printf("7  - Registrar ocorrencia\n");
        printf("8  - Consultar ocorrencias\n");
        printf("9  - Estatisticas da turma\n");
        printf("10 - Sair\n");

        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida. Digite apenas numeros.\n");
            limparEntrada();
            continue;
        }

        switch (opcao) {
            case 1: {
                if (totalAlunos >= MAX_ALUNOS) {
                    printf("\nLimite de alunos atingido!\n");
                    break;
                }

                printf("\n===== CADASTRAR ALUNO =====\n");

                printf("Matricula: ");
                scanf("%d", &alunos[totalAlunos].matricula);

                if (matriculaJaExiste(alunos, totalAlunos, alunos[totalAlunos].matricula)) {
                    printf("\nJa existe um aluno com essa matricula.\n");
                    break;
                }

                printf("Nome: ");
                scanf(" %49[^\n]", alunos[totalAlunos].nome);

                alunos[totalAlunos].nota1 = 0;
                alunos[totalAlunos].nota2 = 0;
                alunos[totalAlunos].nota3 = 0;
                alunos[totalAlunos].media = 0;
                alunos[totalAlunos].notasRegistradas = 0;

                totalAlunos++;

                printf("\nAluno cadastrado com sucesso!\n");
                break;
            }

            case 2: {
                printf("\n===== ALUNOS CADASTRADOS =====\n");

                if (totalAlunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }

                for (int i = 0; i < totalAlunos; i++) {
                    printf("\nAluno %d\n", i + 1);
                    printf("Matricula: %d\n", alunos[i].matricula);
                    printf("Nome: %s\n", alunos[i].nome);
                }
                break;
            }

            case 3: {
                printf("\n===== BUSCAR ALUNO =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                } else {
                    printf("\nAluno encontrado!\n");
                    printf("Matricula: %d\n", alunos[indiceAluno].matricula);
                    printf("Nome: %s\n", alunos[indiceAluno].nome);
                }
                break;
            }

            case 4: {
                printf("\n===== REGISTRAR NOTAS =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                    break;
                }

                printf("\nAluno: %s\n", alunos[indiceAluno].nome);

                printf("Nota 1: ");
                scanf("%f", &alunos[indiceAluno].nota1);

                printf("Nota 2: ");
                scanf("%f", &alunos[indiceAluno].nota2);

                printf("Nota 3: ");
                scanf("%f", &alunos[indiceAluno].nota3);

                if (alunos[indiceAluno].nota1 < 0 || alunos[indiceAluno].nota1 > 10 ||
                    alunos[indiceAluno].nota2 < 0 || alunos[indiceAluno].nota2 > 10 ||
                    alunos[indiceAluno].nota3 < 0 || alunos[indiceAluno].nota3 > 10) {

                    printf("\nErro: as notas devem estar entre 0 e 10.\n");

                    alunos[indiceAluno].nota1 = 0;
                    alunos[indiceAluno].nota2 = 0;
                    alunos[indiceAluno].nota3 = 0;
                    alunos[indiceAluno].media = 0;
                    alunos[indiceAluno].notasRegistradas = 0;

                    break;
                }

                alunos[indiceAluno].media =
                    (alunos[indiceAluno].nota1 +
                     alunos[indiceAluno].nota2 +
                     alunos[indiceAluno].nota3) / 3.0f;

                alunos[indiceAluno].notasRegistradas = 1;

                printf("\nNotas registradas com sucesso!\n");
                printf("Media calculada: %.2f\n", alunos[indiceAluno].media);

                break;
            }

            case 5: {
                printf("\n===== CONSULTAR NOTAS =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                    break;
                }

                printf("\nAluno: %s\n", alunos[indiceAluno].nome);

                if (!alunos[indiceAluno].notasRegistradas) {
                    printf("As notas deste aluno ainda nao foram registradas.\n");
                    break;
                }

                printf("Nota 1: %.2f\n", alunos[indiceAluno].nota1);
                printf("Nota 2: %.2f\n", alunos[indiceAluno].nota2);
                printf("Nota 3: %.2f\n", alunos[indiceAluno].nota3);
                printf("Media: %.2f\n", alunos[indiceAluno].media);

                break;
            }

            case 6: {
                printf("\n===== SITUACAO DO ALUNO =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                    break;
                }

                printf("\nAluno: %s\n", alunos[indiceAluno].nome);

                if (!alunos[indiceAluno].notasRegistradas) {
                    printf("Nao e possivel calcular a situacao: notas ainda nao registradas.\n");
                    break;
                }

                printf("Media: %.2f\n", alunos[indiceAluno].media);

                if (alunos[indiceAluno].media >= 7.0f) {
                    printf("Situacao: APROVADO\n");
                } else if (alunos[indiceAluno].media >= 5.0f) {
                    printf("Situacao: RECUPERACAO\n");
                } else {
                    printf("Situacao: REPROVADO\n");
                }

                break;
            }

            case 7: {
                if (totalOcorrencias >= MAX_OCORRENCIAS) {
                    printf("\nLimite de ocorrencias atingido!\n");
                    break;
                }

                printf("\n===== REGISTRAR OCORRENCIA =====\n");
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                    break;
                }

                printf("\nAluno: %s\n", alunos[indiceAluno].nome);

                ocorrencias[totalOcorrencias].matriculaAluno = matriculaBusca;

                printf("Data (DD/MM/AAAA): ");
                scanf(" %10[^\n]", ocorrencias[totalOcorrencias].data);

                printf("Descricao da ocorrencia: ");
                scanf(" %199[^\n]", ocorrencias[totalOcorrencias].descricao);

                totalOcorrencias++;

                printf("\nOcorrencia registrada com sucesso!\n");

                break;
            }

            case 8: {
                printf("\n===== CONSULTAR OCORRENCIAS =====\n");
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matriculaBusca);

                indiceAluno = buscarAlunoPorMatricula(alunos, totalAlunos, matriculaBusca);

                if (indiceAluno == -1) {
                    printf("\nAluno nao encontrado.\n");
                    break;
                }

                printf("\nAluno: %s\n", alunos[indiceAluno].nome);
                printf("Matricula: %d\n", alunos[indiceAluno].matricula);

                int quantidade = 0;

                for (int i = 0; i < totalOcorrencias; i++) {
                    if (ocorrencias[i].matriculaAluno == matriculaBusca) {
                        quantidade++;

                        printf("\nOcorrencia %d\n", quantidade);
                        printf("Data: %s\n", ocorrencias[i].data);
                        printf("Descricao: %s\n", ocorrencias[i].descricao);
                    }
                }

                if (quantidade == 0) {
                    printf("\nNenhuma ocorrencia encontrada para este aluno.\n");
                } else {
                    printf("\nTotal de ocorrencias: %d\n", quantidade);
                }

                break;
            }

            case 9: {
                printf("\n===== ESTATISTICAS DA TURMA =====\n");
                printf("Total de alunos cadastrados: %d\n", totalAlunos);
                printf("Total de ocorrencias registradas: %d\n", totalOcorrencias);

                if (totalAlunos == 0) {
                    printf("Nao ha alunos cadastrados para calcular estatisticas.\n");
                    break;
                }

                float somaMedias = 0.0f;
                int alunosComNotas = 0;
                int aprovados = 0;
                int recuperacao = 0;
                int reprovados = 0;

                float maiorMedia = -1.0f;
                float menorMedia = 11.0f;
                int indiceMaiorMedia = -1;
                int indiceMenorMedia = -1;

                int maiorQtdOcorrencias = -1;
                int indiceMaiorOcorrencias = -1;

                for (int i = 0; i < totalAlunos; i++) {
                    if (alunos[i].notasRegistradas) {
                        somaMedias += alunos[i].media;
                        alunosComNotas++;

                        if (alunos[i].media >= 7.0f) {
                            aprovados++;
                        } else if (alunos[i].media >= 5.0f) {
                            recuperacao++;
                        } else {
                            reprovados++;
                        }

                        if (alunos[i].media > maiorMedia) {
                            maiorMedia = alunos[i].media;
                            indiceMaiorMedia = i;
                        }

                        if (alunos[i].media < menorMedia) {
                            menorMedia = alunos[i].media;
                            indiceMenorMedia = i;
                        }
                    }

                    int qtdOcorrenciasAluno = 0;

                    for (int j = 0; j < totalOcorrencias; j++) {
                        if (ocorrencias[j].matriculaAluno == alunos[i].matricula) {
                            qtdOcorrenciasAluno++;
                        }
                    }

                    if (qtdOcorrenciasAluno > maiorQtdOcorrencias) {
                        maiorQtdOcorrencias = qtdOcorrenciasAluno;
                        indiceMaiorOcorrencias = i;
                    }
                }

                if (alunosComNotas > 0) {
                    printf("\nMedia geral da turma: %.2f\n", somaMedias / alunosComNotas);
                    printf("Aprovados: %d\n", aprovados);
                    printf("Recuperacao: %d\n", recuperacao);
                    printf("Reprovados: %d\n", reprovados);

                    printf("\nMaior media: %.2f - %s\n",
                           maiorMedia,
                           alunos[indiceMaiorMedia].nome);

                    printf("Menor media: %.2f - %s\n",
                           menorMedia,
                           alunos[indiceMenorMedia].nome);
                } else {
                    printf("\nNenhum aluno possui notas registradas.\n");
                }

                if (indiceMaiorOcorrencias != -1) {
                    printf("\nAluno com mais ocorrencias: %s\n",
                           alunos[indiceMaiorOcorrencias].nome);

                    printf("Quantidade de ocorrencias: %d\n",
                           maiorQtdOcorrencias);
                }

                break;
            }

            case 10:
                printf("\nSistema encerrado.\n");
                return 0;

            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}
