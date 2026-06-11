#include<stdio.h>
int main()
{
    int lin, col, coluna, vez, finalizar, conta, linha;
    char tabuleiro[6][7] = 
    {
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    vez = 0;
    finalizar = 0;
    while(finalizar != 1)
    {
        for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
        {
            for (col=0; col<7; col++)
            {
                printf("|%c", tabuleiro[lin][col]);
            }
            printf("|\n");
        }
        if (vez%2 == 0)//VEZ DO JOGADOR 1 Par
        {
            printf("Escolha a Coluna Jogador 1 --> ");
        }
        else
        {
            printf("Escolha a Coluna Jogador 2 --> ");
        }
        scanf("%d", &col);//LE A COLUNA ESCOLHIDA
        col--;
        if (col<0 || col>6)//invalida a coluna
        {
            printf("Coluna Invalida\n");
            continue;
        }
        for(lin=5;lin>=0;lin--)//COLOCA A PEÇA
        {
            if (tabuleiro[lin][col] == ' ')
            {
               if (vez%2 == 0)
               {
                   tabuleiro[lin][col] = 'X';
               }
               else
               {
                   tabuleiro[lin][col] = 'O';
               }
                break;//Sai do for quando a peça for colocada
            }
        }// peca foi colocada, agora verificar se o jogador venceu ou empatou
        char peca;
        if (vez % 2 == 0)
        {
            peca = 'X';
        } else {
            peca = 'O';
        }
        if (vez>5)
        {
            for (coluna = 0; coluna <= 3; coluna++)//verificar horizontalmente
            {
                if (tabuleiro[lin][coluna] == peca &&
                    tabuleiro[lin][coluna+1] == peca &&
                    tabuleiro[lin][coluna+2] == peca &&
                    tabuleiro[lin][coluna+3] == peca)
                {
                    for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
                    {
                        for (col=0; col<7; col++)
                        {
                            printf("|%c", tabuleiro[lin][col]);
                        }
                        printf("|\n");
                    }
                    printf("Jogador %c venceu!\n", peca);
                    finalizar = 1;
                    break;
                }
            }

            for (linha = 0; linha <= 2; linha++)//verificar verticalmente
            {
                if (tabuleiro[linha][col] == peca &&
                    tabuleiro[linha+1][col] == peca &&
                    tabuleiro[linha+2][col] == peca &&
                    tabuleiro[linha+3][col] == peca)
                {
                    for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
                    {
                        for (col=0; col<7; col++)
                        {
                            printf("|%c", tabuleiro[lin][col]);
                        }
                        printf("|\n");
                    }
                    printf("Jogador %c venceu!\n", peca);
                    finalizar = 1;
                    break;
                }
            }

                if (lin <= 2 && col <= 3 &&
                tabuleiro[lin][col] == peca &&
                tabuleiro[lin+1][col+1] == peca &&
                tabuleiro[lin+2][col+2] == peca &&
                tabuleiro[lin+3][col+3] == peca)
            {
                for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
                {
                    for (col=0; col<7; col++)
                    {
                        printf("|%c", tabuleiro[lin][col]);
                    }
                    printf("|\n");
                }
                
                printf("Jogador %c venceu!\n", peca);
                finalizar = 1;
            }


            if (lin <= 2 && col >= 3 &&
            tabuleiro[lin][col] == peca &&
            tabuleiro[lin+1][col-1] == peca &&
            tabuleiro[lin+2][col-2] == peca &&
            tabuleiro[lin+3][col-3] == peca)
            {
                for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
                {
                    for (col=0; col<7; col++)
                    {
                        printf("|%c", tabuleiro[lin][col]);
                    }
                    printf("|\n");
                }
                printf("Jogador %c venceu!\n", peca);
                finalizar = 1;
            }
            int cheio = 1; // assume que o tabuleiro está cheio
            for (lin = 0; lin < 6; lin++)
            {
                for (coluna = 0; coluna < 7; coluna++)
                {
                    if (tabuleiro[lin][coluna] == ' ')
                    {
                        cheio = 0; // ainda tem espaço
                    }
                }
            }
            if (cheio == 1)
            {
                for (lin=0; lin<6; lin++)//PRINTA O TABULEIRO
                {
                    for (col=0; col<7; col++)
                    {
                        printf("|%c", tabuleiro[lin][col]);
                    }
                    printf("|\n");
                }
                printf("Empate\n");
                finalizar = 1;
            }
        }
        vez++;
    }
}
                    /*
                        0   1    2    3    4    5    6
                        ^   ^    ^    ^    ^    ^    ^
                        |   |    |    |    |    |    |
               0 --> | 50 | 51 | 52 | 53 | 54 | 55 | 56 |
               1 --> | 40 | 41 | 42 | 43 | 44 | 45 | 46 |
               2 --> | 30 | 31 | 32 | 33 | 34 | 35 | 36 |
               3 --> | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
               4 --> | 10 | 11 | 12 | 13 | 14 | 15 | 16 |
               5 --> |0 0 | 01 | 02 | 03 | 04 | 05 | 06 |
                    " "  
                    3 valores para a matriz ' ', "X" e "O"
                    
                    
                    */
