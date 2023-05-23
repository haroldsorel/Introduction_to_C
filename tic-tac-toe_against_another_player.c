#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctype.h>


void maze_printer(char maze[3][3])
{
    for (int i = 0;  i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("  %c", maze[i][j]);
        }
    }
    printf("\n\n");
}
int column()
{
    int column;
    printf("In which column would you like to place your symbole? 1, 2 or 3?\n");
    scanf(" %d", &column);
    return column;
}

int line()
{
    int line;
    printf("In which line would you like to place your symbol? 1, 2, 3?\n");
    scanf(" %d", &line);
    return line;
}

bool write(char maze[3][3], int line, int column , int turn)
{
    bool res = true;
    {
        if (maze[line - 1][column - 1] == '_')
        {
            if (turn % 2 == 0)
            {
                maze[line - 1 ][column - 1] = 'x';
            }
            else
            {
                maze[line - 1][column - 1] = 'o';
            }
        }
        else
        {
            printf("Space Already Occupied!");
            res = false;
        }

    }
    return res;
}


int main()
{

    // start creation of the maze
    char maze[3][3];
    for (int i = 0;  i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            maze[i][j] = '_';
        }
    }
    maze_printer(maze);
    // stop creation of the maze

    //who's turn is it? , always starts with 'x'
    int turn = 2;

    while (true)
    {
        if (write(maze, line(), column(), turn))
        {
            turn++;
        }
        maze_printer(maze);
    }
    printf("Game ended! Thanks for playing.\n");
    return 0;
}
