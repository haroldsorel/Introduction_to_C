#include <iostream>

int binaryArray[31];
char binary[31];
int decimal = 0;


int exponential(int base, int power)
{
    int res = 1;
    if (power != 0)
    {
        for (int i = 1; i <= power; i++)
        {
            res *= base;
        }
    }
    return res;
}

void arrayInitializer()
{
    for (int i = 0; i < 31; i++)
    {
        binaryArray[i] = exponential(2, i);
    }
}

void userInput()
{
    printf("Enter the binary number you wish to convert to decimal\n");
    fgets(binary, 31, stdin);
    binary[strlen(binary) - 1] = '\0';
}

void strReverser()
{
    int len = strlen(binary);
    char temp = ' ';
    for (int i = 0 ; i < len/2 ; i++)
    {
        temp = binary[i];
        binary[i] = binary[len - 1 - i];
        binary[len - 1 - i] = temp;
    }
}

void calculate()
{
    for (int i = 0; i < strlen(binary); i++ )
    {
        if (binary[i] == '1')
        {
            decimal+= binaryArray[i];
        }
    }
}


int main()
{
    arrayInitializer();
    userInput();
    strReverser();
    printf("%s\n", binary);
    calculate();
    printf("The decimal number is %d\n", decimal);
    return 0;
}
