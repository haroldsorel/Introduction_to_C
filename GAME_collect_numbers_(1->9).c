#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

const int ROW = 8;
const int COLUMN = 20;
const char EMPTYSPACE = '-';
const char SNAKE = '+';
const int inventory[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int inventoryIndex = 0;
char APPLE = 49;
char maze[30][30];
int Rpos = ROW / 2 - 1;
int Cpos = COLUMN / 2 - 1 ;
int Rapple = rand() % ROW;
int Capple = rand() % COLUMN;


void buttonz(char key)
{
    if (key == 'z')
    {
        maze[Rpos][Cpos] = EMPTYSPACE;
        Rpos--;
        if (Rpos<0) {Rpos = ROW-1;}
        maze[Rpos][Cpos] = SNAKE;
    }
    if (key == 'w')
    {
        maze[Rpos][Cpos] = EMPTYSPACE;
        Rpos++;
        Rpos%=ROW;
        maze[Rpos][Cpos] = SNAKE;
    }
    if (key == 'q')
    {
        maze[Rpos][Cpos] = EMPTYSPACE;
        Cpos--;
        if (Cpos<0) {Cpos = COLUMN-1;}
        maze[Rpos][Cpos] = SNAKE;
    }
    if (key == 's')
    {
        maze[Rpos][Cpos] = EMPTYSPACE;
        Cpos++;
        Cpos%=COLUMN;
        maze[Rpos][Cpos] = SNAKE;
    }


}

void maze_inventory_print()
{
    printf("\n\n");
    for ( int i = 0; i < ROW; i++)
    {
        for ( int j = 0; j < COLUMN; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }printf("\n");

    printf("Numbers collected : ");
    for (int i = 0; i < inventoryIndex; i++)
    {
        printf("%d " , inventory[i]);
    }
    printf("\n\n");
}

void maze_generator()
{

    printf("\n\nWelcome young prince, you must collect all the 9 numbers to free the princess!\n");
    for ( int i = 0; i < ROW; i++)
    {
        for ( int j = 0; j < COLUMN; j++)
        {
            maze[i][j] = EMPTYSPACE;
        }
    }
    maze[Rpos][Cpos] = SNAKE;
    maze[Rapple][Capple] = APPLE;


}

void apple_generator()
{
    if (maze[Rapple][Capple] == SNAKE)
    {
        inventoryIndex++;
        APPLE++;
        srand(time(0));
        do {
            Rapple = rand() % ROW;
            Capple = rand() % COLUMN;
        } while (maze[Rapple][Capple] == SNAKE);

        maze[Rapple][Capple] = APPLE;
    }
}

int main()
{
        maze_generator();
        maze_inventory_print();
        while (APPLE < 58)

        {
            char keypressed;
            printf("Type in a key... \nControls : z to go up, q to go left, s to go right, w to go down\n");
            scanf(" %c", &keypressed);
            buttonz(keypressed);
            apple_generator();
            maze_inventory_print();
        }
        printf("Well done, thanks for playing!");
        return 0;
    }
