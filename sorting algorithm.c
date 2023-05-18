#include <iostream>

void printArray(int numbers[], int size)
{
    for ( int i = 0; i < size; i++ )
    {
        printf("%d ", numbers[i]);
    }
}

void sort(int numbers[], int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[i])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] =  temp;
            }
        }
    }
}

int main(){

    int numbers[] = {1, 4, 8, 14, 999, -1, 0, 42, 69};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    sort(numbers, size);
    printArray(numbers, size);

    return 0;

}
