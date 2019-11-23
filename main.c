//Henrique Barros de Almeida e Lucas Abrahao

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void gerenciador();

void Manipulacao();

void gerenciador() {
    printf("1 - Manipulacao da Tabela de Processos \n");
    printf("2 - Escalonamento \n");
    printf("3 - Copyright \n");
    printf("0 - Encerrar \n");
}

void Manipulacao() {
    printf("1 - Criar Processo\n");
    printf("2 - Alterar Processo\n");
    printf("3 - Remover Processo\n");
    printf("4 - Listar Tabela\n");
    printf("5 - Limpar a Tabela\n");
    printf("0 - Retornar ao Menu Principal\n");
}


int main() {
    int opcao = 0, opcao2 = 0, i = 0, max = 0, e, remover = 0, x = 0, p = 0, q = 0, r = 0, maior = 0, i_anterior = 0;
    int exec[7], pid[7], fim[7];
    char nome[7][10];
    char provisorio[7][10];
    gerenciador_menu:
    system("clear");
    printf("SIMULADOR DE GERNCIAMENTO DA FILA DE PRONTOS \n");
    gerenciador();
    printf("-> ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        manipulador_menu:
        system("clear");
        Manipulacao();
        printf("-> ");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            menu_cadastro:
            if (max < 7) {
                system("clear");
                printf("Criar Processo");
                printf("\nDigite o nome do processo: ");
                scanf("%s", nome[i]);
                printf("Digite a quantidade de execucoes: ");
                scanf("%d", &exec[i]);
                pid[i] = 100 + i;
                i++;
                max++;
                printf("\n1 - Criar outro processo\n");
                printf("2 - Retornar ao Simulador de gerenciamento\n");
                printf("3 - Retornar ao Menu de manipulacao\n");
                printf("-> ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    goto menu_cadastro;
                } else if (opcao == 2) {
                    goto gerenciador_menu;
                } else {
                    goto manipulador_menu;
                }
            } else if (max >= 7) {
                system("clear");
                printf("Maximo de processos\n");
                printf("1 - Retornar ao Simulador de gerenciamento\n");
                printf("2 - Retornar ao Menu de manipulacao\n");
                printf("-> ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    goto gerenciador_menu;
                } else {
                    goto manipulador_menu;
                }
            }
        } else if (opcao2 == 2) {
            system("clear");
            printf("Alterar Informacoes do Processo\n");
            printf("1 - Nome\n");
            printf("2 - Quantidade de Execucoes\n");
            printf("-> ");
            scanf("%d", &opcao);
            if (opcao == 1) {

                system("clear");
                printf("Alterando Nome\n");
                printf("Digite o PID do processo: ");
                scanf("%d", &e);
                printf("\nDigite o novo nome: ");
                scanf("%s", nome[e - 100]);
                printf("\n1 - Retornar ao Simulador de gerenciamento\n");
                printf("2 - Retornar ao Menu de manipulacao\n");
                printf("-> ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    goto gerenciador_menu;
                } else {
                    goto manipulador_menu;
                }
            } else if (opcao == 2) {
                system("clear");
                printf("Alterando Execucoes\n");
                printf("Digite o PID do processo: ");
                scanf("%d", &e);
                printf("Digite a nova quantidade de execucoes: ");
                scanf("%d", &exec[e - 100]);
                printf("1 - Retornar ao Simulador de gerenciamento\n");
                printf("2 - Retornar ao Menu de manipulacao\n");
                printf("-> ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    goto gerenciador_menu;
                } else {
                    goto manipulador_menu;
                }
            } else {
                printf("\nOpcao Invalida!\n");
                printf("1 - Retornar ao Simulador de gerenciamento\n");
                printf("2 - Retornar ao Menu de manipulacao\n");
                printf("-> ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    goto gerenciador_menu;
                } else {
                    goto manipulador_menu;
                }
            }
        } else if (opcao2 == 3) {
            system("clear");
            printf("Remover Process\n");
            printf("Digite o PID para eliminar: ");
            scanf("%d", &remover);
            for (r = 0; r < i; r++) {
                if (remover == pid[r]) {
                    memset(&nome[remover - 100], 0, sizeof(nome[remover - 100]));
                    memset(&exec[remover - 100], 0, sizeof(exec[remover - 100]));
                    memset(&pid[remover - 100], 0, sizeof(pid[remover - 100]));
                    printf("Removido com sucesso\n");
                    max = max - 1;
                    printf("1 - Retornar ao Simulador de gerenciamento\n");
                    printf("2 - Retornar ao Menu de manipulacao\n");
                    printf("-> ");
                    scanf("%d", &opcao);
                    if (opcao == 1) {
                        goto gerenciador_menu;
                    } else {
                        goto manipulador_menu;
                    }
                }
                if (remover >= i + 100) {
                    printf("PID INVALIDO\n");
                    printf("1 - Retornar ao Simulador de gerenciamento\n");
                    printf("2 - Retornar ao Menu de manipulacao\n");
                    printf("-> ");
                    scanf("%d", &opcao);

                    if (opcao == 1) {
                        goto gerenciador_menu;
                    } else {
                        goto manipulador_menu;
                    }
                }
            }
        } else if (opcao2 == 4) {
            system("clear");
            printf("Tabela de Processo\n\n");
            printf("Nome \t PID \t Executando\n");
            for (x = 0; x < i; x++) {
                if (pid[x] != 0) {
                    printf("%s \t %d \t %d \n", nome[x], pid[x], exec[x]);
                }
            }
            printf("1 - Retornar ao Simulador de gerenciamento\n");
            printf("2 - Retornar ao Menu de manipulacao\n");
            printf("-> ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                goto gerenciador_menu;
            } else {
                goto manipulador_menu;
            }
        } else if (opcao2 == 5) {
            for (q = 0; q < i; q++) {
                if (remover == pid[q]) {
                    memset(&nome[remover - 100], 0, sizeof(nome[remover - 100]));
                    memset(&exec[remover - 100], 0, sizeof(exec[remover - 100]));
                    memset(&pid[remover - 100], 0, sizeof(pid[remover - 100]));
                }
            }
            i = 0;
            system("clear");
            printf("Tabela Limpa\n");
            sleep(3);
            system("clear");
            goto gerenciador_menu;
        } else if (opcao2 == 0) {
            goto gerenciador_menu;
        } else {
            system("clear");
            printf("Comando invalido\n");
            sleep(2);
            system("clear");
            goto manipulador_menu;
        }
    } else if (opcao == 2) {
        rodar:
        system("clear");
        printf("1 - Rodar uma vez\n");
        printf("2 - Rodar ate o fim\n");
        printf("0 - Voltar\n");
        printf("-> ");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            rodar1:
            for (q = 0; q < i; q++) {
                if (exec[q] >= 1) {
                    exec[q] = exec[q] - 1;
                    fim[q] = exec[q];
                }
            }
            printf("Nome \t PID \t Fim ");
            for (r = 0; r < i; r++) {
                if (pid[r] != 0) {
                    printf("\n%s \t %d \t %d \n", nome[r], pid[r], fim[r]);
                }
            }
            printf("\n");
            printf("1 - Rodar novamente\n");
            printf("2 - Retornar ao Simulador de gerenciamento\n");
            printf("0 - Retornar ao menu de escalonamento\n");
            printf("-> ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                goto rodar1;
            } else if (opcao == 2) {
                goto gerenciador_menu;
            } else if (opcao == 0) {
                goto rodar;
            } else {
                system("clear");
                printf("Comando invalido\n");
                sleep(2);
                system("clear");
                goto rodar;
            }
        } else if (opcao2 == 2) {
            maior = exec[0];
            for (r = 0; r < i; r++) {
                if (exec[r] > maior) {
                    maior = exec[r];
                }
            }
            for (p = 0; p <= maior; p++) {
                for (q = 0; q < i; q++) {
                    if (exec[q] >= 1) {
                        exec[q] = exec[q] - 1;
                        fim[q] = exec[q];
                        printf("Nome \t PID \t Finalizando em ");
                        printf("\n%s \t %d \t %d \n", nome[q], pid[q], fim[q]);
                    }
                }
            }
            printf("\nFinalizado\n");
            printf("Nome \t PID \t execucoes ");
            for (r = 0; r < i; r++) {
                if (pid[r] != 0) {
                    printf("\n%s \t %d \t %d ", nome[r], pid[r], fim[r]);
                }
            }
            printf("\n1 - Retornar ao Simulador de gerenciamento\n");
            printf("-> ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                goto gerenciador_menu;
            } else {
                system("clear");
                printf("Comando invalido\n");
                sleep(2);
                system("clear");
                goto rodar;
            }
        } else if (opcao2 == 0) {
            goto gerenciador_menu;
        } else {
            system("clear");
            printf("Comando invalido\n");
            sleep(2);
            system("clear");
            goto rodar;
        }
    } else if (opcao == 3) {
        copy:
        system("clear");
        printf("Copyright\n");
        printf("Henrique Barros de Almeida\n");
        printf("Lucas Abrahao\n");
        printf("0 - Voltar\n");
        printf("-> ");
        scanf("%d", &opcao);
        if (opcao == 0) {
            goto gerenciador_menu;
        } else {
            system("clear");
            printf("Comando invalido\n");
            sleep(2);
            system("clear");
            goto copy;
        }
    } else if (opcao == 0) {
        system("clear");
        return 0;
    } else {
        system("clear");
        printf("Comando invalido\n");
        sleep(2);
        system("clear");
        goto gerenciador_menu;
    }
}


