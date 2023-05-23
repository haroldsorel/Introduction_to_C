#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctype.h>

const char PLAYER1 = 'x';
const char PLAYER2 = 'o';
char maze[3][3];
char turn = 2;
int freespace = 9;
char winner = ' ';


void maze_printer()
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

void playerMove()
{
    int x;
    int y;

    char player;
    if (turn % 2 == 0) {player = PLAYER1;} else {player = PLAYER2;}

    printf("Enter row (1 -> 3) :\n");
    scanf(" %d", &x);
    x--;
    printf("Enter column (1 -> 3) :\n");
    scanf(" %d", &y);
    y--;

    if (maze[x][y] == '_')
    {
        maze[x][y] = player;
        turn++;
        freespace--;
    }
    else
    {
        printf("Invalid action!\n");
    }
}

void checkWinner()
{
    for (int i = 0; i < 3; i++) {
        //lines
        if ((maze[i][0] == PLAYER1 && maze[i][1] == PLAYER1 && maze[i][2] == PLAYER1) ||
            (maze[0][i] == PLAYER1 && maze[1][i] == PLAYER1 && maze[2][i] == PLAYER1))
        {
            winner = PLAYER1;
        }
        //colums
        else if ((maze[i][0] == PLAYER2 && maze[i][1] == PLAYER2 && maze[i][2] == PLAYER2) ||
                 (maze[0][i] == PLAYER2 && maze[1][i] == PLAYER2 && maze[2][i] == PLAYER2))
        {
            winner = PLAYER2;
        }
    }
    //diagonals
    if ((maze[0][0] == PLAYER1 && maze[0][0] == maze[1][1] && maze[0][0] == maze[2][2]) ||
        (maze[0][2] == PLAYER1 && maze[0][2] == maze[1][1] && maze[0][2] == maze[2][0]))
    {
        winner = PLAYER1;
    }
    else if ((maze[0][0] == PLAYER2 && maze[0][0] == maze[1][1] && maze[0][0] == maze[2][2]) ||
             (maze[0][2] == PLAYER2 && maze[0][2] == maze[1][1] && maze[0][2] == maze[2][0]))

    {
        winner = PLAYER2;
    }

}

void aftermath()
{
    if (winner == PLAYER1)
    {
        printf("Player 1 won!\n");
    }
    else if (winner == PLAYER2)
    {
        printf("Player 2 won!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    printf("Thank you for playing!\n");
}


int main()
{
    for (int i = 0; i < 3; i++){for (int j = 0; j < 3; j++){maze[i][j] = '_';}}
    maze_printer();
    while (winner == ' ' && freespace != 0)
    {
        playerMove();
        maze_printer();
        checkWinner();
    }
    aftermath();
    return 0;
}
