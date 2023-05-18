#include <iostream>

void strrev(char word[])
{
    int len = strlen(word);
    char temp = ' ';
    for (int i = 0 ; i < len/2 ; i++)
    {
        temp = word[i];
        word[i] = word[len - 1 - i];
        word[len - 1 - i] = temp;
        printf("%s\n", word);
    }
    printf("%s", word);
}


int main() {
    char word[50];
    printf("Please choose a word you wish to reverse : ");
    fgets(word, 50, stdin);
    word[strlen(word) - 1] = '\0';
    strrev(word);
    return 0;
}
