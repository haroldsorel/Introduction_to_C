#include <iostream>
#include <ctime>
#include <cstdlib>

int random_number_generator(int bound1, int bound2)
{
    srand(time(NULL));
    int number = (rand() % bound2) + bound1;
    return number;
}

int getinput(int bound1, int bound2)
{
    int guess;
    printf("Please choose a number between %d", bound1);
    printf(" and %d\n", bound2);
    scanf("%d", &guess);
    return guess;
}

int difficulty()
{
    int choice;
    printf("Please choose a difficulty ranging from 1 to 5\n");
    scanf("%d", &choice);
    int res = 10;
    if (choice == 2){res = 20;}
    if (choice == 3){res = 30;}
    if (choice == 4){res = 40;}
    if (choice == 5){res = 50;}
    return res;
}

void looper(int guess, int random_number)
{
    while (guess != random_number)
    {
        printf("Wrong!\n");
        guess = getinput(1, 10);
    }
}

int main()
{
    int boundary = difficulty();
    int random_number = random_number_generator(1, boundary);
    int guess = getinput(1, boundary);
    looper(guess, random_number);
    printf("Well done, the number was indeed %d!\n", random_number);
}
