#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>



const int ROWS = 20;
const int COLUMNS = 41;
int rowPOS = ROWS/2 - 1;
int colPOS = COLUMNS/2 - 1;
int foodrowPOS;
int foodcolPOS;


void mazeprint() //creates the boundaries of the game, puts the cursor in the middle, and creates the snake
{
    attron(COLOR_PAIR(1));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0 || i == ROWS - 1)
            {
                mvaddch(i, j, '#');
            }
            else
            {
                if (j == 0 || j == COLUMNS - 1)
                {
                    mvaddch(i, j, '#');
                }
            }
        }
    }
    attroff(COLOR_PAIR(1));
    move(rowPOS, colPOS);
    addch('*');
}

void behavior(int move) //defines the behavior of the snake when arrow keys are pressed
{
    move(rowPOS, colPOS);
    if (move == KEY_UP && rowPOS - 1 != 0)
    {
        addch(' ');
        rowPOS--;
        move(rowPOS, colPOS);
        addch('*');
    }
    if (move == KEY_DOWN && rowPOS + 1 != 19)
    {
        addch(' ');
        rowPOS++;
        move(rowPOS, colPOS);
        addch('*');
    }
    if (move == KEY_RIGHT && colPOS + 1 != 40)
    {
        printw(" ");
        colPOS+=2;
        move(rowPOS, colPOS);
        addch('*');
    }
    if (move == KEY_LEFT && colPOS - 1 != 0)
    {
        addch(' ');
        colPOS-=2;
        move(rowPOS, colPOS);
        addch('*');
    }
}

void food_generator() //generates food for the snake and updates food position
{
        foodrowPOS = (rand() % (ROWS - 2)) + 1;
        do{
            foodcolPOS = (rand() % (COLUMNS - 2)) + 1;
        }while (foodcolPOS % 2 == 0) ;
        move(foodrowPOS, foodcolPOS);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        addch('$');
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
}

void checks_dinner() //checks if the snake just ate food and calls food_generator() ton generate a new one
{
    if (rowPOS == foodrowPOS && colPOS == foodcolPOS)
    {
        food_generator();
    }
}


void initialize()
{
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    raw();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    food_generator();
    mazeprint();
    curs_set(0);
}


int main()
{
    initialize();
    while (true)
    {
        int user_input = getch();
        behavior(user_input);
        checks_dinner();
        refresh();

    }
}
