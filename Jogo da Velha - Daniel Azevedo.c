#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAMANHO_TABULEIRO 3
#define JOGADOR_1 'X'
#define JOGADOR_2 'O'
#define VAZIO '_'

// Função para limpar buffer em caso de entrada inválida
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função responsável por verificar se a entrada é válida
int validarEntrada(int valor, const char *tipo) {
    while (1) {
        if (scanf("%d", &valor) != 1) {
            limparBuffer();
            printf("Entrada inválida! Informe uma %s de 1 a %d: ", tipo, TAMANHO_TABULEIRO);
        } else if (valor < 1 || valor > TAMANHO_TABULEIRO) {
            printf("Opção inválida! Informe uma %s de 1 a %d: ", tipo, TAMANHO_TABULEIRO);
        } else {
            break;
        }
    }
    return valor;
}

// Função responsável por zerar o tabuleiro
void zerarJogo(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    for (int linha = 1; linha <= TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 1; coluna <= TAMANHO_TABULEIRO; coluna++) {
            tab[linha][coluna] = VAZIO;
        }
    }
}

// Função responsável por exibir o tabuleiro
void mostrarJogo(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    for (int linha = 1; linha <= TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 1; coluna <= TAMANHO_TABULEIRO; coluna++) {
            printf("%c\t", tab[linha][coluna]);
        }
        printf("\n\n");
    }
}

// Função que verifica se há um vencedor
int verificarVencedor(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    for (int i = 1; i <= TAMANHO_TABULEIRO; i++) {
        if (tab[i][1] == tab[i][2] && tab[i][2] == tab[i][3] && tab[i][1] != VAZIO) return tab[i][1] == JOGADOR_1 ? 1 : 2;
        if (tab[1][i] == tab[2][i] && tab[2][i] == tab[3][i] && tab[1][i] != VAZIO) return tab[1][i] == JOGADOR_1 ? 1 : 2;
    }
    if (tab[1][1] == tab[2][2] && tab[2][2] == tab[3][3] && tab[1][1] != VAZIO) return tab[1][1] == JOGADOR_1 ? 1 : 2;
    if (tab[3][1] == tab[2][2] && tab[2][2] == tab[1][3] && tab[3][1] != VAZIO) return tab[3][1] == JOGADOR_1 ? 1 : 2;
    return 0;
}

// Função que gerencia o jogo para dois jogadores
void jogarContraUsuario(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    int linha, coluna, fim;
    int jogador1 = 0, jogador2 = 0;

    do {
        zerarJogo(tab);
        mostrarJogo(tab);

        for (int i = 1; i <= TAMANHO_TABULEIRO * TAMANHO_TABULEIRO; i++) {
            printf("%dª jogada!\n", i);

            if (i % 2 != 0) {
                printf("Vez do jogador 1 (%c)!\n", JOGADOR_1);
            } else {
                printf("Vez do jogador 2 (%c)!\n", JOGADOR_2);
            }

            printf("Linha: ");
            linha = validarEntrada(linha, "linha");

            printf("Coluna: ");
            coluna = validarEntrada(coluna, "coluna");

            while (tab[linha][coluna] != VAZIO) {
                printf("Esta posição já foi marcada! Tente novamente.\n");
                printf("Linha: ");
                linha = validarEntrada(linha, "linha");

                printf("Coluna: ");
                coluna = validarEntrada(coluna, "coluna");
            }

            tab[linha][coluna] = (i % 2 != 0) ? JOGADOR_1 : JOGADOR_2;
            mostrarJogo(tab);

            fim = verificarVencedor(tab);
            if (fim == 1) {
                printf("Jogador 1 venceu!\n\n");
                jogador1++;
                break;
            } else if (fim == 2) {
                printf("Jogador 2 venceu!\n\n");
                jogador2++;
                break;
            }

            if (i == TAMANHO_TABULEIRO * TAMANHO_TABULEIRO) {
                printf("Deu velha!\n\n");
            }
        }

        printf("[1] Jogar nova partida\n[2] Ver Placar\n[3] Retornar ao menu principal\nOpção: ");
        fim = validarEntrada(fim, "opção");

        if (fim == 2) {
            printf("\n\tPLACAR\n\tJogador 1: %d\n\tJogador 2: %d\n\n", jogador1, jogador2);
        }

    } while (fim == 1);
}

// Função que gerencia a jogada do computador
void jogadaComputador(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    int linha, coluna;
    do {
        linha = rand() % TAMANHO_TABULEIRO + 1;
        coluna = rand() % TAMANHO_TABULEIRO + 1;
    } while (tab[linha][coluna] != VAZIO);
    tab[linha][coluna] = JOGADOR_2;
}

// Função principal do jogo contra o computador
void jogarContraPC(char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1]) {
    int linha, coluna, fim;
    int minha_vitoria = 0, vitoria_pc = 0;

    do {
        zerarJogo(tab);
        mostrarJogo(tab);

        for (int i = 1; i <= TAMANHO_TABULEIRO * TAMANHO_TABULEIRO / 2 + 1; i++) {
            printf("%dª jogada!\n", i);
            printf("Escolha a linha e coluna que deseja marcar um %c\n\n", JOGADOR_1);

            printf("Linha: ");
            linha = validarEntrada(linha, "linha");

            printf("Coluna: ");
            coluna = validarEntrada(coluna, "coluna");

            while (tab[linha][coluna] != VAZIO) {
                printf("Esta opção já foi marcada! Tente novamente!\n\n");
                printf("Linha: ");
                linha = validarEntrada(linha, "linha");

                printf("Coluna: ");
                coluna = validarEntrada(coluna, "coluna");
            }

            tab[linha][coluna] = JOGADOR_1;
            mostrarJogo(tab);

            fim = verificarVencedor(tab);
            if (fim == 1) {
                printf("Parabéns! Você venceu!\n\n");
                minha_vitoria++;
                break;
            }

            if (i == TAMANHO_TABULEIRO * TAMANHO_TABULEIRO / 2 + 1) {
                printf("Deu velha! Ninguém venceu!\n\n");
                break;
            }

            printf("Agora é a minha vez!\n");
            jogadaComputador(tab);
            mostrarJogo(tab);

            fim = verificarVencedor(tab);
            if (fim == 2) {
                printf("Que pena! Você perdeu!\n\n");
                vitoria_pc++;
                break;
            }
        }

        printf("[1] Jogar nova partida\n[2] Ver Placar\n[3] Retornar ao menu principal\nOpção: ");
        fim = validarEntrada(fim, "opção");

        if (fim == 2) {
            printf("\n\tPLACAR\n\tVocê: %d\n\tComputador: %d\n\n", minha_vitoria, vitoria_pc);
        }

    } while (fim == 1);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int opcao;
    char tab[TAMANHO_TABULEIRO + 1][TAMANHO_TABULEIRO + 1];

    do {
        printf("\nMENU PRINCIPAL\n[1] Jogar contra o PC\n[2] Jogar contra outro jogador\n[3] Sair\nOpção: ");
        opcao = validarEntrada(opcao, "opção");

        switch (opcao) {
            case 1:
                jogarContraPC(tab);
                break;
            case 2:
                jogarContraUsuario(tab);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
