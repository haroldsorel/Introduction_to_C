#include <iostream>


int main(){

    int temp;

    int numbers[] = {1, 4, 8, 14, 999, -1, 0, 42, 69};
    for (int i = 0; i <= 8; i++)
    {
        for (int j = i + 1; j <= 8; j++)
        {
            if (numbers[j] < numbers[i])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] =  temp;
            }
        }
    }
    for (int i = 0; i <= 8; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return 0;

}
