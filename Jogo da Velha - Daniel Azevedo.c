#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Fun��o respons�vel por verificar se a op��o de linha est� entre 1 e 3

int validadeLinha(int linha) {
	while (linha < 1 || linha > 3) {
	    printf("Op��o inv�lida! Informe uma linha de 1 a 3: ");
	    scanf("%d", &linha);
	}
	return linha;
}

//Fun��o respons�vel por verificar se a op��o de coluna est� entre 1 e 3

int validadeColuna(int coluna) {
	while (coluna < 1 || coluna > 3) {
	    printf("Op��o inv�lida! Informe uma linha de 1 a 3: ");
	    scanf("%d", &coluna);
	    }
	return coluna;
}

//Fun��o respons�vel por zerar o tabuleiro
void zeraJogo(char tab[4][4]) {
	int linha, coluna;
    for (linha = 1; linha < 4; linha++) {
        for (coluna = 1; coluna < 4; coluna++) {
        tab[linha][coluna] = '_';
        }
    }
}

//Fun��o respons�vel por atualizar o tabuleiro a cada nova jogada:
void mostraJogo(char tab[4][4]) {
	int linha, coluna;
	for (linha = 1; linha < 4; linha++) {
        for (coluna = 1; coluna < 4; coluna++) {
            printf("%c	", tab[linha][coluna]);
        }
    printf("\n\n\n");
    }
}

//Esta fun��o abaixo verifica se o jogador 1 e PC preencheram uma linha de 3 posi��es, isto �, se venceram a partida.
int Vencedor(char tab[4][4]) {

    if (
        (tab[1][1] == 'X' && tab[2][2] == 'X' && tab[3][3] == 'X') ||
        (tab[3][1] == 'X' && tab[2][2] == 'X' && tab[1][3] == 'X') ||
        (tab[1][1] == 'X' && tab[2][1] == 'X' && tab[3][1] == 'X') ||
        (tab[1][2] == 'X' && tab[2][2] == 'X' && tab[3][2] == 'X') ||
        (tab[1][3] == 'X' && tab[2][3] == 'X' && tab[3][3] == 'X') ||
        (tab[1][1] == 'X' && tab[1][2] == 'X' && tab[1][3] == 'X') ||
        (tab[2][1] == 'X' && tab[2][2] == 'X' && tab[2][3] == 'X') ||
        (tab[3][1] == 'X' && tab[3][2] == 'X' && tab[3][3] == 'X'))
                                                                    {
        printf("\7");
        return 1;

    } if (
         (tab[1][1] == 'O' && tab[2][2] == 'O' && tab[3][3] == 'O') ||
         (tab[3][1] == 'O' && tab[2][2] == 'O' && tab[1][3] == 'O') ||
         (tab[1][1] == 'O' && tab[2][1] == 'O' && tab[3][1] == 'O') ||
         (tab[1][2] == 'O' && tab[2][2] == 'O' && tab[3][2] == 'O') ||
         (tab[1][3] == 'O' && tab[2][3] == 'O' && tab[3][3] == 'O') ||
         (tab[1][1] == 'O' && tab[1][2] == 'O' && tab[1][3] == 'O') ||
         (tab[2][1] == 'O' && tab[2][2] == 'O' && tab[2][3] == 'O') ||
         (tab[3][1] == 'O' && tab[3][2] == 'O' && tab[3][3] == 'O'))
                                                                    {
        printf("\7");
        return 2;
    }
}

