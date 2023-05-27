#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>



int isPalindrome(int x)
{
    int i = 0;
    int temp = x;
    char lsCharx1[30];
    char lsCharx2[30];

    while (x != 0) //creates a string of the integer but read backwards
    {
        lsCharx1[i] = (x % 10) + 48;
        x /= 10;
        i++;
    }
    lsCharx1[i] = '\0'; //creates a string so we can use methods


    while (temp != 0) //creates a string of the integer
    {
        lsCharx2[i - 1] = (temp % 10) + 48;
        temp /= 10;
        i--;
    }
    lsCharx2[strlen(lsCharx1)] = '\0';//creates a string so we can use methods


    return strcmp(lsCharx2, lsCharx1);

}
int main()
{
    int test;
    scanf("%d", &test);
    int result = isPalindrome(test);
    printf("if the number is 0 it is a palindrome : %d", result);
    return 0;
}
