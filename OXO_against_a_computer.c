#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctype.h>

const char PLAYER = 'x';
const char COMPUTER = 'o';
char maze[3][3];
int emptySpace = 9;
char winner = ' ';

void playerTurn()
{
    int x;
    int y;
    printf("Choose the Row you wish to put your symbol down (1 -> 3) : \n");
    scanf("%d", &x);
    printf("Choose the column you wish to put your symbol down (1 -> 3) : \n");
    scanf(" %d", &y);
    x--; y--; //decrements to use the input for the computer
    if (maze[x][y] == '_') //checks if case is occupied
    {
        maze[x][y] = PLAYER; //modifies the maze to accomodate the symbole
        emptySpace--; 
    }
    else
    {
        printf("Invalid action : case already occupied\n");
        playerTurn();} //if case occupied, restart the process until
}

void computerTurn()
{
    int x;
    int y;
    srand(time(0)); //generates a random seed
    if (emptySpace != 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }while (maze[x][y] != '_');

        maze[x][y] = COMPUTER;
        emptySpace--;
    }
}



void printMaze()
{
    for (int i = 0; i < 3; i++){for (int j = 0; j < 3; j++){printf("  %c", maze[i][j]);}printf("\n");}
    printf("\n");
}

void checkWinner()
{
    for (int i = 0; i < 3; i++) {
        if ((maze[i][0] == PLAYER && maze[i][1] == PLAYER && maze[i][2] == PLAYER) ||
            (maze[0][i] == PLAYER && maze[1][i] == PLAYER && maze[2][i] == PLAYER))
        {
            winner = PLAYER;
        }
        else if ((maze[i][0] == COMPUTER && maze[i][1] == COMPUTER  && maze[i][2] == COMPUTER ) ||
                 (maze[0][i] == COMPUTER  && maze[1][i] == COMPUTER  && maze[2][i] == COMPUTER ))
        {
            winner = COMPUTER;
        }
        if ((maze[0][0] == PLAYER && maze[0][0] == maze[1][1] && maze[0][0] == maze[2][2]) ||
            (maze[0][2] == PLAYER && maze[0][2] == maze[1][1] && maze[0][2] == maze[2][0]))
        {
            winner = PLAYER;
        }
        else if ((maze[0][0] == COMPUTER && maze[0][0] == maze[1][1] && maze[0][0] == maze[2][2]) ||
                 (maze[0][2] == COMPUTER && maze[0][2] == maze[1][1] && maze[0][2] == maze[2][0]))

        {
            winner = COMPUTER;
        }
    }
}

void winnerOrTie()
{
    if (winner == PLAYER)
    {
        printf("We have a winner! : Player\n");
    }
    else if (winner == COMPUTER)
    {
        printf("We have a winner! : COMPUTER\n");
    }

    else
    {
        printf("It's a tie!\n");

    }
}

int main()
{
    //initializing maze
    for (int i = 0; i < 3; i++) {for (int j = 0; j < 3; j++){maze[i][j] = '_';}}

    printMaze();
    while (emptySpace != 0 && winner == ' ')
    {
        playerTurn();
        computerTurn();
        printMaze();
        checkWinner();
    }
    winnerOrTie();
    printf("Thank you for playing!");
    return 0;
}
