#include<stdio.h>
int main()
{
    int lin, col, coluna, vez, finalizar, contadorX, contadorO;
    char tabuleiro[6][7] = 
    {
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    for (int col=0; col<7; col++)
    {
        for (lin=0; lin<6; lin++)
        {
            printf("|%c", tabuleiro[lin][col]);
        }
        printf("|\n");
    }
    vez = 0;
    finalizar = 0;
    while(finalizar != 1)
    {
        printf("Escolha a Coluna --> ");
        scanf("%d", &col);
        col--;
        if (col<0 || col>6)
        {
            printf("Coluna Invalida\n");
        }
        for(lin=0;lin<=5;lin++)
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
                lin=10;//break;
            }
            if (vez>5)//VERIFICADOR DE VITORIA/EMPATE
            {
                for(col=0;col<=6;col++)
                {
                    for(lin=0;lin<=5;lin++)
                    {
                        if (tabuleiro[lin][col] == 'X')
                        {
                            contadorX++;
                        }
                        else
                        {
                            contadorO++;
                        }
                    }
                }
                if (contadorX == 4)
                {
                    printf("Jogador 1 venceu\n");
                    finalizar=1;
                }
                else if (contadorO ==4)
                {
                    printf("Jogador 2 venceu\n");
                }
            }
        }
        vez++;
    }
}
                    /*
                        0   1    2    3    4    5    6
                        ^   ^    ^    ^    ^    ^    ^
                        |   |    |    |    |    |    |
               5 --> | 50 | 51 | 52 | 53 | 54 | 55 | 56 |
               4 --> | 40 | 41 | 42 | 43 | 44 | 45 | 46 |
               3 --> | 30 | 31 | 32 | 33 | 34 | 35 | 36 |
               2 --> | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
               1 --> | 10 | 11 | 12 | 13 | 14 | 15 | 16 |
               0 --> | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
                    " "  
                    3 valores para a matriz ' ', "X" e "O"
                    
                    
                    */
