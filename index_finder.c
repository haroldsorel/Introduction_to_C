#include <stdio.h>
#include <string.h>
#include <ncurses.h>

bool needleInside(char *haystack, char *needle, int index)
{
    int size = strlen(needle);
    bool res = true;
    int flag = 0;
    for (int i = 0; i < size ; i++)
    {
        if(haystack[i + index] != needle[i])
        {
            res = false;
            flag = 1;
        }
    }
    return res;
}

int strStr(char *haystack, char *needle)
{

    int res = -1;
    int needleSize = strlen(needle);
    int haystackSize = strlen(haystack);

    if (needleSize > haystackSize)
    {
        return -1;
    }

    for (int i = 0; i < haystackSize; i++)
    {
        if (haystack[i] == needle[0] && needleInside(haystack, needle, i))
        {
            res = i;
            break;
        }
    }
    return res;
}

int main(void)
{
    char haystack[] = "mississipi";
    char needle[] = "issipi";

    printf("%d", strStr(haystack, needle));
}
