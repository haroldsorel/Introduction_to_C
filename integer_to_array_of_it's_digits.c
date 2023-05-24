#include <iostream>

int x;
int lx[9];

void intToArray()
{
    int i = 0;
    while (x != 0)
    {
        int digit = x % 10;
        lx[sizeof(lx)/sizeof(lx[0]) - 1 - i] = digit;
        x /= 10;
        i++;
    }
}

void printArray()
{
    for (int i = 0; i < sizeof(lx)/sizeof(lx[0]); i++)
    {
        printf("%d\n", lx[i]);
    }
}

void user_input()
{
    printf("Choose an integer you wish to seperate into each individual digits : \n");
    scanf("%d", &x);
}

int main()
{
    user_input();
    intToArray();
    printArray();
    return 0;
}
