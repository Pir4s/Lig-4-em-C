#include<stdio.h>
int main()
{
    int lin, col, coluna, vez, finalizar, contadorX1=0, contadorO1=0, linha, contadorX2=0, contadorO2=0, contadorX3=0, contadorO3=0;
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
        if ((vez+1)%2 != 0) //Jogador 1 Impar, Jogador 2 Par
        {
            printf("Escolha a Coluna Jogador 1 --> ");
        }
        else
        {
            printf("Escolha a Coluna Jogador 2 --> ");
        }
        scanf("%d", &col);
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
                break;
            }
            if (vez>5)//VERIFICADOR DE VITORIA/EMPATE
            {
                for(coluna=0;coluna<=6;coluna++)
                {
                    for(linha=0;linha<=5;linha++)
                    {
                        if (tabuleiro[linha][coluna] == 'X')
                        {
                            contadorO1=0;
                            contadorX1++;
                        }
                        else if (tabuleiro[linha][coluna] == 'O')
                        {
                            contadorX1=0;
                            contadorO1++;
                        }
                    }
                }
                if (contadorX1 == 4)
                {
                    printf("Jogador 1 venceu\n");
                    finalizar=1;
                }
                else if (contadorO1 == 4)
                {
                    printf("Jogador 2 venceu\n");
                    finalizar=1;
                }
                for(coluna=0;coluna<=6;coluna++)
                {
                    for(linha=0;linha<=5;linha++)
                    {
                        if (tabuleiro[coluna][linha] == 'X')
                        {
                            contadorO2=0;
                            contadorX2++;
                        }
                        else if (tabuleiro[coluna][linha] == 'O')
                        {
                            contadorX2=0;
                            contadorO2++;
                        }
                    }
                }
                if (contadorX2 == 4)
                {
                    printf("Jogador 1 venceu\n");
                    finalizar=1;
                }
                else if (contadorO2 == 4)
                {
                    printf("Jogador 2 venceu\n");
                    finalizar=1;
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
               0 --> | 50 | 51 | 52 | 53 | 54 | 55 | 56 |
               1 --> | 40 | 41 | 42 | 43 | 44 | 45 | 46 |
               2 --> | 30 | 31 | 32 | 33 | 34 | 35 | 36 |
               3 --> | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
               4 --> | 10 | 11 | 12 | 13 | 14 | 15 | 16 |
               5 --> |0 0 | 01 | 02 | 03 | 04 | 05 | 06 |
                    " "  
                    3 valores para a matriz ' ', "X" e "O"
                    
                    
                    */
