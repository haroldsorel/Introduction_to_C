#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

char maze[7][13];
int iterations = 0;
int spotx = 999; //store old locations
int spoty = 999; //store old locations
int positions[10][2];

void maze_reset()
{

    for (int i = 0; i < 7; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 13; j++)
            {
                maze[i][j] = '#';
            }
        }
        else
        {
            for (int k = 0; k < 13; k++)
            {
                if (k % 4 == 0)
                {
                    maze[i][k] = '|';
                }
                else
                {
                    maze[i][k] = ' ';
                }
            }
        }
    }
}

void SumSpacePLZ()
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
    }
}

void maze_printer()
{
    printf("\n\n");
    for (int i = 0; i < 7; i++)
    {
        printf("\t");
        for (int j = 0; j < 13; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int random_row_number_generator()
{
    int i = rand() % 3;
    int numz[] ={1, 3, 5};
    return numz[i];
}

int random_column_number_generator()
{
    int i = rand() % 3;
    int numz[] ={2, 6, 10};
    return numz[i];
}

void position_storer(int row, int column)
{
    positions[iterations][0] = row;
    positions[iterations][1] = column;

}

void write_random_spot()
{
    int x, y;
    do
    {
        x = random_row_number_generator();
        y = random_column_number_generator();
    }   while (spotx == x && spoty == y); //to avoid having the same spot several times in a row

    maze[x][y] = '$';
    spotx = x;
    spoty = y;
    iterations++;
    position_storer(x, y);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);

}

int main()
{
    srand(time(0));
    maze_reset();
    SumSpacePLZ();
    maze_printer();
    delay(500);
    int times = 1;
    while (true)
    {
        SumSpacePLZ();
        write_random_spot();
        maze_printer();
        delay(500);
        maze_reset();
    }


    return 0;
}