int main () {

	setlocale(0, "Portuguese");

	int menu = 0;
	int opcao;
	char tab[4][4];
	int linha, coluna, i;
	int jogador1 = 0, jogador2 = 0;
	int linha_user[5], coluna_user[5];
	int linha_pc, coluna_pc;
	int fim, continua_jogo = 1;
	int minha_vitoria = 0, vitoria_pc = 0;

	srand(time(NULL));
    printf("-----------------------------------------JOGO DA VELHA ----------------------------------------- \n\n");

	printf("Elaborado por: Daniel Azevedo\n");

	printf("2021\n\n");

	while (menu == 0) {

        printf("____________________________\n");
        printf("                            \n");
        printf("       MENU PRINCIPAL       \n");
        printf("____________________________\n");

        printf("\n[ 1 ]\tJogar contra o PC\n[ 2 ]\tJogar contra outro usu�rio\n[ 3 ]\tSobre\n[ 4 ]\tSair\n");
        printf("\nSelecione a op��o de jogo: ");
        scanf("%d", &opcao);

        while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4) {
            printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n");
            printf("\nSelecione a op��o de jogo: ");
            scanf("%d", &opcao);
        }

        if (opcao == 1) {
/*------------------------------------Jogando partida contra o PC------------------------------------*/

            do {

                system("cls");

                zeraJogo(tab);

        	    mostraJogo(tab);

                for (i = 1; i < 6 ; i++) { //Este for representa o n�mero de jogadas de um jogo da velha: 5.

                    printf("%d� jogada!\n", i);
                    printf("Escolha a linha e coluna que deseja marcar um X\n\n");
                    printf("Linha: ");
                    scanf("%d", &linha_user[i]);

                    linha_user[i] = validadeLinha(linha_user[i]);

                    printf("Coluna: ");
                    scanf("%d", &coluna_user[i]);

                    coluna_user[i] = validadeColuna(coluna_user[i]);

                    while(tab[ linha_user[i] ][ coluna_user[i] ] != '_') {

					    printf("Esta op��o j� foi marcada! Tente novamente!\n\n");
	                    printf("Linha: ");
	                    scanf("%d", &linha_user[i]);
	                    coluna_user[i] = validadeColuna(coluna_user[i]);

	                    printf("Coluna: ");
	                    scanf("%d", &coluna_user[i]);
	                    coluna_user[i] = validadeColuna(coluna_user[i]);
                    }

                    tab[linha_user[i]][coluna_user[i]] = 'X';

	                system("cls");
	                mostraJogo(tab);

                    fim = Vencedor(tab);
                    if (fim == 1) {
                        printf("Parab�ns! Voc� venceu!\n\n");
                        minha_vitoria += 1;
                        break;
                    } if (fim == 2){
                        printf("Que pena! Voc� perdeu!\n\n");
                        vitoria_pc += 1;
                        break;
                    }

                    if (i == 5) {
                    /*Usando a l�gica, ser� obrigatoriamente velha quando chegarmos na 5� rodada e o jogador 1 tiver finalizado
                    a sua jogada. Neste caso, todos os campos j� foram preenchidos.*/
                    	printf("Deu velha! Ningu�m venceu!\n\n");
                    	break;
					}

                    printf("Agora � a minha vez!\n");

                    sleep(1);

                    linha_pc = rand() % 3 + 1; //vai escolher um �ndice aleat�rio
                    coluna_pc = rand() % 3 + 1; //vai escolher um �ndice aleat�rio

                    while (tab[linha_pc][coluna_pc] != '_') {

                        linha_pc  = rand() % 3 + 1; //vai escolher um �ndice aleat�rio
                        coluna_pc = rand() % 3 + 1; //vai escolher um �ndice aleat�rio

                        }

                    tab[linha_pc][coluna_pc] = 'O';

                    system("cls");
               		mostraJogo(tab);

                    fim = Vencedor(tab);

                    if (fim == 1) {
                        printf("Parab�ns! Voc� venceu!\n\n");
                        minha_vitoria += 1;
                        break;

                    } if (fim == 2) {
                        printf("Que pena! Voc� perdeu!\n\n");
                        vitoria_pc += 1;
                        break;
                    }
                }

                printf("[ 1 ] Jogar nova partida\n[ 2 ] Ver Placar\n[ 3 ] Retornar ao menu principal\n");
                printf("Op��o: ");
                scanf("%d", &continua_jogo);

                while (continua_jogo < 1 || continua_jogo > 3) {
	                printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n\n");
	                printf("[ 1 ] Jogar nova partida\n[ 2 ] Ver Placar\n[ 3 ] Retornar ao menu principal\n");
	                printf("Op��o: ");
	                scanf("%d", &continua_jogo);

                }

                if (continua_jogo == 2) {
                    system("cls");

                    printf("----------------------------------------------------\n\n");
                    printf("\t\tPLACAR DE VIT�RIAS\n\n");
                    printf("\tJOGADOR\t\t\tVIT�RIAS\n");
                    printf("\n\tVoc�:\t\t\t   %d\n", minha_vitoria);
                    printf("\n\tComputador:\t\t   %d\n\n", vitoria_pc);
                    printf("-----------------------------------------------------\n");

                    printf("[ 1 ] Jogar nova partida\n[ 2 ] Retornar ao menu principal\n");
                    printf("Op��o: ");
                    scanf("%d", &continua_jogo);

                    while (continua_jogo != 1 && continua_jogo != 2) {
	                    printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n\n");
	                    printf("[ 1 ] Jogar nova partida\n[ 2 ] Retornar ao menu principal\n");
	                    printf("Op��o: ");
	                    scanf("%d", &continua_jogo);
                    }

                    if (continua_jogo == 2) {
	                    minha_vitoria = 0;
	                    vitoria_pc = 0;
	                    system("cls");
	                    continue;
					//Com o comando continue, ser� for�ada uma nova itera��o para o in�cio do jogo e o placar ser� zerado.
                }
            }

            system("cls");

            } while (continua_jogo == 1); //Fim do do while

        } if (opcao == 2) {
/*------------------------------------Jogando partida de dois------------------------------------*/
            do {

            	system("cls");

                zeraJogo(tab);

        	    mostraJogo(tab);

                for (i = 1; i < 6 ; i++) {  //Este for representa o n�mero de jogadas de um jogo da velha: 5.

                    printf("%d� jogada!\n", i);

                    printf("\nVez do primeiro jogador!\n");

                    printf("Escolha a linha e coluna que deseja marcar um X\n\n");
                    printf("Linha: ");
                    scanf("%d", &linha_user[i]);

                    linha_user[i] = validadeLinha(linha_user[i]);

                    printf("Coluna: ");
                    scanf("%d", &coluna_user[i]);

                    coluna_user[i] = validadeColuna(coluna_user[i]);

                    while(tab[ linha_user[i] ][ coluna_user[i] ] != '_') {
	                    printf("Esta op��o j� foi marcada! Tente novamente!\n\n");
	                    printf("Linha: ");
	                    scanf("%d", &linha_user[i]);
	                    linha_user[i] = validadeLinha(linha_user[i]);

	                    printf("Coluna: ");
	                    scanf("%d", &coluna_user[i]);
	                    coluna_user[i] = validadeColuna(coluna_user[i]);
                    }

                    tab[linha_user[i]][coluna_user[i]] = 'X';

                    system("cls");

                    mostraJogo(tab);

                    fim = Vencedor(tab);

                    if (fim == 1) {
                        printf("Vit�ria do jogador 1!\n");
                        jogador1 += 1;
                        break;

                    } if (fim == 2){
                        printf("Vit�ria do jogador 2!\n");
                        jogador2 += 1;
                        break;
                    }

                    if (i == 5) {
                    /*Ou seja, quando for velha*/
                    	printf("Deu velha! Ningu�m venceu!\n\n");
                    	break;
					}

                    printf("Vez do segundo jogador!\n");

                    printf("Escolha a linha e coluna que deseja marcar O\n\n");
                    printf("Linha: ");
                    scanf("%d", &linha_user[i]);

                    linha_user[i] = validadeLinha(linha_user[i]);

                    printf("Coluna: ");
                    scanf("%d", &coluna_user[i]);

                    coluna_user[i] = validadeColuna(coluna_user[i]);

                    while(tab[ linha_user[i] ][ coluna_user[i] ] != '_') {
	                    printf("Esta op��o j� foi marcada! Tente novamente!\n\n");
	                    printf("Linha: ");
	                    scanf("%d", &linha_user[i]);
	                    coluna_user[i] = validadeColuna(coluna_user[i]);

	                    printf("Coluna: ");
	                    scanf("%d", &coluna_user[i]);
	                    coluna_user[i] = validadeColuna(coluna_user[i]);
                    }

                    tab[linha_user[i]][coluna_user[i]] = 'O';

                    system("cls");

                    mostraJogo(tab);

                    fim = Vencedor(tab);

                    if (fim == 1) {
                        printf("Vit�ria do jogador 1!\n");
                        jogador1 += 1;
                        break;

                    } if (fim == 2) {
                        printf("Vit�ria do jogador 2!\n");
                        jogador2 += 1;
                        break;
                    }
                }

			    printf("[ 1 ] Jogar nova partida\n[ 2 ] Ver Placar\n[ 3 ] Retornar ao menu principal\n");
                printf("Op��o: ");
                scanf("%d", &continua_jogo);

                while (continua_jogo < 1 || continua_jogo > 3) {
	                printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n\n");
	                printf("[ 1 ] Jogar nova partida\n[ 2 ] Ver Placar\n[ 3 ] Retornar ao menu principal\n");
	                printf("Op��o: ");
	                scanf("%d", &continua_jogo);
                }

                if (continua_jogo == 2) {

                    system("cls");

                    printf("----------------------------------------------------\n\n");
                    printf("\t\tPLACAR DE VIT�RIAS\n\n");
                    printf("\tJOGADOR\t\t\tVIT�RIAS\n");
                    printf("\n\tJogador 1:\t\t   %d\n", jogador1);
                    printf("\n\tJogador 2:\t\t   %d\n\n", jogador2);
                    printf("-----------------------------------------------------\n");

                    printf("[ 1 ] Jogar nova partida\n[ 2 ] Retornar ao menu principal\n");
                    printf("Op��o: ");
                    scanf("%d", &continua_jogo);

                    while (continua_jogo != 1 && continua_jogo != 2) {
                    printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n\n");
                    printf("[ 1 ] Jogar nova partida\n[ 2 ] Retornar ao menu principal\n");
                    printf("Op��o: ");
                    scanf("%d", &continua_jogo);
                    }

                    if (continua_jogo == 2) {
                    system("cls");
                    jogador1 = 0;
                    jogador2 = 0;
                    continue;
                	}
            	}

                if (continua_jogo == 3) {
                    minha_vitoria = 0;
                    vitoria_pc = 0;
                    printf("\n\n");
                    continue;
                }

                system("cls");

                } while (continua_jogo == 1);

        } if (opcao == 3) {

        	system("cls");

            printf("Este jogo foi desenvolvido por Daniel Azevedo de Oliveira Maia, em Linguagem C, em novembro de 2021.\n\n");
            printf("[ 1 ] Retornar ao menu principal\n[ 2 ] Sair\n\n");
            printf("Op��o: ");
            scanf("%d", &opcao);

            while (opcao != 1 && opcao != 2) {
	            printf("Esta op��o n�o existe! Escolha uma op��o v�lida.\n\n");
	            printf("[ 1 ] Retornar ao menu principal\n[ 2 ] Sair\n\n");
	            printf("Op��o: ");
	            scanf("%d", &opcao);
            }

            if (opcao == 1) {
                system("cls");
                continue;

            } if (opcao == 2) {
                    system("cls");
                    menu = 1; //Estando o menu em 1, encerra-se o while principal e o programa se encerra.
            }

    	} if (opcao == 4) {
                system("cls");
                menu = 1;
        	}
    }
    system("pause");

    return 0;
}
