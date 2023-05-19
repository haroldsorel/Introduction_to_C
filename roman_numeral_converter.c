#include <iostream>

int romanToInt(char* romanNumeral) {
    int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* symbols[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    int result = 0;
    int i = 0;

    while (*romanNumeral) {
        if (strncmp(romanNumeral, symbols[i], strlen(symbols[i])) == 0) {
            result += values[i];
            romanNumeral += strlen(symbols[i]);
        } else {
            i++;
        }
    }

    return result;
}

int main() {
    char romanNumeral[20];

    printf("Enter a Roman numeral: ");
    scanf("%s", romanNumeral);

    int integerValue = romanToInt(romanNumeral);

    printf("Integer value: %d\n", integerValue);

    return 0;
}
