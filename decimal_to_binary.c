#include <iostream>


int numarray[31];
int binaryarray[31];
int number;

//exponential function to have all the bases for counting in binary
int power(int base, int exponent) {
    int result = 1;
    int i;

    if (exponent >= 0)
    {
        for (i = 0; i < exponent; i++) {
            result *= base;
        }
    }
    return result;
}

//array that holds all the bases of binary counting
void arrayInitializer()
{
    for (int i = 0; i < 31; i++)
    {
        numarray[i] = power(2, i);
    }
}

void arrayPrinter()
{
    printf("the answer is : ");
    for (int i = 30; i >= 0; i--)
    {
        printf("%d", binaryarray[i]);
    }
    printf("\n");
}

void userinput()
{
    printf("Please choose a number you wish to convert into binary (under 255) : \n");
    scanf("%d", &number);
}

void toBinary()
{
    int i = 30;
    while (i >= 0)
    {
        if ( number - numarray[i] >= 0)
        {
            binaryarray[i] = 1;
            number -= numarray[i];
        }
        else
        {
            binaryarray[i] = 0;
        }
        i--;
    }
}

int main()
{
    arrayInitializer();
    userinput();
    toBinary();
    arrayPrinter();
    return 0;
}
