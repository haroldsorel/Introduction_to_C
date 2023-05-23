#include <iostream>
#include <ctime>
#include <cstdlib>

int number_generator(int boundary)
{
    srand(time(NULL));
    int random_number = rand() % boundary + 1;
    return random_number;
}

void compare(int guess, int target)
{
    if (guess < target)
    {
        printf("The number is higher than %d\n", guess);
    }
    else if (guess > target)
    {
        printf("The number is lower than %d\n", guess);
    }
}

int user_input(int boundary)
{
    int guess;
    printf("Choose a number between 1 and %d :\n", boundary);
    scanf(" %d", &guess);
    return guess;
}

int difficulty()
{
    int dif;
    int res = 10;
    printf("Choose a difficulty between 1 and 5 : \n");
    scanf(" %d", &dif);
    if (dif == 2){res = 20;}
    else if (dif == 3){ res = 50;}
    else if (dif == 4){ res = 100;}
    else if (dif == 5){ res = 1000;}
    return res;
}

int main()
{
    const int BOUNDARY = difficulty();
    const int TARGET = number_generator(BOUNDARY);
    int guess = 0;
    while (guess != TARGET)
    {
        guess = user_input(BOUNDARY);
        compare(guess, TARGET);
    }
    printf("Well done! the number is indeed %d", TARGET);
    return 0;
}
