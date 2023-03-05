#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 8

int randomGenerator()
{
    int randomnumber;
    randomnumber = rand() % 10;
    return(randomnumber);
}

void createTable(char grid[size][size])
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            int randomBomb = randomGenerator();
            if (randomBomb == 1)
            {
                grid[j][i] = 'X';
            }
            else
            {
                grid[j][i] = '0';
            }
        }
    }
}



void createMask(char gridMask[size][size])
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            gridMask[j][i] = '.';
        }
    }
}

void bombNearby(char grid[size][size])
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            int count = 0;
            char countChar;
            if (grid[j][i] == '0')
            {

                // compter le nombre de bombe adjacente
                if (grid[j - 1][i] == 'X')
                {
                    count = ++count;
                }
                if (grid[j + 1][i] == 'X')
                {
                    count = ++count;
                }
                if (i != 0)
                {

                    if (grid[j][i - 1] == 'X')
                    {
                        count = ++count;
                    }
                    if (grid[j - 1][i - 1] == 'X')
                    {
                        count = ++count;
                    }
                    if (grid[j + 1][i - 1] == 'X')
                    {
                        count = ++count;
                    }
                }

                if (i != size - 1)
                {
                    if (grid[j][i + 1] == 'X')
                    {
                        count = ++count;
                    }
                    if (grid[j - 1][i + 1] == 'X')
                    {
                        count = ++count;
                    }
                    if (grid[j + 1][i + 1] == 'X')
                    {
                        count = ++count;
                    }
                }
                // converion count en char ASCII
                grid[j][i] = (char)(count + 48);
            }
        }
    }
}

void showTable(char grid[size][size])
{
    printf("   0 1 2 3 4 5 6 7 \n");
    for (int j = 0; j < size; ++j)
    {
        printf("%d  ", j);
        for (int i = 0; i < size; ++i)
        {
            printf("%c", grid[j][i]);
            printf(" ");
        }
        printf("\n");
    }
}



int main()
{
    srand(time(NULL));
    int inputRow;
    int inputCol;
    // initianilation du tableau de jeu 
    char grid[size][size];
    char gridMask[size][size];
    createTable(grid);
    createMask(gridMask);
    bombNearby(grid);
    // jeu
    printf("Start of Minesweeper ! \n \n");
    int stopWhile = 0;
    int test;
    int testRow;
    int testCol;
    showTable(gridMask);
    while (stopWhile == 0) {
        test = 0;
        testRow = 0;
        testCol = 0;
        while (test == 0) {
            printf("\n Enter the number of a row : ");
            scanf("%d", &inputRow);
            printf("\n Enter the number of a column : ");
            scanf("%d", &inputCol);
            if ((inputCol < 0) || (inputCol > size - 1)) {
                testCol = 0;
            }
            else {
                testRow = 1;
            }
            if ((inputRow < 0) || (inputRow > size - 1)) {
                testRow = 0;
            }
            else {
                testCol = 1;
            }
            if (testRow == 1 && testCol == 1) {
                test = 1;
            }
            else {
                printf("Strike not possible, try again");
            }
        }
        gridMask[inputRow][inputCol] = grid[inputRow][inputCol];
        printf("\n Played at row : %d and col : %d \n \n", inputRow, inputCol);
        showTable(gridMask);
        if (gridMask[inputRow][inputCol] == 'X')
        {
            printf("\n You discovered a bomb, end of the game");
            break;
        }
        else {
            printf("\n \n");
        }
    }
}